#ifndef CONFIGURECET_H
#define CONFIGURECET_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
    class ConfigureCet;
}

class ConfigureCet : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigureCet(QWidget *parent = 0);
    ~ConfigureCet();

private:
    Ui::ConfigureCet *ui;
    QString ipAddress;
    QFile *file;
    QMessageBox msgBox;

private slots:
    void configureCetSubmitButtonHandler();
    void configureCetCancelButtonHandler();
};

#endif // CONFIGURECET_H
