#ifndef ADDSUPPLIESWINDOW_H
#define ADDSUPPLIESWINDOW_H

#include <QDialog>
#include <QMessageBox>
<<<<<<< HEAD
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region.h"
=======
#include "DataHandler.h"
#include "SupplyType.h"
#include "Region.h"
>>>>>>> 52cbc344018b1185dd9a38258f6e53a3aa5879f4

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
<<<<<<< HEAD
    QMessageBox msgBox;
    SupplyType *aSupply;
    SupplyType *bSupply;
    Region *aRegion;
    Region *bRegion;

private slots:
    void addSuppliesSubmitButtonHandler();
    void addSuppliesCancelButtonHandler();
=======
    QMessageBox messageBox;

private slots:
    void SubmitButtonHandler();

>>>>>>> 52cbc344018b1185dd9a38258f6e53a3aa5879f4
};

#endif // ADDSUPPLIESWINDOW_H
