
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "CaseReport.h"
#include "DiseaseType.h"
#include "Inventory.h"
#include "Province.h"
#include "Region.h"
#include "Shipment.h"
#include "ShipmentDetail.h"
#include "User.h"
 #include <QList>


class DataHandler
{
public:
    DataHandler();
    QList<CaseReport::CaseReport> getCaseReports(int,int,int,int,int,int,int,int);
    QList<DiseaseType::DiseaseType> getDiseaseTypes();
    QList<Inventory::Inventory> getInventory(int,int,int,int,int,int);
    QList<Province::Province> getProvinces();
    QList<Region::Region> getRegions();
    QList<Shipment::Shipment> getShipments(int,int,int,int,Shipment::shipmentState,int,int,int,int,int,int,int,int);
    QList<ShipmentDetail::ShipmentDetail> getShipmentDetails(int);


};

#endif // DATAHANDLER_H


