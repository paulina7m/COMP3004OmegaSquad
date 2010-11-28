#ifndef CREATESHIPMENTWINDOW_H
#define CREATESHIPMENTWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CreateShipmentWindow;
}

class CreateShipmentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateShipmentWindow(QWidget *parent = 0);
    ~CreateShipmentWindow();

private:
    Ui::CreateShipmentWindow *ui;
};

#endif // CREATESHIPMENTWINDOW_H
