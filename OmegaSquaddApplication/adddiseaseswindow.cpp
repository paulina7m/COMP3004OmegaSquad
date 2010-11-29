#include "adddiseaseswindow.h"
#include "ui_adddiseaseswindow.h"
#include <QDebug>

AddDiseasesWindow::AddDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDiseasesWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox->addItems(fetchListOfRegions());
    ui->comboBox_2->addItems(fetchListOfDiseases());
    dh = new DataHandler();
}

//Get a list of disease from the server
QStringList AddDiseasesWindow::fetchListOfDiseases() {
    QStringList list;

    diseaseList = dh->getDiseaseTypes();
    for (int i = 0; i < diseaseList.size(); i++) {
        list.push_front(diseaseList[i].getName());
    }

    //Just a test
    //list.push_front("H1N1");

    return list;
}

//Get a list of regions from the server
QStringList AddDiseasesWindow::fetchListOfRegions() {
    QStringList list;

    regionList = dh->getRegions();
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }

    //Just a test
    //list.push_front("Vancouver");

    return list;
}

//Save the case report
void AddDiseasesWindow::addCaseSubmitButtonHandler() {
    if (ui->spinBox->value() == 0)
    {
        msgBox.setText("Quantity must be greater than 0.");
        msgBox.exec();
    }
    else {
    int regionId;
    //QDateTime formatDate;
    QString date;
    int diseaseType;
    int quantity;

    //Get the region ID
    for (int i = 0; i < regionList.size(); i++) {
        if (ui->comboBox->currentText() == regionList[i].getName()) {
            regionId = regionList[i].getId();
        }
    }

    //Get the diseaseType ID
    for (int i = 0; i < diseaseList.size(); i++) {
        if (ui->comboBox_2->currentText() == diseaseList[i].getName()) {
            diseaseType = diseaseList[i].getId();
        }
    }

    //Get the quantity entered
    quantity = ui->spinBox->value();
    //qDebug() << quantity;

    //Get the date and format to proper string format (YYYY-MM-DD)
    date = ui->dateEdit->text();
    //qDebug() << date;

    //Save CaseReports
    //Required inputs: Region Id of the case, the date ("YYYY-MM-DD" format), the disease type and the quantity
    //dh->saveCaseReport(regionID, date, diseaseType, quantity);

    //Use a confirmation popup dialog
    //GAVIN: This needs to be more robust, like a confirmation box for going ahead or cancelling.
    msgBox.setText("Case report has been saved.");
    msgBox.exec();
    //close the window
    AddDiseasesWindow::close();
    }
}

AddDiseasesWindow::~AddDiseasesWindow()
{
    delete ui;
}
