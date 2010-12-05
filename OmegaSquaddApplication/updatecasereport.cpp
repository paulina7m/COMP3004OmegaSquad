#include "updatecasereport.h"
#include "ui_updatecasereport.h"
#include "viewthediseaseswindow.h"
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/DiseaseType.h"
#include "../CETClientApplication/Region1.h"


UpdateCaseReport::UpdateCaseReport(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::UpdateCaseReport)
{
    ui->setupUi(this);
}

void UpdateCaseReport::updateCases(int id) {
    caseId = id;

    QString regionName;
    QString diseaseType;
    QString date;
    int quantity;

    dh = new DataHandler();
    if (dh->isConnected()) {
        QList<CaseReport> caseList = dh->getCaseReports();
        QList<Region1> regionList = dh->getRegions();
        QList<DiseaseType> diseaseList = dh->getDiseaseTypes();

        for (int i = 0; i < caseList.size(); i++) {
            if (caseList[i].getId() == id) {
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
                date = caseList[i].getDateOfReport();
                quantity = caseList[i].getQuantity();

            }
        }

        ui->label_2->setText(diseaseType);
        ui->label_7->setText(regionName);
        ui->label_8->setText(date);
        ui->spinBox->setValue(quantity);


        //ui->spinBox->setValue(id);
    }
}

void UpdateCaseReport::updateCaseReportSubmitButtonHandler() {
    dh->updateCaseReport(caseId, ui->spinBox->value());
    //qDebug() << caseId;

    //Use a confirmation popup dialog
    msgBox.setText("Case report has been updated.");
    msgBox.exec();

    ViewTheDiseasesWindow *viewTheDiseasesWindow = new ViewTheDiseasesWindow;
    viewTheDiseasesWindow->show();
    viewTheDiseasesWindow->setModal(true);

    UpdateCaseReport::close();
}


void UpdateCaseReport::updateCaseReportCancelButtonHandler() {
    ViewTheDiseasesWindow *viewTheDiseasesWindow = new ViewTheDiseasesWindow;
    viewTheDiseasesWindow->show();
    viewTheDiseasesWindow->setModal(true);

    emit caseUpdated();
    UpdateCaseReport::close();
}

UpdateCaseReport::~UpdateCaseReport()
{
    delete ui;
}
