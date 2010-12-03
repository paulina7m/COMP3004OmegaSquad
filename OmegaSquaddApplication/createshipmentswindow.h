#ifndef CREATESHIPMENTSWINDOW_H
#define CREATESHIPMENTSWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region1.h"
#include "../CETClientApplication/Inventory.h"

namespace Ui {
    class CreateShipmentsWindow;
}

class CreateShipmentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateShipmentsWindow(QWidget *parent = 0);
    ~CreateShipmentsWindow();
public slots:
    void fromManager(int);
private:
    Ui::CreateShipmentsWindow *ui;
    QStringList fetchListOfRegions();
    QStringList fetchListOfSupplies();
    QMessageBox msgBox;
    QList<SupplyType> supplyList;
    QList<Region1> regionList;
    QList<Inventory> inventoryList;
    SupplyType *aSupply;
    SupplyType *bSupply;
    Region1 *aRegion1;
    Region1 *bRegion1;
    bool cameFrom;
private slots:
    void changeText(QString);
    void notifyUser();
    void CreateShipmentsWindowSubmitButtonHandler();
    void CreateShipmentsWindowCancelButtonHandler();
};

#endif // CREATESHIPMENTSWINDOW_H
