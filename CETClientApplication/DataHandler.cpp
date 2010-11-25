#include "datahandler.h"
#include <QtXml/QDomDocument>
#include "clientconnection.h"

#include <QDebug>

DataHandler::DataHandler() {
    connection = new ClientConnection();
}
DataHandler::~DataHandler() {}

//getCaseReports
//all parameters should be optional/nullable (-1 indicates this)
//parameters are used to shape xml query
//from is >=
//to is <=
//QList<CaseReport> DataHandler::getCaseReports(int idFrom, int idTo, int regionID, QString dateFrom, QString dateTo, int diseaseType, int quantityFrom, int quantityTo)
QList<CaseReport> DataHandler::getCaseReports()
{
    //create a list to be returned
    QList<CaseReport> returnList;

    /*
    int nullInt = -1; //-1 means it's a 'NULL' int
    QString nullString = "";
    QString xmlRequest;

    //encode parameters to xml query
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"CaseReport\">");

    //Check for nulls, turn ints into strings and form query
    if (idFrom != nullInt) {
        QString idStart;
        idStart.setNum(idFrom);

        //Form query
        xmlRequest.append("<query key=\"id\" value=\"");
        xmlRequest.append(idStart);
        xmlRequest.append("\" comparison=\"&gt;=\" />");

        qDebug() << "idFrom: " << idStart;
    }

    if (idTo != nullInt) {
        QString idEnd;
        idEnd.setNum(idTo);

        //Form query
        xmlRequest.append("<query key=\"id\" value=\"");
        xmlRequest.append(idStart);
        xmlRequest.append("\" comparison=\"&gt;=\" />");


        qDebug() << "idTo: " <<  idEnd;
    }

    if (regionID != nullInt) {
        QString regionNum;
        regionNum.setNum(regionID);
        qDebug() << "regionID: " << regionNum;
    }

    if (dateFrom != nullString) {
        QString dateStart;
        dateStart = dateFrom;
        qDebug() << "dateFrom: " << dateStart;
    }

    if (dateTo != nullString) {
        QString dateEnd;
        dateEnd = dateTo;
        qDebug() << "dateTo: " << dateEnd;
    }

    if (diseaseType != nullInt) {
        QString diseaseNum;
        diseaseNum.setNum(diseaseType);
        qDebug() << "diseaseType: " << diseaseNum;
    }

    if (quantityFrom != nullInt) {
        QString quantityStart;
        quantityStart.setNum(quantityFrom);
        qDebug() << "quantityFrom: " << quantityStart;
    }

    if (quantityTo != nullInt) {
        QString quantityEnd;
        quantityEnd.setNum(quantityTo);
        qDebug() << "quantityTo: " << quantityEnd;
    }
    */

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"CaseReport\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //send xml query to  communication component




    //receive xml result from component
    //Dummy reply
    QString xmlReply = connection->sendRequest(xmlRequest);



    //dissect xml data and populate it into returnList
    int id;
    int regionId;
    QString date;
    int disease;
    bool correction;
    int quantity;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "regionId") {
                                        regionId = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "dateOfReport") {
                                        date = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "diseaseType") {
                                        disease = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "correction") {
                                        correction = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "quantity") {
                                        quantity = f.attribute("value").toInt();
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            CaseReport aCaseReport(id, regionId, date, disease, quantity);
                            aCaseReport.setCorrection(correction);
                            returnList.append(aCaseReport);
                            g = g.nextSibling();
                        }

                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}


//getDiseaseTypes
//no parameters passed in because it doesn't make sense
//of course it can be changed
QList<DiseaseType> DataHandler::getDiseaseTypes()
{
    QList<DiseaseType> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"DiseaseType\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);




    //dissect xml data and populate it into returnList
    int id;
    QString name;
    int colorIndex;
    bool enabled;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "name") {
                                        name = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "colorIndex") {
                                        colorIndex = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "enabled") {
                                        enabled = f.attribute("value").toInt();
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            DiseaseType aDiseaseType(id, name, colorIndex, enabled);
                            returnList.append(aDiseaseType);
                            g = g.nextSibling();
                        }

                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}

