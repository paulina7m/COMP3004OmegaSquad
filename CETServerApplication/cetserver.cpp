#include "cetserver.h"
#include "ui_cetserver.h"
#include <QDebug>
#include <QFile>

CETServer::CETServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CETServer)
{
    ui->setupUi(this);
}

CETServer::~CETServer()
{
    sqLite->closeDB();
    delete ui;
}

/*Start server button handler*/
void CETServer::startServerButtonHandler() {
    ui->statusText->appendPlainText("Starting Server.");
    //Set the path to the database
    QString dbLocation = "/Users/mrtaka79/COMP3004OmegaSquad/CETdb.sqlite";
    sqLite = new DatabaseHandler();
    const QFile sqlite_db(dbLocation);
    if(sqlite_db.exists()) {
        sqLite->openDB(dbLocation);
        ui->statusText->appendPlainText("Opening database.");
        //Start the server connection
    }
    else {
        //Don't start the server
        ui->statusText->appendPlainText("Cannot open database. Check path of database or if it exists.");
    }    
}

/*Stop server button handler*/
void CETServer::stopServerButtonHandler() {
    ui->statusText->appendPlainText("Stopping Server.");
    //Stop the server
    //Close the database
    sqLite->closeDB();
    ui->statusText->appendPlainText("Database closed.");
}

/*Press Exit in the menu*/
void CETServer::on_actionExit_triggered()
{
    //Close the database
    sqLite->closeDB();
    CETServer::close();
}
