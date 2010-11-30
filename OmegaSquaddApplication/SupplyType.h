#ifndef SUPPLYTYPE_H
#define SUPPLYTYPE_H

#include <QString>

//SupplyType.h
//Defines a supply
//Based on teamJAG's DesignReview p.28

//SupplyType class definition
class SupplyType {
private:
        int id;
        QString name;
        int colorIndex;
        bool enabled;
public:
        SupplyType(int, QString, int, bool);
        ~SupplyType();

        int getId();
        QString getName();
        int getColorIndex();
        bool getEnabled();
        void setEnabled(bool);
};


#endif // SUPPLYTYPE_H
