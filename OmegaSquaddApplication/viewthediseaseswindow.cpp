#include "viewthediseaseswindow.h"
#include "ui_viewthediseaseswindow.h"
#include <QStandardItem>
#include "updatecasereport.h"
#include "adddiseaseswindow.h"

ViewTheDiseasesWindow::ViewTheDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheDiseasesWindow)
{
    ui->setupUi(this);

    /*
    //This calls the database, doesn't work yet
    dh = new DataHandler();
    //Get a list of case reports
    QList<CaseReport> caseList = dh->getCaseReports();
    QList<Region> regionList = dh->getRegions();
    QList<DiseaseType> diseaseList = dh->getDiseaseTypes();
    QString regionName;
    QString diseaseType;

    //Map the edit buttons to the case id number
    QSignalMapper *mapper = new QSignalMapper();

    //CHECK THIS
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(caseList.size());
    ui->tableWidget->setColumnCount(5);
    QString quantityStr;

    for (int i = 0; i < caseList.size(); i++) {
        int loc = caseList[i].getId();
        for (int j = 0; j < regionList.size(); j++) {
            if (caseList[i].getRegionId() == regionList[j].getId()) {
                regionName = regionList[j].getName();
            }
        }
        for (int k = 0; k < diseaseList.size(); k++) {
            if (caseList[i].getDiseaseType() == diseaseList[k].getId()) {
                diseaseType = diseaseList[k].getName();
            }
        }
        //Edit buttons for each case
        QPushButton *editButton = new QPushButton("Edit");
        connect(editButton, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(editButton, loc);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(caseList[i].getDateOfReport()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(regionName));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(diseaseType));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(quantityStr.setNum(caseList[i].getQuantity())));
        //Edit button
        ui->tableWidget->setCellWidget(i, 4, editButton);
    }
    ui->tableWidget->setSortingEnabled(true);

    //If button clicked, int is the case report id to edit
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(editCase(int)));
    */


    QSignalMapper *mapper = new QSignalMapper();
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(4);
    QString quantity;
    int j = 0;
    ui->tableWidget->setColumnCount(5);
    for (int i = 0; i < 4; i++) {
        int loc = i;
        QPushButton *editButton = new QPushButton("Edit");
        connect(editButton, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(editButton, loc);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem("item 1"));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("item 2"));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem("item 3"));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(quantity.setNum(j++)));
        ui->tableWidget->setCellWidget(i, 4, editButton);

    }
    ui->tableWidget->setSortingEnabled(true);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(editCase(int)));

}


void ViewTheDiseasesWindow::editCase(int caseId) {
    //Open up the edit case window
    //qDebug() << caseId;

    UpdateCaseReport *updateCaseReport = new UpdateCaseReport;
    updateCaseReport->show();
    updateCaseReport->isModal();
    updateCaseReport->updateCases(caseId);
}

void ViewTheDiseasesWindow::viewTheDiseasesWindowCancelButtonHandler() {
    ViewTheDiseasesWindow::close();
}

void ViewTheDiseasesWindow::viewTheDiseasesWindowNewButtonHandler() {
    AddDiseasesWindow *addDiseasesWindow = new AddDiseasesWindow;
    addDiseasesWindow->show();
    addDiseasesWindow->isModal();
    ViewTheDiseasesWindow::close();
}

ViewTheDiseasesWindow::~ViewTheDiseasesWindow()
{
    delete ui;
}
