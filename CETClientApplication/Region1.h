#ifndef REGION1_H
#define REGION1_H

#include <QString>

//Region1.h
//Defines a Region1

//Region1 class definition
class Region1 {
private:
        int id;
        int provinceId;
        QString name;
        int centerX;
        int centerY;
public:
        Region1(int, int, QString, int, int);
        ~Region1();

        int getId();
        int getProvinceId();
        QString getName();
        int getCenterX();
        int getCenterY();
};

#endif // REGION1_H
