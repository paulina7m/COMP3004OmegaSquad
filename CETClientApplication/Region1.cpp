#include "Region1.h"

Region1::Region1(int anId, int aProvinceId, QString aName, int aCenterX, int aCenterY):id(anId), provinceId(aProvinceId), name(aName), centerX(aCenterX), centerY(aCenterY) {}
Region1::~Region1() {}

int Region1::getId() {
    return id;
}

int Region1::getProvinceId() {
    return provinceId;
}

QString Region1::getName() {
    return name;
}

int Region1::getCenterX() {
    return centerX;
}

int Region1::getCenterY() {
    return centerY;
}
