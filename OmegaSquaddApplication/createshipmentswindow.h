#ifndef CREATESHIPMENTSWINDOW_H
#define CREATESHIPMENTSWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region1.h"

namespace Ui {
    class CreateShipmentsWindow;
}

class CreateShipmentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateShipmentsWindow(QWidget *parent = 0);
    ~CreateShipmentsWindow();

private:
    Ui::CreateShipmentsWindow *ui;
    QStringList fetchListOfRegions();
    QStringList fetchListOfSupplies();
    QMessageBox msgBox;
    QList<SupplyType> supplyList;
    QList<Region1> regionList;
    SupplyType *aSupply;
    SupplyType *bSupply;
    Region1 *aRegion1;
    Region1 *bRegion1;
private slots:
    void CreateShipmentsWindowSubmitButtonHandler();
    void CreateShipmentsWindowCancelButtonHandler();
};

#endif // CREATESHIPMENTSWINDOW_H
