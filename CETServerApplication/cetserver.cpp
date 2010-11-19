#include "cetserver.h"
#include "ui_cetserver.h"
#include <QDebug>
#include <QFile>

CETServer::CETServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CETServer)
{
    ui->setupUi(this);
    ui->stopServerButton->setEnabled(false);

    /* CONNECT TO THE DATABASE */
    //Set the path to the database
    QString dbLocation = "/Users/mrtaka79/COMP3004OmegaSquad/CETdb.sqlite";
    QString dbType = "QSQLITE";
    QString dbHostName = "hostname";
    sqLite = new DatabaseHandler();
    //Check if the db file exists
    const QFile sqlite_db(dbLocation);
    if(sqlite_db.exists() && sqLite->openDB(dbType, dbLocation, dbHostName)) {
        ui->statusText->appendHtml("<br>Opening database.<br>");
    }
    else {
        ui->startServerButton->setEnabled(false);
        //Don't start the server
        ui->statusText->appendPlainText("Cannot open database. Check path of database or if it exists.");
    }
    /* END CONNECT TO DATABASE */
}

CETServer::~CETServer()
{
    //Close the database connections and delete instance
    sqLite->closeDB();
    delete sqLite;
    delete ui;
}

/*Start server button handler*/
void CETServer::startServerButtonHandler() {
    ui->statusText->appendHtml("<br>Starting Server.<br>");
    ui->stopServerButton->setEnabled(true);
    ui->startServerButton->setEnabled(false);
    //Start the server connection

    //This is a test query
    //QString List = sqLite->queryDatabase("<message><command>findEntities</command><findEntitiesRequest type=\"Province\"></findEntitiesRequest></message>");
    //ui->statusText->appendPlainText(List);

}

/*Stop server button handler*/
void CETServer::stopServerButtonHandler() {
    ui->statusText->appendHtml("<br>Stopping Server.<br>");

    ui->stopServerButton->setEnabled(false);
    ui->startServerButton->setEnabled(true);
}

/*Press Exit in the menu*/
void CETServer::on_actionExit_triggered()
{
    CETServer::close();
}
