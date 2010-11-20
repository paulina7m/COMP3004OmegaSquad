#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QtXml/QDomDocument>

#include <QDebug>
#include <QStringList>

/*
The following must be added to the .pro file
QT += sql
QT += xml
*/

bool DatabaseHandler::openDB(QString dbType, QString pathToDb, QString hostName) {
    db = QSqlDatabase::addDatabase(dbType);
    //path/to/database/databasename
    db.setDatabaseName(pathToDb);
    db.setHostName(hostName);
    //DEBUG
    //qDebug() << "Database name: " << db.databaseName();
    //qDebug() << "Host name: " << db.hostName();
    if (db.open()) {
        /*
        //DEBUG
        qDebug() << "Connected to database";
        Find the maxId for getIdNumbers method
        */
        //Query the IdNumbers table for the biggest int
        //assign it to maxId
        QSqlQuery query("SELECT MAX(id) FROM idNumbers");
        if (query.next()) {
            maxId = query.value(0).toInt();
        }
        //qDebug() << maxId;
        return true;
    }
    else {
        //qDebug() << "Cannot open database";
        return false;
    }
    return false;
}


//All xml strings are passed through here and filtered
QString DatabaseHandler::queryDatabase(QString xmlString) {
    xmlReply = "";

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlString)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            if(!n.isNull()) {
                QDomElement e = n.toElement();
                if (e.tagName() == "command" && e.text() == "findEntities") {
                    //qDebug() << "finding";
                    xmlReply = this->findEntities(xmlString);
                    return xmlReply;
                }
                else if (e.tagName() == "command" && e.text() == "saveEntities") {
                    //qDebug() << "saving";
                    xmlReply = this->saveEntities(xmlString);
                    return xmlReply;
                }
                else if (e.tagName() == "command" && e.text() == "getIdNumbers") {
                    //qDebug() << "get ids";
                    xmlReply = this->getIdNumbers(xmlString);
                    return xmlReply;
                }
                else if (e.tagName() == "command" && e.text() == "login") {
                    //qDebug() << "login";
                    xmlReply = this->checkLogin(xmlString);
                    return xmlReply;
                }
                n = n.nextSibling();
            }
        }
        else {
            xmlReply = "<?xml version=\"1.0\"?><message><command>ParseXml</command><status>BadRequest</status></message>";
            return xmlReply;
        }
    }
    xmlReply = "<?xml version=\"1.0\"?><message><command>ParseXml</command><status>BadRequest</status></message>";
    return xmlReply;
}

//Find entities, return xml
QString DatabaseHandler::findEntities(QString xmlString) {
    xmlReply = "";
    queryString = "";
    entityType = "";

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        doc.setContent(xmlString);
        int andCounter = 0;
        //Prepare the query and get data
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        while(!n.isNull()) {
            QDomElement e = n.toElement();
            if (e.tagName() == "findEntitiesRequest") {
                queryString = "SELECT * FROM ";
                entityType = e.attribute("type");
                queryString.append(entityType);
                QDomNode m = e.firstChild();
                if (!m.isNull()) {
                    queryString.append(" WHERE ");
                    while (!m.isNull()) {
                        if (andCounter >= 1) {
                            queryString.append(" AND ");
                        }
                        ++andCounter;
                        QDomElement f = m.toElement();
                        //Form the query
                        queryString.append(f.attribute("key"));
                        queryString.append(f.attribute("comparison"));
                        queryString.append("\"");
                        escapeString = f.attribute("value");
                        //escape strings
                        if (escapeString.contains("<")) {
                            escapeString.replace("<", "&lt;");
                        }
                        queryString.append(escapeString);
                        queryString.append("\"");

                        m = m.nextSibling();
                    }
                }
            }
            n = n.nextSibling();
        }
        //Execute the query
        //qDebug() << queryString;
        QSqlQuery query(queryString);
        QSqlRecord rec;
        int numOfCols = 0;
        //returns the number of columns in the query
        xmlReply.append("<?xml version=\"1.0\"?><message><command>findEntities</command>");
        xmlReply.append("<status>OK</status>");
        while (query.next()) {
            int columnCount = 1;
            rec = query.record();
            numOfCols = rec.count();
            //qDebug() << numOfCols;
            xmlReply.append("<entity type=\"");
            xmlReply.append(entityType);
            xmlReply.append("\" id=\"");
            xmlReply.append(query.value(0).toString());
            xmlReply.append("\">");
            while (columnCount <= (numOfCols-1)) {
                xmlReply.append("<attribute key=\"");
                xmlReply.append(rec.fieldName(columnCount));
                xmlReply.append("\" value=\"");
                xmlReply.append(query.value(columnCount).toString());
                xmlReply.append("\" />");
                columnCount++;
            }
            xmlReply.append("</entity>");
        }
        xmlReply.append("</message>");
        //qDebug() << xmlReply;
        return xmlReply;
    }
    else {
        xmlReply = "<?xml version=\"1.0\"?><message><command>findEntities</command><status>BadRequest</status></message>";
        return xmlReply;
    }
    xmlReply = "<?xml version=\"1.0\"?><message><command>findEntities</command><status>PermissionDenied</status></message>";
    return xmlReply;
}

