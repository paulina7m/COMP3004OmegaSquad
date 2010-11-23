#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "CaseReport.h"
#include "DiseaseType.h"
#include "Inventory.h"
#include "Province.h"
#include "Region.h"
#include "Shipment.h"
#include "ShipmentDetail.h"
#include "SupplyType.h"
#include "User.h"
#include <QList>
#include <QString>


class DataHandler
{
public:
    DataHandler();
    //QList<CaseReport> getCaseReports(int,int, int,QString, QString,int,int,int);
    QList<CaseReport> getCaseReports();
    QList<DiseaseType> getDiseaseTypes();
    QList<Inventory> getInventory();
    QList<Region> getRegions();
    QList<Province> getProvinces();
    QList<Shipment> getShipments();
    QList<ShipmentDetail> getShipmentDetails();
    QList<SupplyType> getSupplyTypes();

    QString saveCaseReport(int, QString, int, int);
    QString updateCaseReport(int, int, QString, int, int);
    QString saveShipment(int, int, QString, int, int, QString);
    QString updateShipment(int, int, int, QString, QString, QString, QString);
    QString saveInventory(int, int, int);
    QString updateInventory(int, int);

};

#endif // DATAHANDLER_H


