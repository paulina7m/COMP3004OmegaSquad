#ifndef MANAGETHESHIPMENTSWINDOW_H
#define MANAGETHESHIPMENTSWINDOW_H

#include <QDialog>

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
};

#endif // MANAGETHESHIPMENTSWINDOW_H
