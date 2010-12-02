#ifndef UPDATECASEREPORT_H
#define UPDATECASEREPORT_H

#include <QDialog>
#include <QMessageBox>
#include "../CETClientApplication/DataHandler.h"

namespace Ui {
    class UpdateCaseReport;
}

class UpdateCaseReport : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateCaseReport(QWidget *parent = 0);
    ~UpdateCaseReport();
    void updateCases(int id);

private:
    Ui::UpdateCaseReport *ui;
    DataHandler *dh;
    int caseId;
    QMessageBox msgBox;
private slots:
    void updateCaseReportSubmitButtonHandler();
    void updateCaseReportCancelButtonHandler();

 signals:
    void caseUpdated();

};

#endif // UPDATECASEREPORT_H
