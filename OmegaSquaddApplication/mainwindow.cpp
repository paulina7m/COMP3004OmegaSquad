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

    GoogleMap *gmap = new GoogleMap(ui->mapView);
    gmap->show();

}



MainWindow::~MainWindow()
{
    delete ui;
}
