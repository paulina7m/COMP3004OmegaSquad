#ifndef ADDDISEASEWINDOW_H
#define ADDDISEASEWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AddDiseaseWindow;
}

class AddDiseaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDiseaseWindow(QWidget *parent = 0);
    ~AddDiseaseWindow();

public slots:
    void MapHandler();
    void AddSupplyHandler();
    void CreateShipmentHandler();
    void ManageShipmentsHandler();
    void ViewDiseasesHandler();
    void ViewSuppliesHandler();

private:
    Ui::AddDiseaseWindow *ui;
};

#endif // ADDDISEASEWINDOW_H
