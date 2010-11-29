#ifndef ADDDISEASESWINDOW_H
#define ADDDISEASESWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/DiseaseType.h"
#include "../CETClientApplication/Region.h"

namespace Ui {
    class AddDiseasesWindow;
}

class AddDiseasesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDiseasesWindow(QWidget *parent = 0);
    ~AddDiseasesWindow();

private:
    Ui::AddDiseasesWindow *ui;
    QStringList fetchListOfDiseases();
    QStringList fetchListOfRegions();
    DataHandler *dh;
    QList<DiseaseType> diseaseList;
    QList<Region> regionList;
    QMessageBox msgBox;

private slots:
    void addCaseSubmitButtonHandler();
};

#endif // ADDDISEASESWINDOW_H
