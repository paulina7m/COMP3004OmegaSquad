#include "ShipmentDetail.h"

ShipmentDetail::ShipmentDetail(int anId, int aShipmentId, int aSupplyType, int aQuantityRequested, int aQuantityShipped):id(anId), shipmentId(aShipmentId), supplyType(aSupplyType), quantityRequested(aQuantityRequested), quantityShipped(aQuantityShipped) {}
ShipmentDetail::~ShipmentDetail() {}

int ShipmentDetail::getId() {
    return id;
}

int ShipmentDetail::getShipmentId() {
    return shipmentId;
}

int ShipmentDetail::getSupplyType() {
    return supplyType;
}

int ShipmentDetail::getQuantityRequested() {
    return quantityRequested;
}

int ShipmentDetail::getQuantityShipped() {
    return quantityShipped;
}
