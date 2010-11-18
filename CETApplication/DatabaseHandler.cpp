#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QVariant>
#include <QtXml/QDomDocument>

#include <QDebug>

/*
The following must be added to the .pro file
QT += sql
QT += xml
*/

bool DatabaseHandler::openDB(QString pathToDb) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    //path/to/database/databasename
    db.setDatabaseName(pathToDb);
    db.setHostName("localhost");
    //DEBUG
    qDebug() << "Database name: " << db.databaseName();
    if (db.open()) {
        //DEBUG
        qDebug() << "Connected to database";
        //Find the maxId for getIdNumbers method
        //Query the IdNumbers table for the biggest int
        //assign it to maxId
        QSqlQuery query("SELECT MAX(id) FROM idNumbers", db);
        if (query.next()) {
            maxId = query.value(0).toInt();
        }
        return true;
    }
    else {
        qDebug() << "Cannot open database";
        return false;
    }
    return false;
}

//Runs and returns any query (for testing)
QSqlQuery DatabaseHandler::queryResultsFrom(QString sqlQuery) {
    QSqlQuery query(sqlQuery, db);
    qDebug() << "running query";
    while (query.next()) {
        qDebug() << "In Loop";
        QString result = query.value(0).toString();
        qDebug() << result;
    }
    qDebug() << "after loop";
    return query;
}

//Find Entities, store them in a list
//Send list of entities to Server Message class
//Send list of Diseases
QList<DiseaseType> DatabaseHandler::findDiseaseType() {
    diseaseList.clear();
    QSqlQuery query("SELECT * FROM DiseaseType");
    while (query.next()) {
        DiseaseType addDisease(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toBool());
        diseaseList.append(addDisease);
    }
    return diseaseList;
}

//Send list of Supplies
QList<SupplyType> DatabaseHandler::findSupplyType() {
    supplyList.clear();
    QSqlQuery query("SELECT * FROM SupplyType");
    while (query.next()) {
        SupplyType addSupply(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toBool());
        supplyList.append(addSupply);
    }

    return supplyList;
}

QList<Inventory> DatabaseHandler::findInventory(QString xmlString) {
    inventoryList.clear();

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
            int andCounter = 0;
            //Prepare the query and get data
            QString queryString = "SELECT * FROM Inventory";
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            while(!n.isNull()) {
                QDomElement e = n.toElement();
                if (e.tagName() == "findEntitiesRequest") {
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
                                queryString.append(f.attribute("value"));

                                m = m.nextSibling();
                        }
                    }
                }
                n = n.nextSibling();
            }
            //qDebug() << queryString;
            //Execute the query
            //qDebug() << queryString;
            QSqlQuery query(queryString);
            //Create a list of CaseReport objects
            while (query.next()) {
                Inventory addInventoryList(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt());
                inventoryList.append(addInventoryList);
            }
        }
    }
    else {
        //Empty string
    }

    return inventoryList;
}

QList<Region> DatabaseHandler::findRegion() {
    regionList.clear();
    QSqlQuery query("SELECT * FROM Region");
    while (query.next()) {
        Region addRegion(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toInt(), query.value(5).toString());
        regionList.append(addRegion);
    }

    return regionList;
}

QList<Province> DatabaseHandler::findProvince() {
    provinceList.clear();
    QSqlQuery query("SELECT * FROM Province");
    while (query.next()) {
        Province addProvince(query.value(0).toInt(), query.value(1).toString());
        provinceList.append(addProvince);
    }

    return provinceList;
}

