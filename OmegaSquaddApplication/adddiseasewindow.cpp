#include "adddiseasewindow.h"
#include "ui_adddiseasewindow.h"
#include "mainwindow.h"
#include "addsupplywindow.h"
#include "createshipmentwindow.h"
#include "manageshipmentswindow.h"
#include "viewdiseasewindow.h"
#include "viewsupplieswindow.h"

AddDiseaseWindow::AddDiseaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddDiseaseWindow)
{
    ui->setupUi(this);
}

AddDiseaseWindow::~AddDiseaseWindow()
{
    delete ui;
}

void AddDiseaseWindow::MapHandler()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->showNormal();
    this->close();
}

void AddDiseaseWindow::AddSupplyHandler()
{
    AddSupplyWindow *addSupplyWindow = new AddSupplyWindow;
    addSupplyWindow->showNormal();
    this->close();
}

void AddDiseaseWindow::CreateShipmentHandler()
{
    CreateShipmentWindow *createShipmentWindow = new CreateShipmentWindow;
    createShipmentWindow->showNormal();
    this->close();
}

void AddDiseaseWindow::ManageShipmentsHandler()
{
    ManageShipmentsWindow *manageShipmentsWindow = new ManageShipmentsWindow;
    manageShipmentsWindow->showNormal();
    this->close();
}

void AddDiseaseWindow::ViewDiseasesHandler()
{
    ViewDiseaseWindow *viewDiseaseWindow = new ViewDiseaseWindow;
    viewDiseaseWindow->showNormal();
    this->close();
}

void AddDiseaseWindow::ViewSuppliesHandler()
{
    ViewSuppliesWindow *viewSuppliesWindow = new ViewSuppliesWindow;
    viewSuppliesWindow->showNormal();
    this->close();
}
