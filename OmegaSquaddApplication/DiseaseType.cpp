#include "DiseaseType.h"

DiseaseType::DiseaseType(int anId, QString aName, int aColorIndex, bool isEnabled):id(anId), name(aName), colorIndex(aColorIndex), enabled(isEnabled) {}
DiseaseType::~DiseaseType() {}

int DiseaseType::getId() {
    return id;
}

QString DiseaseType::getName() {
    return name;
}

int DiseaseType::getColorIndex() {
    return colorIndex;
}

bool DiseaseType::getEnabled() {
    return enabled;
}

void DiseaseType::setEnabled(bool changeEnabled) {
    enabled = changeEnabled;
}