QList<Shipment> DatabaseHandler::findShipment(QString xmlString) {
    shipmentList.clear();

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
            int andCounter = 0;
            //Prepare the query and get data
            QString queryString = "SELECT * FROM Shipment";
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            while(!n.isNull()) {
                QDomElement e = n.toElement();
                if (e.tagName() == "findEntitiesRequest") {
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
                            if (f.attribute("key") == "createdDate" || f.attribute("key") == "shippedDate" || f.attribute("key") == "receivedDate" || f.attribute("key") == "cancelledDate") {
                                //put double quotes around it since it's a string
                                queryString.append("\"");
                                queryString.append(f.attribute("value"));
                                queryString.append("\"");
                            }
                            else {
                                queryString.append(f.attribute("value"));
                            }

                            m = m.nextSibling();
                        }
                    }
                }
                n = n.nextSibling();
            }

            qDebug() << queryString;
            //Execute the query
            QSqlQuery query(queryString);
            //Create a list of Shipment objects
            while (query.next()) {
                Shipment addShipmentReport(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt(), Shipment::shipmentState(query.value(3).toInt()), query.value(4).toString(), query.value(8).toString());
                if (query.value(5).toString() != "" && query.value(6).toString() == "" && query.value(7).toString() == "") {
                    addShipmentReport.setShippedDate(query.value(5).toString());
                }
                else if(query.value(5).toString() != "" && query.value(6).toString() != "" && query.value(7).toString() == "") {
                    addShipmentReport.setShippedDate(query.value(5).toString());
                    addShipmentReport.setReceivedDate(query.value(6).toString());
                }
                else if(query.value(7).toString() != "") {
                    addShipmentReport.setShippedDate("");
                    addShipmentReport.setReceivedDate("");
                    addShipmentReport.setCancelledDate(query.value(7).toString());
                }
                shipmentList.append(addShipmentReport);
            }
        }
    }
    else {
        //Invalid XML
    }

    return shipmentList;
}

QList<ShipmentDetail> DatabaseHandler::findShipmentDetail(QString xmlString) {
    shipmentDetailList.clear();

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
            int andCounter = 0;
            //Prepare the query and get data
            QString queryString = "SELECT * FROM ShipmentDetail";
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            while(!n.isNull()) {
                QDomElement e = n.toElement();
                if (e.tagName() == "findEntitiesRequest") {
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
                            queryString.append(f.attribute("value"));
                            m = m.nextSibling();
                        }
                    }
                }
                n = n.nextSibling();
            }
            //qDebug() << queryString;
            //Execute the query
            QSqlQuery query(queryString);
            //Create a list of Shipment objects
            while (query.next()) {
                ShipmentDetail addShipmentDetail(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt(), query.value(4).toInt());
                shipmentDetailList.append(addShipmentDetail);
            }
        }
    }
    else {
        //Empty string
    }


    return shipmentDetailList;
}

QList<CaseReport> DatabaseHandler::findCaseReport(QString xmlString) {
    caseReportList.clear();

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
            int andCounter = 0;
            //Prepare the query and get data
            QString queryString = "SELECT * FROM CaseReport";
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            while(!n.isNull()) {
                QDomElement e = n.toElement();
                if (e.tagName() == "findEntitiesRequest") {
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
                            if (f.attribute("key") == "dateOfReport") {
                                //put double quotes around it since it's a string
                                queryString.append("\"");
                                queryString.append(f.attribute("value"));
                                queryString.append("\"");
                             }
                             else {
                                queryString.append(f.attribute("value"));
                             }
                            m = m.nextSibling();
                        }
                    }
                }
                n = n.nextSibling();
            }
            //qDebug() << queryString;
            //Execute the query
            QSqlQuery query(queryString);
            //Create a list of CaseReport objects
            while (query.next()) {
                CaseReport addCaseReport(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toInt());
                caseReportList.append(addCaseReport);
            }
        }
    }
    else {
        //Empty string
    }

    return caseReportList;
}

