#ifndef CREATESHIPMENTSWINDOW_H
#define CREATESHIPMENTSWINDOW_H

#include <QDialog>

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
};

#endif // CREATESHIPMENTSWINDOW_H
