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
#include "updatecasereport.h"
#include "updateinventory.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
        this->setGeometry(100,100, 998,569);
        ui->setupUi(this);
        this->ui->type_selector->clear();
        this->ui->type_selector->addItems(fetchListOfDiseases());
        fetchDataForSelectedType();
        initializeMap();
        selectedCaseOrSupplyID = 0;
        QObject::connect(ui->e_s_selector,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChangedForESSelector(int)));

}


void MainWindow::initializeMap()
{

    gmap = new GoogleMap(ui->mapView, this);
    QObject::connect(gmap, SIGNAL(mapItemClicked(QString, QString)),
                         this, SLOT(setNameIDValue(QString, QString)));
    QObject::connect(gmap, SIGNAL(notifyMapTilesLoaded()),
                         this, SLOT(hideLoadingLabel()));
    gmap->show();



}

void MainWindow::updateData(){
    fetchDataForSelectedType();
    this->ui->namebox->clear();;
    this->ui->idbox->clear();
    this->ui->numberofbox->clear();
}

void MainWindow::setNameIDValue(QString name, QString id)
{

    this->ui->namebox->setText(name);
    this->ui->idbox->setText(id);
    selectedCaseOrSupplyID = id.toInt();
 if(ui->e_s_selector->currentIndex() == 0){
    int numberOfCases = 0;

    for (int i = 0; i < caseReports.size(); i++) {
         if (caseReports[i].getRegionId() == id.toInt()) {
             int diseaseID = caseReports[i].getDiseaseType();
             QString diseaseName = "";
             for (int i = 0; i < diseaseList.size(); i++) {
                 if(diseaseList[i].getId() == diseaseID){
                     diseaseName = diseaseList[i].getName();
                 }
             }
             if (diseaseName == this->ui->type_selector->currentText()) {
                 numberOfCases += caseReports[i].getQuantity();
             }
         }
     }

    QString numberOfCasesString;
    numberOfCasesString.setNum(numberOfCases);
    this->ui->numberofbox->setText(numberOfCasesString);
} else {
    int numberOfSupplies = 0;

    for (int i = 0; i < inventory.size(); i++) {
         if (inventory[i].getRegionId() == id.toInt()) {
             int supplyID = inventory[i].getSupplyType();
             QString supplyTypeName = "";
             for (int i = 0; i < supplyList.size(); i++) {
                 if(supplyList[i].getId() == supplyID){
                     supplyTypeName = supplyList[i].getName();
                 }
             }
             if (supplyTypeName == this->ui->type_selector->currentText()) {
                 numberOfSupplies += inventory[i].getQuantity();
             }
         }
     }

    QString numberOfSuppliesString;
    numberOfSuppliesString.setNum(numberOfSupplies);
    this->ui->numberofbox->setText(numberOfSuppliesString);
}

}

QStringList MainWindow::fetchListOfDiseases(){
    QStringList list;

    DataHandler *dh = new DataHandler();
    diseaseList = dh->getDiseaseTypes();
    for (int i = 0; i < diseaseList.size(); i++) {
        list.push_front(diseaseList[i].getName());
    }
    delete dh;

    return list;
}

QStringList MainWindow::fetchListOfSupplyTypes(){
    QStringList list;

    DataHandler *dh = new DataHandler;
    supplyList = dh->getSupplyTypes();
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }
    delete dh;

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

    currentIndexChangedForTypeSelector();
}

void MainWindow::currentIndexChangedForTypeSelector(){
    fetchDataForSelectedType();
    calculateBadGoodWorse();
    //gmap->updateIcons(this->ui->type_selector->currentIndex());
}

void MainWindow::fetchDataForSelectedType(){

    DataHandler *dh = new DataHandler;
    caseReports = dh->getCaseReports();
    inventory = dh->getInventory();

    delete dh;
}

void MainWindow::calculateBadGoodWorse(){
    //TODO: calculate bad - worse - good states, add them into a hashmap attached to region ids
}


void MainWindow::hideLoadingLabel(){
    this->ui->loadinglabel->hide();
}

//void MainWindow::showAboutCETDialog(){
//    if(!aboutDialog){
//        aboutDialog = new AboutCETDialog(ui->mapView);
//        QObject::connect(aboutDialog, SIGNAL(dialogToBeClosed()),
//                             this, SLOT(closeAboutCETDialog()));
//    }

//    aboutDialog->show();
//}

//void MainWindow::closeAboutCETDialog(){

//    aboutDialog->hide();
//}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddDiseaseHandler()
{
    AddDiseasesWindow *addDiseasesWindow = new AddDiseasesWindow;
    addDiseasesWindow->showNormal();
    addDiseasesWindow->isModal();
    QObject::connect(addDiseasesWindow,SIGNAL(diseaseAdded()),this,SLOT(updateData()));
}

void MainWindow::AddSupplyHandler()
{
    AddSuppliesWindow *addSuppliesWindow = new AddSuppliesWindow;
    addSuppliesWindow->showNormal();
    addSuppliesWindow->isModal();
    QObject::connect(addSuppliesWindow,SIGNAL(suppliesAdded()),this,SLOT(updateData()));
}

void MainWindow::ViewDiseasesHandler()
{
    ViewTheDiseasesWindow *viewTheDiseasesWindow = new ViewTheDiseasesWindow;
    viewTheDiseasesWindow->showNormal();
    viewTheDiseasesWindow->isModal();
    QObject::connect(viewTheDiseasesWindow,SIGNAL(diseasesViewedEdited()),this,SLOT(updateData()));
}

void MainWindow::ViewSuppliesHandler()
{
    ViewTheSuppliesWindow *viewTheSuppliesWindow = new ViewTheSuppliesWindow;
    viewTheSuppliesWindow->showNormal();
    viewTheSuppliesWindow->isModal();
    QObject::connect(viewTheSuppliesWindow,SIGNAL(suppliesViewedEdited()),this,SLOT(updateData()));
}

void MainWindow::AddShipmentHandler()
{
    CreateShipmentsWindow *createShipmentsWindow = new CreateShipmentsWindow;
    createShipmentsWindow->showNormal();
    createShipmentsWindow->isModal();
}

void MainWindow::ManageShipmentsHandler()
{
    ManageTheShipmentsWindow *manageTheShipmentsWindow = new ManageTheShipmentsWindow;
    manageTheShipmentsWindow->showNormal();
    manageTheShipmentsWindow->isModal();
}

void MainWindow::AboutCETHandler()
{
    aboutDialog = new AboutCETDialog;
    aboutDialog->showNormal();
    aboutDialog->isModal();
}

void MainWindow::EditDataHandler(){
    if(this->ui->e_s_selector->currentIndex() == 0){
        ViewTheDiseasesWindow *viewTheDiseasesWindow = new ViewTheDiseasesWindow;
        viewTheDiseasesWindow->showNormal();
        viewTheDiseasesWindow->isModal();
        QObject::connect(viewTheDiseasesWindow,SIGNAL(diseasesViewedEdited()),this,SLOT(updateData()));
    } else {
        ViewTheSuppliesWindow *viewTheSuppliesWindow = new ViewTheSuppliesWindow;
        viewTheSuppliesWindow->showNormal();
        viewTheSuppliesWindow->isModal();
        QObject::connect(viewTheSuppliesWindow,SIGNAL(suppliesViewedEdited()),this,SLOT(updateData()));
    }
}



