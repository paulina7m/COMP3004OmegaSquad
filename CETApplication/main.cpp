#include <QtCore/QCoreApplication>
#include "DatabaseHandler.h"
#include <QList>
#include <QVector>

#include <QDebug>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseHandler *sqLite = new DatabaseHandler();
    sqLite->openDB();

    /*
    //Query Test
    sqLite->queryResultsFrom("select * from user");
    */

    /*
    //getIdNumbers Test
    QList<int> idRequest = sqLite->getIdNumbers(10);

    //QList<int>::iterator i;
    /for (i = idRequest.begin(); i != idRequest.end(); ++i)
        qDebug() << *i;
    */

    /*
    //Get Disease List Test
    QList<DiseaseType> List = sqLite->findDiseaseType();

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getName();
    }
    */

    /*
    //CaseReport Test
    //QList<CaseReport> List = sqLite->findCaseReport("<message><command>findEntities</command><findEntitiesRequest type=\"CaseReport\"><query key=\"regionId\" value=\"5932\" comparison=\"=\" /><query key=\"dateOfReport\" value=\"2010-10-09\" comparison=\"=\" /></findEntitiesRequest></message>");
    //QList<CaseReport> List = sqLite->findCaseReport("<message><command>findEntities</command><findEntitiesRequest type=\"CaseReport\"><query key=\"regionId\" value=\"5932\" comparison=\"=\" /></findEntitiesRequest></message>");
    //QList<CaseReport> List = sqLite->findCaseReport("<message><command>findEntities</command><findEntitiesRequest type=\"CaseReport\"></findEntitiesRequest></message>");

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getDateOfReport();
    }
    */

    /*
    //Supply list test
    QList<SupplyType> List = sqLite->findSupplyType();

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getName();
    }
    */

    /*
    //Region list test
    QList<Region> List = sqLite->findRegion();

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getName();
    }
    */

    /*
    //Province list test
    QList<Province> List = sqLite->findProvince();

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getName();
    }
    */

     /*
    //User list test
    QList<User> List = sqLite->findUser();

    for (int i = 0; i < List.size(); ++i) {
        qDebug() << List[i].getName() << " who is a " << List[i].getUserRoleStr(List[i].getUserRole());
    }

    User aUser(1, "bob", "password", 1, 1, User::MedicalAdministrator);
    qDebug() << aUser.getUserRole(User::MedicalAdministrator);
    */

    //Save Entities Test
    QString theMessage = "<message><command>saveEntities</command>";
    theMessage.append("<entity type=\"Shipment\" id=\"6225\">");
    theMessage.append("<attribute key=\"srcRegion\" value=\"5931\" />");
    theMessage.append("<attribute key=\"destRegion\" value=\"5932\" />");
    theMessage.append("<attribute key=\"shipmentState\" value=\"0\" />");
    theMessage.append("<attribute key=\"createdDate\" value=\"2010-10-10\" />");
    theMessage.append("<attribute key=\"shippedDate\" value=\"\" />");
    theMessage.append("<attribute key=\"receivedDate\" value=\"\" />");
    theMessage.append("<attribute key=\"cancelledDate\" value=\"\" />");
    theMessage.append("<attribute key=\"notes\" value=\"This is a comment.\" />");
    theMessage.append("</entity>");
    theMessage.append("<entity type=\"ShipmentDetail\" id=\"6226\">");
    theMessage.append("<attribute key=\"shipmentId\" value=\"6225\" />");
    theMessage.append("<attribute key=\"supplyType\" value=\"6217\" />");
    theMessage.append("<attribute key=\"quantityRequested\" value=\"1000\" />");
    theMessage.append("<attribute key=\"quantityShipped\" value=\"900\" />");
    theMessage.append("</entity></message>");
    bool List = sqLite->saveEntities(theMessage);
    qDebug() << List;

    //Check if the entities were inserted
    QString findMessage = "<message><command>findEntities</command>";
    findMessage.append("<findEntitiesRequest type=\"Shipment\">");
    findMessage.append("<query key=\"createdDate\" value=\"2010-10-10\" comparison=\"=\" />");
    findMessage.append("</findEntitiesRequest>");
    findMessage.append("</message>");

    QList<Shipment> aList = sqLite->findShipment(findMessage);

    for (int i = 0; i < aList.size(); ++i) {
        qDebug() << "Shipment state: " << aList[i].shipmentStateStr(aList[i].getShipmentState()) << " Notes: " << aList[i].getNotes();
    }

    qDebug() << "Closing DB";
    sqLite->closeDB();

    return a.exec();
}
