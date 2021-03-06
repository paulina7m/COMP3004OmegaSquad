#include "Region.h"

Region::Region(int anId, int aProvinceId, QString aName, int aCenterX, int aCenterY, QString somePolygonPoints):id(anId), provinceId(aProvinceId), name(aName), centerX(aCenterX), centerY(aCenterY), polygonPoints(somePolygonPoints) {}
Region::~Region() {}

int Region::getId() {
    return id;
}

int Region::getProvinceId() {
    return provinceId;
}

QString Region::getName() {
    return name;
}

int Region::getCenterX() {
    return centerX;
}

int Region::getCenterY() {
    return centerY;
}

QString Region::getPolygonPoints() {
    return polygonPoints;
}
