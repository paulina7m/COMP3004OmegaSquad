#ifndef SHIPMENTDETAIL_H
#define SHIPMENTDETAIL_H

//ShipmentDetail.h
//Defines a shipment detail
//Based on teamJAG's DesignReview p.27

//ShipmentDetail class definition
class ShipmentDetail {
private:
        int id;
        int shipmentId;
        int supplyType;
        int quantityRequested;
        int quantityShipped;
public:
        ShipmentDetail(int, int, int, int, int);
        ~ShipmentDetail();

        int getId();
        int getShipmentId();
        int getSupplyType();
        int getQuantityRequested();
        int getQuantityShipped();
};

#endif // SHIPMENTDETAIL_H
