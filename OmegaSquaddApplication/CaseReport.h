#ifndef CASEREPORT_H
#define CASEREPORT_H

#include <QString>

//CaseReport.h
//Represents an epidemic case object
//Based on teamJAG's DesignReview p.22

//CaseReport class definition
class CaseReport {
private:
        int id;
        int regionId;
        QString dateOfReport;
        int diseaseType;
        bool correction;
        int quantity;
public:
        CaseReport(int, int, QString, int, int);
        ~CaseReport();

        int getId();
        int getRegionId();
        QString getDateOfReport();
        int getDiseaseType();
        void setCorrection(bool);
        bool getCorrection();
        void setQuantity(int);
        int getQuantity();

};

#endif // CASEREPORT_H
