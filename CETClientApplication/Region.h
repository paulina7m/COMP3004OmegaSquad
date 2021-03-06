#ifndef REGION_H
#define REGION_H

#include <QString>

//Region.h
//Defines a region

//Region class definition
class Region {
private:
        int id;
        int provinceId;
        QString name;
        int centerX;
        int centerY;
public:
        Region(int, int, QString, int, int);
        ~Region();

        int getId();
        int getProvinceId();
        QString getName();
        int getCenterX();
        int getCenterY();
};

#endif // REGION_H
