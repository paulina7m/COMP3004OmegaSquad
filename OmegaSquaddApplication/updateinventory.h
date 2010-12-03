#ifndef UPDATEINVENTORY_H
#define UPDATEINVENTORY_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"

namespace Ui {
    class updateinventory;
}

class updateinventory : public QDialog
{
    Q_OBJECT

public:
    explicit updateinventory(QWidget *parent = 0);
    ~updateinventory();
    void updateInventory(int id);

private:
    Ui::updateinventory *ui;
    DataHandler *dh;
    int inventoryId;
    QMessageBox msgBox;

private slots:
    void UpdateInventorySubmitButtonHandler();
    void UpdateInventoryCancelButtonHandler();

signals:
    void suppliesUpdated();
};

#endif // UPDATEINVENTORY_H
