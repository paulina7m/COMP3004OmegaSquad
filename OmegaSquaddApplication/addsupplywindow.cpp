#include "addsupplywindow.h"
#include "ui_addsupplywindow.h"
#include "mainwindow.h"
#include "adddiseasewindow.h"
#include "createshipmentwindow.h"
#include "manageshipmentswindow.h"

AddSupplyWindow::AddSupplyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSupplyWindow)
{
    ui->setupUi(this);
}

AddSupplyWindow::~AddSupplyWindow()
{
    delete ui;
}

void AddSupplyWindow::MapHandler()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->showNormal();
    this->close();
}

void AddSupplyWindow::AddDiseaseHandler()
{
    AddDiseaseWindow *addDiseaseWindow = new AddDiseaseWindow;
    addDiseaseWindow->showNormal();
    this->close();
}

void AddSupplyWindow::CreateShipmentHandler()
{
    CreateShipmentWindow *createShipmentWindow = new CreateShipmentWindow;
    createShipmentWindow->showNormal();
    this->close();
}

void AddSupplyWindow::ManageShipmentHandler()
{
    ManageShipmentsWindow *manageShipmentsWindow = new ManageShipmentsWindow;
    manageShipmentsWindow->showNormal();
    this->close();
}