QList<Inventory> DataHandler::getInventory() {
    QList<Inventory> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"Inventory\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = "Response from server";


    //dissect xml data and populate it into returnList
    int id;
    int regionId;
    int supplyType;
    int quantity;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "regionId") {
                                        regionId = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "supplyType") {
                                        supplyType = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "quantity") {
                                        quantity = f.attribute("value").toInt();
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            Inventory anInventory(id, regionId, supplyType, quantity);
                            returnList.append(anInventory);
                            g = g.nextSibling();
                        }

                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}

//getRegions
//no parameters passed in because it doesn't make sense
//of course it can be changed
QList<Region> DataHandler::getRegions()
{
    QList<Region> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"Region\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);


    //dissect xml data and populate it into returnList
    int id;
    int provinceId;
    QString name;
    int centerX;
    int centerY;
    QString polygonPoints;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "provinceId") {
                                        provinceId = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "name") {
                                        name = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "centerX") {
                                        centerX = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "centerY") {
                                        centerY = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "polygonPoints") {
                                        polygonPoints = f.attribute("value");
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            Region aRegion(id, provinceId, name, centerX, centerY, polygonPoints);
                            returnList.append(aRegion);
                            g = g.nextSibling();
                        }

                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}



//getProvinces
//no parameters passed in because it doesn't make sense
//of course it can be changed
QList<Province> DataHandler::getProvinces()
{
    QList<Province> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"Province\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);


    //dissect xml data and populate it into returnList
    int id;
    QString name;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "name") {
                                        name = f.attribute("value");
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            Province aProvince(id, name);
                            returnList.append(aProvince);
                            g = g.nextSibling();
                        }

                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;

}

QList<Shipment> DataHandler::getShipments()
{
    QList<Shipment> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"Shipment\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);



    //dissect xml data and populate it into returnList
    int id;
    int srcRegion;
    int destRegion;
    int shipmentState;
    QString created;
    QString shipped;
    QString received;
    QString cancelled;
    QString notes;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "srcRegion") {
                                        srcRegion = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "destRegion") {
                                        destRegion = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "shipmentState") {
                                        if (f.attribute("value") == "Created") {
                                            shipmentState = 0;
                                        }
                                        else if (f.attribute("value") == "Shipped") {
                                            shipmentState = 1;
                                        }
                                        else if (f.attribute("value") == "Received") {
                                            shipmentState = 2;
                                        }
                                        else if (f.attribute("value") == "Cancelled") {
                                            shipmentState = 3;
                                        }
                                    }
                                    else if (f.attribute("key") == "createdDate") {
                                        created = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "shippedDate") {
                                        shipped = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "receivedDate") {
                                        received = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "cancelledDate") {
                                        cancelled = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "notes") {
                                        notes = f.attribute("value");
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            Shipment aShipment(id, srcRegion, destRegion, Shipment::shipmentState(shipmentState), created, notes);
                            aShipment.setShippedDate(shipped);
                            aShipment.setReceivedDate(received);
                            aShipment.setCancelledDate(cancelled);
                            returnList.append(aShipment);
                            g = g.nextSibling();
                        }
                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;

}

QList<ShipmentDetail> DataHandler::getShipmentDetails()
{
    QList<ShipmentDetail> returnList;

    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"ShipmentDetail\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);


    //dissect xml data and populate it into returnList
    int id;
    int shipmentId;
    int supplyType;
    int quantityRequested;
    int quantityShipped;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "shipmentId") {
                                        shipmentId = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "supplyType") {
                                        supplyType = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "quantityRequested") {
                                        quantityRequested = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "quantityShipped") {
                                        quantityShipped = f.attribute("value").toInt();
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            ShipmentDetail aShipmentDetail(id, shipmentId, supplyType, quantityRequested, quantityShipped);
                            returnList.append(aShipmentDetail);
                            g = g.nextSibling();
                        }
                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}


