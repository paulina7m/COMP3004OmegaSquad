#ifndef PROVINCE_H
#define PROVINCE_H

#include <QString>

//Province.h
//Defines a province
//Based on teamJAG's DesignReview p.26

//Province class definition
class Province {
private:
        int id;
        QString name;
public:
        Province(int, QString);
        ~Province();

        int getId();
        QString getName();
};

#endif // PROVINCE_H
