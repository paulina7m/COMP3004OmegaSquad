#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QHash>
#include <QWebElement>
#include "googlemap.h"
#include "aboutCET.h"
#include "../CETClientApplication/DiseaseType.h"
#include "../CETClientApplication/DataHandler.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GoogleMap *gmap;
    AboutCETDialog *aboutDialog;
    QList<SupplyType> supplyList;
    QList<DiseaseType> diseaseList;
    QList<CaseReport> caseReports;
    QList<Inventory> inventory;
    QList<int> regionsWithCasesForSelectedDisease;
    QList<QString> regionsWithDataForSelType_low;
    QList<QString> regionsWithDataForSelType_normal;
    QList<QString> regionsWithDataForSelType_high;
    QStringList fetchListOfDiseases();
    QStringList fetchListOfSupplyTypes();
    int selectedCaseOrSupplyID;
    void fetchDataForSelectedType();
    void calculateLowHighNormal();
    QString getSupplyTypeName(int supplyTypeID);
    QString getDiseaseName(int diseaseID);
    int getTotalNumberOfCasesForRegion(int regionID, QList<CaseReport> list);



private slots:
    void initializeMap();
    void currentIndexChangedForESSelector(int index);
    void currentIndexChangedForTypeSelector(int index);
//    void showAboutCETDialog();
//    void closeAboutCETDialog(); // close function already exists - Gavin
    void AddDiseaseHandler();
    void AddSupplyHandler();
    void ViewDiseasesHandler();
    void ViewSuppliesHandler();
    void AddShipmentHandler();
    void ManageShipmentsHandler();
    void AboutCETHandler();
    void EditDataHandler();



public Q_SLOTS:
    void setNameIDValue(QString name, QString id);
    void hideLoadingLabel();
    void updateData();


};

#endif // MAINWINDOW_H
