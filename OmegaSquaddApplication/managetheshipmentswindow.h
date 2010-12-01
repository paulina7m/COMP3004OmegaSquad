#ifndef MANAGETHESHIPMENTSWINDOW_H
#define MANAGETHESHIPMENTSWINDOW_H

#include <QDialog>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region1.h"
#include "../CETClientApplication/Shipment.h"
#include "../CETClientApplication/Inventory.h"
#include "../CETClientApplication/ShipmentDetail.h"


namespace Ui {
    class ManageTheShipmentsWindow;
}

class ManageTheShipmentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ManageTheShipmentsWindow(QWidget *parent = 0);
    ~ManageTheShipmentsWindow();
private:
    Ui::ManageTheShipmentsWindow *ui;
    QStringList shipStateList;
    int status;
private slots:
    void changeShipmentStatus(QString);
    void ManageTheShipmentsWindowSubmitButtonHandler();
    void ManageTheShipmentsWindowCancelButtonHandler();
};

#endif // MANAGETHESHIPMENTSWINDOW_H
