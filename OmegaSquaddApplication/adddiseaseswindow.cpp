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

    /*
    //Real call but doesn't work!
    diseaseList = dh->getDiseaseTypes();
    for (int i = 0; i < diseaseList.size(); i++) {
        list.push_front(diseaseList[i].getName());
    }
    */


    //Temp workaround
    aDisease = new DiseaseType(6202, "Small Pox", 0, 1);
    bDisease = new DiseaseType(6203, "H1N1", 1, 1);
    diseaseList.append(*aDisease);
    diseaseList.append(*bDisease);
    for (int i = 0; i < diseaseList.size(); i++) {
        list.push_front(diseaseList[i].getName());
    }

    return list;
}

//Get a list of Region1s from the server
QStringList AddDiseasesWindow::fetchListOfRegions() {
    QStringList list;

    /*
    //Real call but doesn't work!
    Region1List = dh->getRegion1s();
    for (int i = 0; i < Region1List.size(); i++) {
        list.push_front(Region1List[i].getName());
    }
    */

    //Workaround
    aRegion1 = new Region1(5931, 2, "Richmond", 0, 0);
    bRegion1 = new Region1(5932, 2, "Vancouver", 0, 0);
    Region1List.append(*aRegion1);
    Region1List.append(*bRegion1);
    for (int i = 0; i < Region1List.size(); i++) {
        list.push_front(Region1List[i].getName());
    }

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
    int Region1Id;
    //QDateTime formatDate;
    QString date;
    int diseaseType;
    int quantity;

    //Get the Region1 ID
    for (int i = 0; i < Region1List.size(); i++) {
        if (ui->comboBox->currentText() == Region1List[i].getName()) {
            Region1Id = Region1List[i].getId();
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
    //Required inputs: Region1 Id of the case, the date ("YYYY-MM-DD" format), the disease type and the quantity
    //DOES NOT WORK
    //dh->saveCaseReport(Region1ID, date, diseaseType, quantity);

    //Use a confirmation popup dialog
    msgBox.setText("Case report has been saved.");
    msgBox.exec();
    //close the window
    AddDiseasesWindow::close();
    }
}

//Save the case report
void AddDiseasesWindow::addCaseCancelButtonHandler() {
    AddDiseasesWindow::close();
}

AddDiseasesWindow::~AddDiseasesWindow()
{
    delete ui;
}