//Return a list of users
QList<User> DatabaseHandler::findUser() {
    userList.clear();

    QSqlQuery query("SELECT * FROM User");
    while (query.next()) {
        User addUser(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toBool(), User::role(query.value(5).toInt()));
        userList.append(addUser);
    }

    return userList;
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
    //parse xml
    //qDebug() << xmlString;
    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //Is this a valid xml document?
        if (doc.setContent(xmlString)) {
            QString queryString;
            //Get the root element
            QDomElement root = doc.documentElement();
            qDebug() << root.tagName();
            QDomNode n = root.firstChild();
            while(!n.isNull()) {
                queryString = "";
                QDomElement e = n.toElement();
                qDebug() << e.tagName();
                if (e.tagName() == "entity") {
                    QDomNode m = e.firstChild();
                    //check the database and see if this entity already exists
                    QString queryCheck = "SELECT * FROM ";
                    queryCheck.append(e.attribute("type"));
                    queryCheck.append(" WHERE id=");
                    queryCheck.append(e.attribute("id"));
                    QSqlQuery query(queryCheck);
                    qDebug() << queryCheck;
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
                            if (f.attribute("key") == "createdDate" || f.attribute("key") == "shippedDate"  || f.attribute("key") == "receivedDate"  || f.attribute("key") == "cancelledDate"  || f.attribute("key") == "notes" || f.attribute("key") == "dateOfReport") {
                                //put double quotes around it since it's a string
                                queryString.append("\"");
                                queryString.append(f.attribute("value"));
                                queryString.append("\"");
                                /*
                                if (f.attribute("key") == "receivedDate" && f.attribute("value") != "") {
                                    qDebug() << "Received a shipment!";
                                    //Update
                                    //Shipment (Update the created, shipped, received, cancelled date and corresponding shipmentState),
                                    //Inventory (if Shipments update their received date and state,
                                    //           update the Inventory quantity with the ShipmentDetails quantitiesShipped)
                                }
                                */
                            }
                            else {
                                queryString.append(f.attribute("value"));
                            }
                            m = m.nextSibling();
                            if (!m.isNull()) {
                                queryString.append(", ");
                            }
                        }
                        queryString.append(" WHERE id=");
                        queryString.append(e.attribute("id"));
                        qDebug() << queryString;
                        //Execute the update
                        QSqlQuery query(queryString);
                        return "OK";
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
                            if (f.attribute("key") == "createdDate" || f.attribute("key") == "shippedDate"  || f.attribute("key") == "receivedDate"  || f.attribute("key") == "cancelledDate"  || f.attribute("key") == "notes" || f.attribute("key") == "dateOfReport") {
                                //put double quotes around it since it's a string
                                queryString.append("\"");
                                queryString.append(f.attribute("value"));
                                queryString.append("\"");
                            }
                            else {
                                queryString.append(f.attribute("value"));
                            }

                            m = m.nextSibling();
                        }
                        queryString.append(")");
                    }
                }
                n = n.nextSibling();
                qDebug() << queryString;
                //Execute the insert
                QSqlQuery query(queryString);
            }
            return "OK";
        }
        else {
            return "BadRequest";
        }
    }
    //if empty xml string
    else {
        return "BadRequest";
    }
    return "PermissionDenied";
}

//Get login information
//Send status message back to Server Message class
QString DatabaseHandler::checkLogin(QString xmlString) {

    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
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
            qDebug() << queryString;
            if (query.next()) {
                return "OK";
            }
        }
        else {
            return "BadRequest";
        }
    }
    else {
        //bad string
        return "BadRequest";
    }
    return "PermissionDenied";
}

//Get ID Numbers (for when creating entities)
QList<int> DatabaseHandler::getIdNumbers(int blockSize){
    int blockStart = maxId + 1;
    int blockEnd = blockStart + (blockSize - 1);
    //iterate from blockStart to blockEnd and put in a list
    QList<int> idList;
    for (int i=blockStart; i <= blockEnd; i++) {
        idList.append(i);
    }

    //update the database table with the blockEnd number
    QString num;
    QString insert = "INSERT INTO IdNumbers values(";
    insert.append(num.setNum(blockEnd));
    insert.append(")");
    qDebug() << insert;
    QSqlQuery query;
    query.prepare(insert);
    query.exec();

    return idList;
}

void DatabaseHandler::closeDB() {
    db.close();
}
