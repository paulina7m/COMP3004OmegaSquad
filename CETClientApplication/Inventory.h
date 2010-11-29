#ifndef INVENTORY_H
#define INVENTORY_H

//Inventory.h
//Defines an inventory
//Based on teamJAG's DesignReview p.24

//Inventory class definition
class Inventory {
private:
        int id;
        int regionId;
        int supplyType;
        int quantity;
        int required;
public:
        Inventory(int, int, int, int, int);
        ~Inventory();

        int getId();
        int getRegionId();
        int getSupplyType();
        int getQuantity();
        void setQuantity(int);
        int getRequired();
        void setRequired(int);
};


#endif // INVENTORY_H
