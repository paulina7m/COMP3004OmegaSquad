#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <QString>

//Shipment.h
//Defines a shipment
//Based on teamJAG's DesignReview p.26

//Shipment class definition
class Shipment {
public:
        enum shipmentState{
            Created,
            Shipped,
            Received,
            Cancelled
        };

        Shipment(int, int, int, shipmentState, QString, QString);
        ~Shipment();

        int getId();
        int getSrcRegion();
        int getDestRegion();
        Shipment::shipmentState getShipmentState();
        void setShipmentState(shipmentState);
        QString getCreatedDate();
        QString getShippedDate();
        void setShippedDate(QString);
        QString getReceivedDate();
        void setReceivedDate(QString);
        QString getCancelledDate();
        void setCancelledDate(QString);
        QString getNotes();
        void setNotes(QString);
private:
        int id;
        int srcRegion;
        int destRegion;
        shipmentState shipState;
        QString createdDate;
        QString shippedDate;
        QString receivedDate;
        QString cancelledDate;
        QString notes;
};

#endif // SHIPMENT_H
