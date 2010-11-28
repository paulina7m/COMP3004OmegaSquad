#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QWebElement>
#include "googlemap.h"
#include "aboutCET.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void initializeMap();
    void currentIndexChangedForESSelector(int index);
    void showAboutCETDialog();
    void closeAboutCETDialog();

public Q_SLOTS:
    void setNameIDValue(QString name, QString id);
    void hideLoadingLabel();

private:
    Ui::MainWindow *ui;
    QStringList fetchListOfDiseases();
    QStringList fetchListOfSupplyTypes();
    AboutCETDialog *aboutDialog;
};

#endif // MAINWINDOW_H
