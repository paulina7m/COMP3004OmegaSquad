#include "updateinventory.h"
#include "ui_updateinventory.h"

updateinventory::updateinventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateinventory)
{
    ui->setupUi(this);
}

void updateinventory::updateInventory(int id) {
    inventoryId = id;

    /*
    QString regionName;
    QString supplyType;
    int quantity;

    dh = new DataHandler();
    QList<Inventory> inventoryList = dh->getInventory();
    QList<Region> regionList = dh->getRegions();
    QList<SupplyType> supplyList = dh->getSupplyTypes();

    for (int i = 0; i < inventoryList.size(); i++) {
        if (inventoryList[i].getId() == id) {
            for (int j = 0; j < regionList.size(); j++) {
                if (inventoryList[i].getRegionId() == regionList[j].getId()) {
                    regionName = regionList[j].getName();
                }
            }
            for (int k = 0; k < supplyList.size(); k++) {
                if (inventoryList[i].getSupplyType() == supplyList[k].getId()) {
                    supplyType = supplyList[k].getName();
                }
            }
            quantity = inventoryList[i].getQuantity();

        }
    }

    ui->label_2->setText(supplyType);
    ui->label_7->setText(regionName);
    ui->spinBox->setValue(quantity);

    //update the values
    dh->updateInventory(id, ui->spinBox->value());
    */


    ui->spinBox->setValue(id);
}

void updateinventory::UpdateInventorySubmitButtonHandler() {
    //dh->updateInventory(inventoryId, ui->spinBox->value());
    //qDebug() << inventoryId;

    //Use a confirmation popup dialog
    msgBox.setText("Inventory has been updated.");
    msgBox.exec();

    updateinventory::close();
}

void updateinventory::UpdateInventoryCancelButtonHandler() {
    updateinventory::close();
}

updateinventory::~updateinventory()
{
    delete ui;
}
