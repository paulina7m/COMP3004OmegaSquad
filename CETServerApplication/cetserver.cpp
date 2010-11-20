#include "cetserver.h"
#include "ui_cetserver.h"
#include <QDebug>
#include <QFile>
#include <QtXml/QDomDocument>

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
        ui->statusText->appendHtml("<b style=\"color:'green'\">Opening database.</b>");
    }
    else {
        ui->startServerButton->setEnabled(false);
        //Don't start the server
        ui->statusText->appendPlainText("<b style=\"color:'red'\">Database file not found. Check paths.</b>");
    }
    /* END CONNECT TO DATABASE */
}

//Destructor
CETServer::~CETServer()
{
    //Close the database connections and delete instance
    sqLite->closeDB();
    delete sqLite;
    delete ui;
}

/*Start server button handler*/
void CETServer::startServerButtonHandler() {
    ui->statusText->appendHtml("<b style=\"color:'green'\">Starting Server.</b>");
    ui->stopServerButton->setEnabled(true);
    ui->startServerButton->setEnabled(false);
    //Start the server connection here

    /*
    //These are test queries
    //Test 1
    QString List = sqLite->queryDatabase("<message<command>findEntities</command><findEntitiesRequest type=\"Province\"></findEntitiesRequest></message>");
    this->commandStatus(List);

    //Test2
    QString List = sqLite->queryDatabase("<message><command>findEntities</command><findEntitiesRequest type=\"Region\"></findEntitiesRequest></message>");
    qDebug() << List;
    ui->statusText->appendPlainText(List);
    */

}

/*Stop server button handler*/
void CETServer::stopServerButtonHandler() {
    ui->statusText->appendHtml("-----<br><b style=\"color:'red'\">Stopping Server.</b>");

    ui->stopServerButton->setEnabled(false);
    ui->startServerButton->setEnabled(true);
}

/*Press Exit in the menubar*/
void CETServer::on_actionExit_triggered()
{
    CETServer::close();
}

//Outputs the command and its request status in the text area
//after queryingDatabase (optional use)
void CETServer::commandStatus(QString xmlString) {
    if (xmlString != "") {
        //Parse the xml string
        //The name of the xml document
        QDomDocument doc("xmldocument");
        if (doc.setContent(xmlString)) {
            //Get the root element
            QDomElement root = doc.documentElement();
            QDomNode n = root.firstChild();
            if(!n.isNull()) {
                QDomElement e = n.toElement();
                QDomNode f = n.nextSibling();
                QDomElement m = f.toElement();
                QString message = "-----<br>Command: ";
                message.append(e.text());
                message.append("<br>Status: ");
                message.append(m.text());
                if (e.tagName() == "command" && e.text() == "findEntities") {
                    ui->statusText->appendHtml(message);
                }
                else if (e.tagName() == "command" && e.text() == "saveEntities") {
                    ui->statusText->appendHtml(message);
                }
                else if (e.tagName() == "command" && e.text() == "getIdNumbers") {
                    ui->statusText->appendHtml(message);
                }
                else if (e.tagName() == "command" && e.text() == "login") {
                    ui->statusText->appendHtml(message);
                }
                else {
                    ui->statusText->appendHtml("-----<br>Command: Querying database");
                    ui->statusText->appendHtml("Status: Bad Request");
                }
            }
        }
        else {
            ui->statusText->appendHtml("-----<br>Command: Querying database");
            ui->statusText->appendHtml("Status: Bad Request");
        }
    }
    else {
        ui->statusText->appendHtml("-----<br>Command: Querying database");
        ui->statusText->appendHtml("Status: String malformed");
    }
}
