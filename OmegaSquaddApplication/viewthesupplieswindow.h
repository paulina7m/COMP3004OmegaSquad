#ifndef VIEWTHESUPPLIESWINDOW_H
#define VIEWTHESUPPLIESWINDOW_H

#include <QDialog>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/SupplyType.h"
#include "../CETClientApplication/Region1.h"

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
    DataHandler *dh;
private slots:
    void editInventory(int);
    void ViewTheSuppliesWindowSubmitButtonHandler();
    void ViewTheSuppliesWindowCancelButtonHandler();
};

#endif // VIEWTHESUPPLIESWINDOW_H
