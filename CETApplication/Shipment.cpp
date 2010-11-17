#include "Shipment.h"

Shipment::Shipment(int anId, int aSrcRegion, int aDestRegion, shipmentState aShipmentState, QString aCreatedDate, QString someNotes):id(anId), srcRegion(aSrcRegion), destRegion(aDestRegion), shipState(aShipmentState), createdDate(aCreatedDate), notes(someNotes) {}
Shipment::~Shipment() {}

int Shipment::getId() {
    return id;
}

int Shipment::getSrcRegion() {
    return srcRegion;
}

int Shipment::getDestRegion() {
    return destRegion;
}

Shipment::shipmentState Shipment::getShipmentState() {
    return shipState;
}

void Shipment::setShipmentState(shipmentState currentStatus) {
    shipState = currentStatus;
}

QString Shipment::getCreatedDate() {
    return createdDate;
}

QString Shipment::getShippedDate() {
    return shippedDate;
}

void Shipment::setShippedDate(QString shipDate) {
    shippedDate = shipDate;
}

QString Shipment::getReceivedDate() {
    return receivedDate;
}

void Shipment::setReceivedDate(QString receiveDate) {
    receivedDate = receiveDate;
}

QString Shipment::getCancelledDate() {
    return cancelledDate;
}

void Shipment::setCancelledDate(QString cancelDate) {
    cancelledDate = cancelDate;
}

QString Shipment::getNotes() {
    return notes;
}

void Shipment::setNotes(QString shipmentNotes) {
    notes = shipmentNotes;
}