QList<SupplyType> DataHandler::getSupplyTypes()
{
    QList<SupplyType> returnList;
    QString xmlRequest;
    xmlRequest = "<?xml version=\"1.0\"?><message><command>findEntities</command>";
    xmlRequest.append("<findEntitiesRequest type=\"SupplyType\">");
    xmlRequest.append("</findEntitiesRequest></message>");

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //receive xml result from component
    QString xmlReply = connection->sendRequest(xmlRequest);


    //dissect xml data and populate it into returnList
    int id;
    QString name;
    int colorIndex;
    bool enabled;
    if (xmlReply != "") {
            //Parse the xml string
            //The name of the xml document
            QDomDocument doc("xmldocument");
            //if it's a valid XML and properly nested
            if (doc.setContent(xmlReply)) {
                //Get the root element
                QDomElement root = doc.documentElement();
                QDomNode n = root.firstChild();
                QDomElement m = n.toElement();
                if(m.tagName() == "command" && m.text() == "findEntities") {
                    QDomNode e = n.nextSibling();
                    QDomElement f = e.toElement();
                    if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    while(!g.isNull()) {
                        QDomElement i = g.toElement();
                        id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                            if (!j.isNull()) {
                                while (!j.isNull()) {
                                    QDomElement f = j.toElement();
                                    if (f.attribute("key") == "name") {
                                        name = f.attribute("value");
                                    }
                                    else if (f.attribute("key") == "colorIndex") {
                                        colorIndex = f.attribute("value").toInt();
                                    }
                                    else if (f.attribute("key") == "enabled") {
                                        enabled = f.attribute("value").toInt();
                                    }
                                    j = j.nextSibling();
                                }
                            }
                            SupplyType aSupplyType(id, name, colorIndex, enabled);
                            returnList.append(aSupplyType);
                            g = g.nextSibling();
                        }
                    }
                }
            }
            return returnList;
        }
        else {
            return returnList;
        }

    //return the list
    return returnList;
}

/*SAVING AND UPDATING*/
//Save CaseReports
QString DataHandler::saveCaseReport(int regionID, QString date, int disease, int quantity) {
    QString replyStatus;
    QString xmlStatus;

    //get an ID number first
    int id;

    //form the xml query to get id
    QString xmlIdRequest;
    xmlIdRequest = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command><getIdNumbersRequest>";
    xmlIdRequest.append("<blockSize>1</blockSize>");
    xmlIdRequest.append("</getIdNumbersRequest></message>");

    //SPENCE
    //send xml query to  communication component




    //SPENCE
    //Get a response back
    QString xmlReply = connection->sendRequest(xmlIdRequest);




    //Parse the xml
    if (xmlReply != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlReply)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "getIdNumbers") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    if(!g.isNull()) {
                        QDomElement i = g.toElement();
                        //id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                        if (!j.isNull()) {
                            while (!j.isNull()) {
                                QDomElement f = j.toElement();
                                id = f.text().toInt();
                                j = j.nextSibling();
                            }
                        }
                    }
                }
            }
        }
    }

    //Create the entity and attach id number
    QString anId;
    QString aRegion;
    QString aDisease;
    QString aQuantity;

    QString xmlSaveRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlSaveRequest.append("<entity type=\"CaseReport\" id=\"");
    xmlSaveRequest.append(anId.setNum(id));
    xmlSaveRequest.append("\">");
    xmlSaveRequest.append("<attribute key=\"regionId\" value=\"");
    xmlSaveRequest.append(aRegion.setNum(regionID));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"dateOfReport\" value=\"");
    xmlSaveRequest.append(date);
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"diseaseType\" value=\"");
    xmlSaveRequest.append(aDisease.setNum(disease));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"correction\" value=\"0\" />");
    xmlSaveRequest.append("<attribute key=\"quantity\" value=\"");
    xmlSaveRequest.append(aQuantity.setNum(quantity));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("</entity></message>");

    //send xml query to  communication component



    //get a status response string
    xmlStatus = "Response from server";

    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }

    return replyStatus;
}

