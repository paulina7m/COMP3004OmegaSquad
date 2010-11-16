#include "CaseReport.h"

CaseReport::CaseReport(int anId, int aRegionId, QString aDate, int aDisease, int aQuantity):id(anId), regionId(aRegionId), dateOfReport(aDate), diseaseType(aDisease), quantity(aQuantity) {}
CaseReport::~CaseReport() {}

int CaseReport::getId() {
    return id;
}

int CaseReport::getRegionId() {
    return regionId;
}

QString CaseReport::getDateOfReport() {
    return dateOfReport;
}

int CaseReport::getDiseaseType() {
    return diseaseType;
}

void CaseReport::setCorrection(bool correctQuantity) {
    correction = correctQuantity;
}

bool CaseReport::getCorrection() {
    return correction;
}

void CaseReport::setQuantity(int adjustedQuantity) {
    quantity = adjustedQuantity;
}

int CaseReport::getQuantity() {
    return quantity;
}
