#include "SupplyType.h"

SupplyType::SupplyType(int anId, QString aName, int aColorIndex, bool isEnabled):id(anId), name(aName), colorIndex(aColorIndex), enabled(isEnabled) {}
SupplyType::~SupplyType() {}

int SupplyType::getId() {
    return id;
}

QString SupplyType::getName() {
    return name;
}

int SupplyType::getColorIndex() {
    return colorIndex;
}

bool SupplyType::getEnabled() {
    return enabled;
}

void SupplyType::setEnabled(bool changeEnabled) {
    enabled = changeEnabled;
}
