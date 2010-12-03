#include "viewthesupplieswindow.h"
#include "ui_viewthesupplieswindow.h"
#include <QStandardItem>
#include "updateinventory.h"
#include "addsupplieswindow.h"

ViewTheSuppliesWindow::ViewTheSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheSuppliesWindow)
{
    ui->setupUi(this);

    //This calls the database, doesn't work yet
    DataHandler *dh = new DataHandler();
    if (dh->isConnected()) {
    //Get a list of case reports
    QList<Inventory> inventoryList = dh->getInventory();
    QList<Region1> regionList = dh->getRegions();
    QList<SupplyType> supplyList = dh->getSupplyTypes();
    QString regionName;
    QString supplyType;

    //Map the edit buttons to the case id number
    QSignalMapper *mapper = new QSignalMapper();

    //CHECK THIS
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(inventoryList.size());
    ui->tableWidget->setColumnCount(4);

    for (int i = 0; i < inventoryList.size(); i++) {
        int loc = inventoryList[i].getId();
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

        //Edit button
        QPushButton *editButton = new QPushButton("Edit");
        editButton->setStyleSheet("QPushButton {border-color: black; padding: 0px; width: 3em; height: 3em; }");

        //Slot for when an edit button is pressed
        connect(editButton, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(editButton, loc);

        //Fill the table
        ui->tableWidget->setItem(i, 0, region = new QTableWidgetItem(regionName));
        region->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 1, type = new QTableWidgetItem(supplyType));
        type->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 2, quantity = new QTableWidgetItem());
        quantity->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        quantity->setData(Qt::DisplayRole, inventoryList[i].getQuantity());
        //Edit button
        ui->tableWidget->setCellWidget(i, 3, editButton);
    }
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->resizeRowsToContents();

    //If button clicked, int is the case report id to edit
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(editInventory(int)));


    /*
    QSignalMapper *mapper = new QSignalMapper();
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(4);
    QString quantity;
    int j = 0;
    ui->tableWidget->setColumnCount(5);
    for (int i = 0; i < 4; i++) {
        int loc = i;
        QPushButton *editButton = new QPushButton("Edit");
        connect(editButton, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(editButton, loc);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem("item 1"));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("item 2"));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem("item 3"));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(quantity.setNum(j++)));
        ui->tableWidget->setCellWidget(i, 4, editButton);

    }
    ui->tableWidget->setSortingEnabled(true);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(editInventory(int)));
    */
}
}

void ViewTheSuppliesWindow::editInventory(int invId) {

    //Open up the edit case window
    //qDebug() << invId;
    updateinventory *updateInventory = new updateinventory;
    updateInventory->show();
    updateInventory->isModal();
    updateInventory->updateInventory(invId);

    QObject::connect(updateInventory,SIGNAL(suppliesUpdated()),this,SLOT(emitSuppliesEditedSignal()));
    //Close this window
    ViewTheSuppliesWindow::close();
}

void ViewTheSuppliesWindow::emitSuppliesEditedSignal(){
    emit suppliesViewedEdited();
}

void ViewTheSuppliesWindow::ViewTheSuppliesWindowSubmitButtonHandler() {
    AddSuppliesWindow *addSuppliesWindow = new AddSuppliesWindow;
    addSuppliesWindow->show();
    addSuppliesWindow->isModal();
    QObject::connect(addSuppliesWindow,SIGNAL(suppliesAdded()),this,SLOT(emitDiseasesEditedSignal()));
    ViewTheSuppliesWindow::close();
}

void ViewTheSuppliesWindow::ViewTheSuppliesWindowCancelButtonHandler() {
    ViewTheSuppliesWindow::close();
}

ViewTheSuppliesWindow::~ViewTheSuppliesWindow()
{
    delete ui;
}
