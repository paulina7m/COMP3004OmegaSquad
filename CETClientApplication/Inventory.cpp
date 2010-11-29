#include "Inventory.h"

Inventory::Inventory(int anId, int aRegionId, int aSupplyType, int aQuantity, int aRequired):id(anId), regionId(aRegionId), supplyType(aSupplyType), quantity(aQuantity), required(aRequired) {}
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

int Inventory::getRequired() {
	return required;
}

void Inventory::setRequired(int changeRequired) {
	required = changeRequired;
}