//Save Entities (create entities)
//Update Entites:
//CaseReport (Update the quantity),
//Shipment (Update the created, shipped, received or cancelled date)
//It is the responsability of the client to send a request to save the Shipments corresponding shipmentState
//and Inventory when shipment status changes
//Inventory (Update the quantity),
//NOTE: The client must request id numbers first, get a reply, then attach the id numbers to an object
//      when doing insertions
//Send Status message back to Server Message class
QString DatabaseHandler::saveEntities(QString xmlString) {
    xmlReply = "";
    //parse xml
    //qDebug() << xmlString;
    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        doc.setContent(xmlString);
        QString queryString;
        //Get the root element
        QDomElement root = doc.documentElement();
        //qDebug() << root.tagName();
        QDomNode n = root.firstChild();
        while(!n.isNull()) {
            //qDebug() << "looping";
            queryString = "";
            QDomElement e = n.toElement();
            //qDebug() << e.tagName();
            if (e.tagName() == "entity") {
                QDomNode m = e.firstChild();
                //check the database and see if this entity already exists
                QString queryCheck = "SELECT * FROM ";
                queryCheck.append(e.attribute("type"));
                queryCheck.append(" WHERE id=");
                queryCheck.append(e.attribute("id"));
                QSqlQuery query(queryCheck);
                //qDebug() << queryCheck;
                //if it exists, this command is meant to be an update
                if (query.next()) {
                    //update
                    //eg. update shipment set shippedDate = '2010-11-11' where id=6227;
                    //qDebug() << "This entity already exists";
                    queryString = "UPDATE ";
                    queryString.append(e.attribute("type"));
                    queryString.append(" SET ");
                    while (!m.isNull()) {
                        QDomElement f = m.toElement();
                        //Form the query
                        queryString.append(f.attribute("key"));
                        queryString.append("=");
                        queryString.append("\"");
                        queryString.append(f.attribute("value"));
                        queryString.append("\"");

                        m = m.nextSibling();
                        if (!m.isNull()) {
                            queryString.append(", ");
                        }
                    }
                    queryString.append(" WHERE id=");
                    queryString.append(e.attribute("id"));
                }
                else {
                    //insert
                    //eg. insert into SupplyType values (6220, "Panadol", 9, 1);
                    //Prepare the query and get data
                    queryString = "INSERT INTO ";
                    queryString.append(e.attribute("type"));
                    queryString.append(" VALUES (");
                    queryString.append(e.attribute("id"));
                    while (!m.isNull()) {
                        queryString.append(", ");
                        QDomElement f = m.toElement();
                        //Form the query
                        queryString.append("\"");
                        queryString.append(f.attribute("value"));
                        queryString.append("\"");

                        m = m.nextSibling();
                    }
                    queryString.append(")");
                }
            }
            //qDebug() << queryString;
            //Execute the insert
            QSqlQuery query(queryString);
            n = n.nextSibling();
        }
        xmlReply = "<?xml version=\"1.0\"?><message><command>saveEntities</command><status>OK</status></message>";
        return xmlReply;
    }
    //if empty xml string
    else {
        xmlReply = "<?xml version=\"1.0\"?><message><command>saveEntities</command><status>BadRequest</status></message>";
        return xmlReply;
    }
    xmlReply = "<?xml version=\"1.0\"?><message><command>saveEntities</command><status>PermissionDenied</status></message>";
    return xmlReply;
}

