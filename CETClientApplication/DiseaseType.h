#ifndef DISEASETYPE_H
#define DISEASETYPE_H

#include <QString>

//DiseaseType.h
//Defines a disease
//Based on teamJAG's DesignReview p.23

//DiseaseType class definition
class DiseaseType {
private:
        int id;
        QString name;
        int colorIndex;
        bool enabled;
public:
        DiseaseType(int, QString, int, bool);
        ~DiseaseType();

        int getId();
        QString getName();
        int getColorIndex();
        bool getEnabled();
        void setEnabled(bool);
};

#endif // DISEASETYPE_H
