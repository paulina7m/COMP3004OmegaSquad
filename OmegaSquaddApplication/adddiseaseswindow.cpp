#include "adddiseaseswindow.h"
#include "ui_adddiseaseswindow.h"
#include <QDebug>

AddDiseasesWindow::AddDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDiseasesWindow)
{
    QDate currentDate = QDate::currentDate();
    ui->setupUi(this);
    ui->label_6->setText(currentDate.toString("ddd MMMM d yyyy"));

    //Check if there's a connection
    DataHandler *dh = new DataHandler();
    if (dh->isConnected()) {
        ui->comboBox->addItems(fetchListOfRegions());
        ui->comboBox_2->addItems(fetchListOfDiseases());
    }
    else {
        ui->pushButton->hide();
    }
    delete dh;
}

//Get a list of disease from the server
QStringList AddDiseasesWindow::fetchListOfDiseases() {
    QStringList list;

    DataHandler *dh = new DataHandler();
    diseaseList = dh->getDiseaseTypes();
    for (int i = 0; i < diseaseList.size(); i++) {
        list.push_front(diseaseList[i].getName());
    }
    delete dh;

    return list;
}

//Get a list of Region1s from the server
QStringList AddDiseasesWindow::fetchListOfRegions() {
    QStringList list;

    DataHandler *dh = new DataHandler();
    Region1List = dh->getRegions();
    for (int i = 0; i < Region1List.size(); i++) {
        list.push_front(Region1List[i].getName());
    }
    delete dh;

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
    QDate currentDate = QDate::currentDate();
    date = currentDate.toString("yyyy-MM-dd");
    //qDebug() << date;

    //Save CaseReports
    //Required inputs: Region1 Id of the case, the date ("YYYY-MM-DD" format), the disease type and the quantity
    DataHandler *dh = new DataHandler();
    dh->saveCaseReport(Region1Id, date, diseaseType, quantity);
    delete dh;

    //Use a confirmation popup dialog
    msgBox.setText("Case report has been saved.");
    msgBox.exec();
    emit diseaseAdded();
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
