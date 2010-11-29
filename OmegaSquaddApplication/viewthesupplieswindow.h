#ifndef VIEWTHESUPPLIESWINDOW_H
#define VIEWTHESUPPLIESWINDOW_H

#include <QDialog>
#include "DataHandler.h"
#include "SupplyType.h"
#include "Region.h"
#include "Inventory.h"
#include "addsupplieswindow.h"

namespace Ui {
    class ViewTheSuppliesWindow;
}

class ViewTheSuppliesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTheSuppliesWindow(QWidget *parent = 0);
    ~ViewTheSuppliesWindow();

private:
    Ui::ViewTheSuppliesWindow *ui;
    void PopulateTable();
    QStringList FetchListOfSupplies();
    QStringList FetchListOfRegions();
    QStringList regionNamesList;
    QStringList supplyNamesList;
    QList<int> quantityList;
    QList<int> FetchQuantity();
    QList<SupplyType> supplyList;
    QList<Region> regionList;
    QList<Inventory> inventoryList;
    DataHandler *dh;

private slots:
    void AddNewSupplyHandler();
};

#endif // VIEWTHESUPPLIESWINDOW_H
