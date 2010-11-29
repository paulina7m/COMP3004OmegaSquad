#include "viewthesupplieswindow.h"
#include "ui_viewthesupplieswindow.h"

ViewTheSuppliesWindow::ViewTheSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheSuppliesWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,167,1000, 539);
    dh = new DataHandler;
    regionNamesList = FetchListOfRegions();
    supplyNamesList = FetchListOfSupplies();
    quantityList = FetchQuantity();
    PopulateTable();
}

ViewTheSuppliesWindow::~ViewTheSuppliesWindow()
{
    delete ui;
}

void ViewTheSuppliesWindow::AddNewSupplyHandler()
{
    AddSuppliesWindow *addSuppliesWindow = new AddSuppliesWindow;
    addSuppliesWindow->showNormal();
    this->close();
}

void ViewTheSuppliesWindow::PopulateTable()
{
    for(int i = 0; i < regionList.size(); i++)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(regionNamesList[i]));

    for(int i = 0; i < supplyList.size(); i++)
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(supplyNamesList[i]));

    for(int i = 0; i < inventoryList.size(); i++)
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(quantityList[i]));
}

QStringList ViewTheSuppliesWindow::FetchListOfRegions()
{
    QStringList list;

    regionList = dh->getRegions();
    for(int i = 0; i < regionList.size(); i++)
        list.push_front(regionList[i].getName());

    return list;
}

QStringList ViewTheSuppliesWindow::FetchListOfSupplies()
{
    QStringList list;

    supplyList = dh->getSupplyTypes();
    for(int i = 0; i < regionList.size(); i++)
        list.push_front(supplyList[i].getName());

    return list;
}

QList<int> ViewTheSuppliesWindow::FetchQuantity()
{
    QList<int> list;

    inventoryList = dh->getInventory();
    for(int i = 0; i < inventoryList.size(); i++)
        list.push_front(inventoryList[i].getQuantity());

    return list;
}
