#include "addsupplieswindow.h"
#include "ui_addsupplieswindow.h"
#include <QDebug>

AddSuppliesWindow::AddSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSuppliesWindow)
{
    QDate currentDate = QDate::currentDate();
    ui->setupUi(this);
    ui->label_6->setText(currentDate.toString("ddd MMMM d yyyy"));
    ui->comboBox->addItems(fetchListOfRegions());
    ui->comboBox_2->addItems(fetchListOfSupplies());
}

AddSuppliesWindow::~AddSuppliesWindow()
{
    delete ui;
}

//Get a list of regions from the server
QStringList AddSuppliesWindow::fetchListOfRegions() {
    QStringList list;

    DataHandler *dh = new DataHandler();
    regionList = dh->getRegions();
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }
    delete dh;

    return list;
}

//Get a list of Supplies
QStringList AddSuppliesWindow::fetchListOfSupplies() {
    QStringList list;

    DataHandler *dh = new DataHandler();
    supplyList = dh->getSupplyTypes();
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }
    delete dh;

    return list;
}

void AddSuppliesWindow::addSuppliesSubmitButtonHandler() {
    if (ui->spinBox->value() == 0)
    {
        msgBox.setText("Quantity must be greater than 0.");
        msgBox.exec();
    }
    else {
    int regionId;
    int supplyType;
    int quantity;

    //Get the region ID
    for (int i = 0; i < regionList.size(); i++) {
        if (ui->comboBox->currentText() == regionList[i].getName()) {
            regionId = regionList[i].getId();
        }
    }

    //Get the supplyType ID
    for (int i = 0; i < supplyList.size(); i++) {
        if (ui->comboBox_2->currentText() == supplyList[i].getName()) {
            supplyType = supplyList[i].getId();
        }
    }

    //Get the quantity entered
    quantity = ui->spinBox->value();
    //qDebug() << quantity;

    DataHandler *dh = new DataHandler();
    QList<Inventory> inventoryList = dh->getInventory();
    for (int i = 0; i < inventoryList.size(); i++) {
        if (inventoryList[i].getRegionId() == regionId && inventoryList[i].getSupplyType() == supplyType) {
            int updateQuantity = inventoryList[i].getQuantity() + quantity;
            //Update Inventory with the new quantity if has same regionid and supplytype
            dh->updateInventory(inventoryList[i].getId(), updateQuantity);
        }
        else {
            //Insert new Inventory
            dh->saveInventory(regionId, supplyType, quantity);
        }
    }
    delete dh;


    qDebug() << regionId << supplyType << quantity;
    //Use a confirmation popup dialog
    msgBox.setText("Supply data has been saved.");
    msgBox.exec();
    //close the window
    AddSuppliesWindow::close();
    }
}

void AddSuppliesWindow::addSuppliesCancelButtonHandler() {
    AddSuppliesWindow::close();
}
