#ifndef ADDDISEASESWINDOW_H
#define ADDDISEASESWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"
#include "../CETClientApplication/DiseaseType.h"
#include "../CETClientApplication/Region1.h"

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
    QList<DiseaseType> diseaseList;
    QList<Region1> Region1List;
    QMessageBox msgBox;
    DiseaseType *aDisease;
    DiseaseType *bDisease;
    Region1 *aRegion1;
    Region1 *bRegion1;


private slots:
    void addCaseSubmitButtonHandler();
    void addCaseCancelButtonHandler();

signals:
    void diseaseAdded();
};

#endif // ADDDISEASESWINDOW_H