//Update CaseReport
QString DataHandler::updateCaseReport(int id, int quantity) {
    QString replyStatus;
    QString xmlStatus;

    //Update the entity
    QString anId;
    QString aRegion;
    QString aDisease;
    QString aQuantity;

    QString xmlUpdateRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlUpdateRequest.append("<entity type=\"CaseReport\" id=\"");
    xmlUpdateRequest.append(anId.setNum(id));
    xmlUpdateRequest.append("\">");
    /*
    xmlUpdateRequest.append("<attribute key=\"regionId\" value=\"");
    xmlUpdateRequest.append(aRegion.setNum(regionID));
    xmlUpdateRequest.append("\" />");
    xmlUpdateRequest.append("<attribute key=\"dateOfReport\" value=\"");
    xmlUpdateRequest.append(date);
    xmlUpdateRequest.append("\" />");
    xmlUpdateRequest.append("<attribute key=\"diseaseType\" value=\"");
    xmlUpdateRequest.append(aDisease.setNum(disease));
    xmlUpdateRequest.append("\" />");
    */
    xmlUpdateRequest.append("<attribute key=\"correction\" value=\"0\" />");
    xmlUpdateRequest.append("<attribute key=\"quantity\" value=\"");
    xmlUpdateRequest.append(aQuantity.setNum(quantity));
    xmlUpdateRequest.append("\" />");
    xmlUpdateRequest.append("</entity></message>");

    //send xml query to  communication component


    //get a status response string
    xmlStatus = connection->sendRequest(xmlUpdateRequest);

    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }



    return replyStatus;
}

//Save Shipments
QString DataHandler::saveShipment(int srcRegion, int destRegion, QString createdDate, int supplyType, int quantityRequested, QString notes) {
    QString replyStatus;
    QString xmlStatus;

    //get two ID numbers first
    int id;

    //form the xml query to get 2 ids (one for shipment and one for shipmentdetail)
    QString xmlIdRequest;
    xmlIdRequest = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command><getIdNumbersRequest>";
    xmlIdRequest.append("<blockSize>2</blockSize>");
    xmlIdRequest.append("</getIdNumbersRequest></message>");

    //SPENCE
    //send xml query to  communication component





    //SPENCE
    QString xmlReply = connection->sendRequest(xmlIdRequest);





    //create a simple array to store the two id numbers
    int array [2];
    int counter = 0;
    //Parse the xml
    if (xmlReply != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlReply)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "getIdNumbers") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    if(!g.isNull()) {
                        QDomElement i = g.toElement();
                        //id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                        if (!j.isNull()) {
                            while (!j.isNull()) {
                                QDomElement f = j.toElement();
                                id = f.text().toInt();
                                array[counter] = id;
                                counter++;
                                j = j.nextSibling();
                            }
                        }
                    }
                }
            }
        }
    }

    //Create the entity and attach id number
    QString aShipmentId;
    QString aShipmentDetailId;
    QString aSource;
    QString aDest;
    QString aSupplyType;
    QString aQuantity;
    int shipId = array[0];
    int shipDetailId = array[1];

    QString xmlSaveRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlSaveRequest.append("<entity type=\"Shipment\" id=\"");
    xmlSaveRequest.append(aShipmentId.setNum(shipId));
    xmlSaveRequest.append("\">");
    xmlSaveRequest.append("<attribute key=\"srcRegion\" value=\"");
    xmlSaveRequest.append(aSource.setNum(srcRegion));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"destRegion\" value=\"");
    xmlSaveRequest.append(aDest.setNum(destRegion));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"shipmentState\" value=\"0\" />");
    xmlSaveRequest.append("<attribute key=\"createdDate\" value=\"");
    xmlSaveRequest.append(createdDate);
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"shippedDate\" value=\"null\" />");
    xmlSaveRequest.append("<attribute key=\"receivedDate\" value=\"null\" />");
    xmlSaveRequest.append("<attribute key=\"cancelledDate\" value=\"null\" />");
    xmlSaveRequest.append("<attribute key=\"notes\" value=\"");
    xmlSaveRequest.append(notes);
    xmlSaveRequest.append("\" /></entity>");

    xmlSaveRequest.append("<entity type=\"ShipmentDetail\" id=\"");
    xmlSaveRequest.append(aShipmentDetailId.setNum(shipDetailId));
    xmlSaveRequest.append("\">");
    xmlSaveRequest.append("<attribute key=\"shipmentId\" value=\"");
    xmlSaveRequest.append(aShipmentId);
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"supplyType\" value=\"");
    xmlSaveRequest.append(aSupplyType.setNum(supplyType));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"quantityRequested\" value=\"");
    xmlSaveRequest.append(aQuantity.setNum(quantityRequested));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"quantityShipped\" value=\"null\" />");
    xmlSaveRequest.append("</entity></message>");
    //qDebug() << xmlSaveRequest;

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //get a status response string
    xmlStatus = "Response from server";


    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }

    return replyStatus;
}

