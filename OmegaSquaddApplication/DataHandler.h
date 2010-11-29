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
#include "clientconnection.h"


class DataHandler
{
public:
    DataHandler();
    ~DataHandler();
    
    //Retrieve Case Reports
    QList<CaseReport> getCaseReports();
    
    //Retrieve Disease Types
    QList<DiseaseType> getDiseaseTypes();
    
    //Retrieve Inventory
    QList<Inventory> getInventory();
    
    //Retrieve Regions
    QList<Region> getRegions();
    
    //Retrieve Provinces
    QList<Province> getProvinces();
    
    //Retrieve Shipments
    QList<Shipment> getShipments();
    //Retrieve Shipment Details, always in conjunction with retrieving Shipments
    QList<ShipmentDetail> getShipmentDetails();
    
    //Retrieve Supply Types
    QList<SupplyType> getSupplyTypes();

    //Save CaseReports
    //Required inputs: Region Id of the case, the date ("YYYY-MM-DD" format), the disease type and the quantity
    QString saveCaseReport(int, QString, int, int);
    
    //Update CaseReport
    //Required inputs: id of the case report and the adjusted quantity
    QString updateCaseReport(int, int);
    
    //Save Shipments
    //Required inputs: source region id number , the destination region id number, the date of creation ("YYYY-MM-DD") and Quantity requested
    //Optional inputs: notes (this can be empty string)
    QString saveShipment(int, int, QString, int, int, QString);

    //Update Shipments
    //Required inputs: shipment id number , shipmentdetail id number and any one of ShippedDate, ReceivedDate or CancelledDate.
    //NOTE: Any dates you're not updating must be passed in as empty strings.
    //If you pass in a shippedDate string, make sure you pass in a quantityShipped number (greater than 0), otherwise, the quantityShipped number should be 0
    //Optional inputs: notes (this can be empty string)
    QString updateShipment(int, int, int, QString, QString, QString, QString);

    //Save Inventory
    //Required inputs: region id associated with inventory, the supply type and Quantity of supply
    QString saveInventory(int, int, int);

    //Update Inventory
    //Required inputs: Inventory id number, adjusted quantity
    QString updateInventory(int, int);

private:
    ClientConnection* connection;

};

#endif // DATAHANDLER_H


