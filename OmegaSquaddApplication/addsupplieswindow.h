#ifndef ADDSUPPLIESWINDOW_H
#define ADDSUPPLIESWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region.h"

namespace Ui {
    class AddSuppliesWindow;
}

class AddSuppliesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddSuppliesWindow(QWidget *parent = 0);
    ~AddSuppliesWindow();

private:
    Ui::AddSuppliesWindow *ui;
    QStringList fetchListOfSupplies();
    QStringList fetchListOfRegions();
    DataHandler *dh;
    QList<SupplyType> supplyList;
    QList<Region> regionList;
    QMessageBox msgBox;
    SupplyType *aSupply;
    SupplyType *bSupply;
    Region *aRegion;
    Region *bRegion;

private slots:
    void addSuppliesSubmitButtonHandler();
    void addSuppliesCancelButtonHandler();
};

#endif // ADDSUPPLIESWINDOW_H