//Update Shipments
//quantityShipped created when actually shipped
//quantityShipped is 0 if shipped date empty string
QString DataHandler::updateShipment(int shipmentId, int shipmentDetailId, int quantityShipped, QString shippedDate, QString receivedDate, QString cancelledDate, QString notes) {
    QString replyStatus;
    QString xmlStatus;

    //Update the entity
    QString anId;
    QString quantity;

    QString xmlUpdateRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlUpdateRequest.append("<entity type=\"Shipment\" id=\"");
    xmlUpdateRequest.append(anId.setNum(shipmentId));
    xmlUpdateRequest.append("\">");
    if (shippedDate != "") {
        xmlUpdateRequest.append("<attribute key=\"shippedDate\" value=\"");
        xmlUpdateRequest.append(shippedDate);
        xmlUpdateRequest.append("\" />");
        xmlUpdateRequest.append("<attribute key=\"shipmentState\" value=\"");
        xmlUpdateRequest.append("Shipped");
        xmlUpdateRequest.append("\" />");
    }
    else if (receivedDate != "") {
        xmlUpdateRequest.append("<attribute key=\"receivedDate\" value=\"");
        xmlUpdateRequest.append(shippedDate);
        xmlUpdateRequest.append("\" />");
        xmlUpdateRequest.append("<attribute key=\"shipmentState\" value=\"");
        xmlUpdateRequest.append("Received");
        xmlUpdateRequest.append("\" />");
    }
    else if (cancelledDate != "") {
        xmlUpdateRequest.append("<attribute key=\"cancelledDate\" value=\"");
        xmlUpdateRequest.append(shippedDate);
        xmlUpdateRequest.append("\" />");
        xmlUpdateRequest.append("<attribute key=\"shipmentState\" value=\"");
        xmlUpdateRequest.append("Cancelled");
        xmlUpdateRequest.append("\" />");
    }
    if (notes != "") {
        xmlUpdateRequest.append("<attribute key=\"notes\" value=\"");
        xmlUpdateRequest.append(notes);
        xmlUpdateRequest.append("\" />");
    }
    xmlUpdateRequest.append("</entity>");
    if (shippedDate != "" && quantityShipped > 0) {
        xmlUpdateRequest.append("<entity type=\"ShipmentDetail\" id=\"");
        xmlUpdateRequest.append(anId.setNum(shipmentDetailId));
        xmlUpdateRequest.append("\">");
        xmlUpdateRequest.append("<attribute key=\"quantityShipped\" value=\"");
        xmlUpdateRequest.append(quantity.setNum(quantityShipped));
        xmlUpdateRequest.append("\" />");
        xmlUpdateRequest.append("</entity></message>");

    }
    else {
        xmlUpdateRequest.append("</message>");
    }

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //get a status response string
    xmlStatus = connection->sendRequest(xmlUpdateRequest);

    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }



    return replyStatus;
}

