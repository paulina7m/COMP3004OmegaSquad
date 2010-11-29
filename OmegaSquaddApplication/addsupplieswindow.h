#ifndef ADDSUPPLIESWINDOW_H
#define ADDSUPPLIESWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "DataHandler.h"
#include "SupplyType.h"
#include "Region.h"

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
    QMessageBox messageBox;

private slots:
    void SubmitButtonHandler();

};

#endif // ADDSUPPLIESWINDOW_H
