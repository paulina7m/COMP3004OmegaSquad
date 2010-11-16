#ifndef REGION_H
#define REGION_H

#include <QString>

//Region.h
//Defines a region
//Based on teamJAG's DesignReview p.25

//Region class definition
class Region {
private:
        int id;
        int provinceId;
        QString name;
        int centerX;
        int centerY;
        QString polygonPoints;
public:
        Region(int, int, QString, int, int, QString);
        ~Region();

        int getId();
        int getProvinceId();
        QString getName();
        int getCenterX();
        int getCenterY();
        QString getPolygonPoints();
};

#endif // REGION_H
