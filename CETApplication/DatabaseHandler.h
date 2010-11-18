#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
#include <QSqlQuery>
#include <QString>
#include <QList>
#include "DiseaseType.h"
#include "CaseReport.h"
#include "Inventory.h"
#include "Region.h"
#include "Province.h"
#include "Shipment.h"
#include "ShipmentDetail.h"
#include "SupplyType.h"
#include "User.h"

/*
The following must be added to the .pro file
QT += sql
QT += xml
*/

class DatabaseHandler
{
  public:
    //Opens the database with the database path/name of db passed
    bool openDB(QString);

    //Runs any query (for testing)
    QSqlQuery queryResultsFrom(QString sqlQuery);

    //Find Entities, turn objects into query
    //Send list of entities to Server Message class
    QList<DiseaseType> findDiseaseType();
    QList<SupplyType> findSupplyType();
    QList<Inventory> findInventory(QString xmlString);
    QList<Region> findRegion();
    QList<Province> findProvince();
    QList<Shipment> findShipment(QString xmlString);
    QList<ShipmentDetail> findShipmentDetail(QString xmlString);
    QList<CaseReport> findCaseReport(QString xmlString);
    QList<User> findUser();

    //Save Entities (create entities)
    //NOTE: The client must request id numbers first, get a reply, then attach the id numbers to an object
    //Send bool back to Server Message class
    QString saveEntities(QString xmlString);

    //Get login information
    //Send status string back to Server Message class
    QString checkLogin(QString xmlString);

    //Get ID Numbers (for when creating entities)
    QList<int> getIdNumbers(int blockSize);

    void closeDB();
  private:
    QList<CaseReport> caseReportList;
    QList<DiseaseType> diseaseList;
    QList<SupplyType> supplyList;
    QList<Region> regionList;
    QList<Province> provinceList;
    QList<User> userList;
    QList<Shipment> shipmentList;
    QList<Inventory> inventoryList;
    QList<ShipmentDetail> shipmentDetailList;

    QSqlDatabase db;
    int maxId;
};

#endif // DATABASEHANDLER_H
