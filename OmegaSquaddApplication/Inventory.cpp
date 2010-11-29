#include "Inventory.h"

Inventory::Inventory(int anId, int aRegionId, int aSupplyType, int aQuantity):id(anId), regionId(aRegionId), supplyType(aSupplyType), quantity(aQuantity) {}
Inventory::~Inventory() {}

int Inventory::getId() {
    return id;
}

int Inventory::getRegionId() {
    return regionId;
}

int Inventory::getSupplyType() {
    return supplyType;
}

int Inventory::getQuantity() {
    return quantity;
}

void Inventory::setQuantity(int changeQuantity) {
    quantity = changeQuantity;
}
