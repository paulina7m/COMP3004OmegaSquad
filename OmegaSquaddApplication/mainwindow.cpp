#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWebKit>




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
        this->setGeometry(100,100, 998,569);
        ui->setupUi(this);
        initializeMap();
}




void MainWindow::initializeMap()
{

    GoogleMap *gmap = new GoogleMap(ui->mapView, this);
    QObject::connect(gmap, SIGNAL(mapItemClicked(QString, QString, QString)),
                         this, SLOT(setNameIDValue(QString, QString, QString)));
    gmap->show();



}

void MainWindow::setNameIDValue(QString name, QString id, QString value)
{

    this->ui->namebox->setText(name);
    this->ui->idbox->setText(id);

}




MainWindow::~MainWindow()
{
    delete ui;
}
