#ifndef CASEREPORT_H
#define CASEREPORT_H

#include <QDate>

//CaseReport.h
//Represents an epidemic case object
//Based on teamJAG's DesignReview p.22

//CaseReport class definition
class CaseReport {
private:
        int id;
        int regionId;
        QDate dateOfReport;
        int diseaseType;
        bool correction;
        int quantity;
public:
        CaseReport(int, int, QDate, int, int);
        ~CaseReport();

        int getId();
        int getRegionId();
        QDate getDateOfReport();
        int getDiseaseType();
        void setCorrection(bool);
        bool getCorrection();
        void setQuantity(int);
        int getQuantity();

};

#endif // CASEREPORT_H