//Save Inventory
QString DataHandler::saveInventory(int regionID, int supplyType, int quantity) {
    QString replyStatus;
    QString xmlStatus;

    //get an ID number first
    int id;

    //form the xml query to get id
    QString xmlIdRequest;
    xmlIdRequest = "<?xml version=\"1.0\"?><message><command>getIdNumbers</command><getIdNumbersRequest>";
    xmlIdRequest.append("<blockSize>1</blockSize>");
    xmlIdRequest.append("</getIdNumbersRequest></message>");

    //SPENCE
    //send xml query to  communication component



    //SPENCE
    //Get a response back
    QString xmlReply = connection->sendRequest(xmlIdRequest);




    //Parse the xml
    if (xmlReply != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlReply)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "getIdNumbers") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status" && f.text() == "OK") {
                    QDomNode g = e.nextSibling();
                    if(!g.isNull()) {
                        QDomElement i = g.toElement();
                        //id = i.attribute("id").toInt();
                        QDomNode j = i.firstChild();
                        if (!j.isNull()) {
                            while (!j.isNull()) {
                                QDomElement f = j.toElement();
                                id = f.text().toInt();
                                j = j.nextSibling();
                            }
                        }
                    }
                }
            }
        }
    }

    //Create the entity and attach id number
    QString anId;
    QString aRegion;
    QString aSupply;
    QString aQuantity;

    QString xmlSaveRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlSaveRequest.append("<entity type=\"Inventory\" id=\"");
    xmlSaveRequest.append(anId.setNum(id));
    xmlSaveRequest.append("\">");
    xmlSaveRequest.append("<attribute key=\"regionId\" value=\"");
    xmlSaveRequest.append(aRegion.setNum(regionID));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"supplyType\" value=\"");
    xmlSaveRequest.append(aSupply.setNum(supplyType));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("<attribute key=\"quantity\" value=\"");
    xmlSaveRequest.append(aQuantity.setNum(quantity));
    xmlSaveRequest.append("\" />");
    xmlSaveRequest.append("</entity></message>");
    //qDebug() << xmlSaveRequest;

    //SPENCE
    //send xml query to  communication component


    //SPENCE
    //get a status response string
    xmlStatus = "Response from server";



    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }

    return replyStatus;
}

//Update Inventory
QString DataHandler::updateInventory(int id, int quantity) {
    QString replyStatus;
    QString xmlStatus;

    //Update the entity
    QString anId;
    QString aQuantity;

    QString xmlUpdateRequest = "<?xml version=\"1.0\"?><message><command>saveEntities</command>";
    xmlUpdateRequest.append("<entity type=\"Inventory\" id=\"");
    xmlUpdateRequest.append(anId.setNum(id));
    xmlUpdateRequest.append("\">");
    xmlUpdateRequest.append("<attribute key=\"quantity\" value=\"");
    xmlUpdateRequest.append(aQuantity.setNum(quantity));
    xmlUpdateRequest.append("\" />");
    xmlUpdateRequest.append("</entity></message>");

    //SPENCE
    //send xml query to  communication component

    //SPENCE
    //get a status response string
    xmlStatus = connection->sendRequest(xmlUpdateRequest);




    //Parse the xml
    if (xmlStatus != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        //if it's a valid XML and properly nested
        if (doc.setContent(xmlStatus)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            QDomElement m = n.toElement();
            if(m.tagName() == "command" && m.text() == "saveEntities") {
                QDomNode e = n.nextSibling();
                QDomElement f = e.toElement();
                if(f.tagName() == "status") {
                    replyStatus = f.text();
                }
            }
        }
    }



    return replyStatus;
}
