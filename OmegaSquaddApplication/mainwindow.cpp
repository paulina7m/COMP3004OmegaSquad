#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWebKit>
#include <QList>
#include "adddiseaseswindow.h"
#include "addsupplieswindow.h"
#include "viewthediseaseswindow.h"
#include "viewthesupplieswindow.h"
#include "createshipmentswindow.h"
#include "managetheshipmentswindow.h"
//#include "updatecasereport.h"
//#include "updateinventory.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
        this->setGeometry(100,100, 998,569);
        ui->setupUi(this);
        this->ui->type_selector->clear();
        this->ui->type_selector->addItems(fetchListOfDiseases());
        initializeMap();
        QObject::connect(ui->e_s_selector,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChangedForESSelector(int)));
        QObject::connect(ui->actionAbout_CET,SIGNAL(triggered()),this,SLOT(showAboutCETDialog()));
}




void MainWindow::initializeMap()
{

    GoogleMap *gmap = new GoogleMap(ui->mapView, this);
    QObject::connect(gmap, SIGNAL(mapItemClicked(QString, QString)),
                         this, SLOT(setNameIDValue(QString, QString)));
    QObject::connect(gmap, SIGNAL(notifyMapTilesLoaded()),
                         this, SLOT(hideLoadingLabel()));
    gmap->show();



}

void MainWindow::setNameIDValue(QString name, QString id)
{

    this->ui->namebox->setText(name);
    this->ui->idbox->setText(id);

// TODO: to fetch the total number of cases
//    QString totalnumber of = getNumberOfCases();
//    this->ui->numberofbox->setText(totalnumberof);


}

QStringList MainWindow::fetchListOfDiseases(){
    QStringList list;

    //TODO: fetch list from data handler
    //list =
    list.push_front("H1N1");
    list.push_front("ChickenPox");
    list.push_front("HIV");
    list.push_front("Maliaria");

    return list;
}

QStringList MainWindow::fetchListOfSupplyTypes(){
    QStringList list;

    //TODO: fetch list from data handler
    //list =

    list.push_front("Bandages");
    list.push_front("Morphine");
    list.push_front("Blades");
    list.push_front("Knives");

    return list;
}


void MainWindow::currentIndexChangedForESSelector(int index){
    this->ui->namebox->clear();
    this->ui->idbox->clear();
    this->ui->numberofbox->clear();
    this->ui->type_selector->clear();
    if(index == 0){
        this->ui->type_selector->addItems(fetchListOfDiseases());
        this->ui->numberof_label->setText("Number of Cases:");
    }else{
        this->ui->type_selector->addItems(fetchListOfSupplyTypes());
        this->ui->numberof_label->setText("Number of Supplies:");
    }
}


void MainWindow::hideLoadingLabel(){
    this->ui->loadinglabel->hide();
}

void MainWindow::showAboutCETDialog(){
    if(!aboutDialog){
        aboutDialog = new AboutCETDialog(ui->mapView);
        QObject::connect(aboutDialog, SIGNAL(dialogToBeClosed()),
                             this, SLOT(closeAboutCETDialog()));
    }

    aboutDialog->show();
}

void MainWindow::closeAboutCETDialog(){

    aboutDialog->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddDiseaseHandler()
{
    AddDiseasesWindow *addDiseasesWindow = new AddDiseasesWindow;
    addDiseasesWindow->show();
    addDiseasesWindow->isModal();
}

void MainWindow::AddSupplyHandler()
{
    AddSuppliesWindow *addSuppliesWindow = new AddSuppliesWindow;
    addSuppliesWindow->show();
    addSuppliesWindow->isModal();
}

void MainWindow::ViewDiseasesHandler()
{
    ViewTheDiseasesWindow *viewTheDiseasesWindow = new ViewTheDiseasesWindow;
    viewTheDiseasesWindow->show();
    viewTheDiseasesWindow->isModal();
}

void MainWindow::ViewSuppliesHandler()
{
    ViewTheSuppliesWindow *viewTheSuppliesWindow = new ViewTheSuppliesWindow;
    viewTheSuppliesWindow->show();
    viewTheSuppliesWindow->isModal();
}

void MainWindow::AddShipmentHandler()
{
    CreateShipmentsWindow *createShipmentsWindow = new CreateShipmentsWindow;
    createShipmentsWindow->show();
    createShipmentsWindow->isModal();
}

void MainWindow::ManageShipmentsHandler()
{
    ManageTheShipmentsWindow *manageTheShipmentsWindow = new ManageTheShipmentsWindow;
    manageTheShipmentsWindow->show();
    manageTheShipmentsWindow->isModal();
}

/*
void MainWindow::UpdateCaseReportHandler()
{
    UpdateCaseReport *updateCaseReport = new UpdateCaseReport;
    updateCaseReport->isModal();
}

void MainWindow::UpdateInventoryHandler()
{
    updateinventory *updateInventory = new updateinventory;
    updateInventory->isModal();
}
*/

