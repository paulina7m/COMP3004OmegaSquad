#include "Province.h"

Province::Province(int anId, QString aName):id(anId), name(aName) {}
Province::~Province() {}

int Province::getId() {
    return id;
}

QString Province::getName() {
    return name;
}