//Get login information
//Send status message back to Server Message class
QString DatabaseHandler::checkLogin(QString xmlString) {
    xmlReply = "";
    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        doc.setContent(xmlString);
        int andCounter = 0;
        //Prepare the query and get data
        QString queryString = "SELECT * FROM User";
        //Get the root element
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        while(!n.isNull()) {
            QDomElement e = n.toElement();
            if (e.tagName() == "loginRequest") {
                QDomNode m = e.firstChild();
                if (!m.isNull()) {
                    queryString.append(" WHERE ");

                    while (!m.isNull()) {
                        if (andCounter >= 1) {
                            queryString.append(" AND ");
                        }
                        ++andCounter;
                        QDomElement f = m.toElement();
                        //Form the query
                        queryString.append(f.tagName());
                        queryString.append("=\"");
                        queryString.append(f.text());
                        queryString.append("\"");

                        m = m.nextSibling();
                    }
                }
            }
            n = n.nextSibling();
        }

        //Execute the query
        QSqlQuery query(queryString);
        //qDebug() << queryString;
        if (query.next()) {
            QString role;
            switch(query.value(5).toInt()) {
                case 0:
                    role = "MedicalClerk";
                    break;
                case 1:
                    role = "MedicalAdministrator";
                    break;
                case 2:
                    role = "SystemAdministrator";
                    break;
            }
            xmlReply = "<?xml version=\"1.0\"?><message><command>login</command><status>OK</status><loginReply><role>";
            xmlReply.append(role);
            xmlReply.append("</role></loginReply></message>");
            return xmlReply;
        }

    }
    else {
        xmlReply = "<?xml version=\"1.0\"?><message><command>login</command>";
        xmlReply.append("<status>BadRequest</status><loginReply><role></role></loginReply></message>");
        return xmlReply;
    }
    xmlReply = "<?xml version=\"1.0\"?><message><command>login</command>";
    xmlReply.append("<status>PermissionDenied</status><loginReply><role></role></loginReply></message>");
    return xmlReply;
}

//Get ID Numbers (for when creating entities)
QString DatabaseHandler::getIdNumbers(QString xmlString){
    xmlReply = "";
    blockSize = "";

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //Prepare the query and get data
        //QString queryString = "SELECT MAX(id) FROM IdNumbers";
        //Get the root element
        doc.setContent(xmlString);
        QDomElement root = doc.documentElement();
        QDomNode n = root.firstChild();
        while(!n.isNull()) {
            QDomElement e = n.toElement();
            if (e.tagName() == "getIdNumbersRequest") {
                QDomNode m = e.firstChild();
                if (!m.isNull()) {
                    QDomElement f = m.toElement();
                    if (f.tagName() == "blockSize") {
                        blockSize = f.text();
                        qDebug() << blockSize;
                    }
                }
            }
            n = n.nextSibling();
        }

        //query the database for the max number
        //int maxId;
        //QSqlQuery query(queryString);
        //if (query.next()) {
            //maxId = query.value(0).toInt();
        //}
        int block = blockSize.toInt();
        int blockStart = maxId + 1;
        int blockEnd = blockStart + (block - 1);
        //qDebug() << blockStart;
        //qDebug() << blockEnd;
        QString num;
        QString insert = "INSERT INTO IdNumbers values(";
        insert.append(num.setNum(blockEnd));
        insert.append(")");
        //qDebug() << insert;
        QSqlQuery query(insert);

        xmlReply = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command><status>OK</status><getIdNumbersReply>";
        xmlReply.append("<blockStart>");
        xmlReply.append(num.setNum(blockStart));
        xmlReply.append("</blockStart><blockEnd>");
        xmlReply.append(num.setNum(blockEnd));
        xmlReply.append("</blockEnd></getIdNumbersReply></message>");
        return xmlReply;
    }
    else {
        xmlReply = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command>";
        xmlReply.append("<status>BadRequest</status><getIdNumbersReply><blockStart></blockStart></getIdNumbersReply></message>");
        return xmlReply;
    }

    xmlReply = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command>";
    xmlReply.append("<status>PermissionDenied</status><getIdNumbersReply><blockStart></blockStart></getIdNumbersReply></message>");
    return xmlReply;
}

void DatabaseHandler::closeDB() {
    db.close();
}
