#ifndef ADDSUPPLYWINDOW_H
#define ADDSUPPLYWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AddSupplyWindow;
}

class AddSupplyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSupplyWindow(QWidget *parent = 0);
    ~AddSupplyWindow();

public slots:
    void MapHandler();
    void AddDiseaseHandler();
    void CreateShipmentHandler();
    void ManageShipmentHandler();

private:
    Ui::AddSupplyWindow *ui;
};

#endif // ADDSUPPLYWINDOW_H
