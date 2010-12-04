#include "clientconnection.h"
#include "stdio.h"
#include <QHostAddress>
#include <iostream>

using namespace std;

ClientConnection::ClientConnection(QObject* parent): QObject(parent)
{
    //chunked = true;
    connect(&client, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(&client,SIGNAL(readyRead()),this,SLOT(readMessage()));


    /*
    QString filename = "config.cet";
    QFile file;
    file.setFileName(filename);
    if(!file.exists()) //if file does not exist
    {
        address = "127.0.0.1";
    }
    else { //if file does exist open for reading

        if (file.open(QIODevice::ReadOnly)) {
            address = file.readAll();
        }
        //qDebug() << ipAddress;

    }
    file.close();
    //qDebug() << address;
    */

    address = "127.0.0.1";
}

ClientConnection::~ClientConnection()
{
    client.close();
}

bool ClientConnection::connectionOpen() {
    QHostAddress addr(address);
    test.connectToHost(addr,6789);
    bool connected = false;
    if(test.waitForConnected(300))
    {
        connected = true;
    }else{
        connected = false;
    }
    test.close();
    return connected;
}

void ClientConnection::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    client.connectToHost(addr,port);
}

void ClientConnection::startTransfer()
{

    //client.write(xmlRequest.toAscii(),xmlRequest.length()+1);
    //client.write("<?xml version=\"1.0\"?><message><command>getIdNumbers</command><getIdNumbersRequest><blockSize>10</blockSize></getIdNumbersRequest></message>",1024);

}
QString ClientConnection::getAddress()
{
    return address;
}
void ClientConnection::setAddress(QString addr){
    address = addr;
}


QString ClientConnection::sendRequest(QString xmlReq)
{

    this->xmlRequest = xmlReq;

    QHostAddress addr(address);

    xmlReply = "";

    client.connectToHost(addr,6789);

    if(client.waitForConnected(30000))
    {
        client.write(xmlRequest.toAscii(),xmlRequest.length()+1);
    }else{
        xmlReply = "<message>Server Connection Timeout</message>";
    }

    char message[30000] = {0};





    //should loop through, appendign newly received parts from the tcp socket
    //and stuff
    while(!(xmlReply.contains("</message>")))
    {
        if(client.waitForReadyRead(3000)){

            client.read(message,30000);

            xmlReply += (QString)message;
            usleep(3000);

        }else{
            xmlReply = "<message>Server Response Timeout</message>";
        }
    }

    client.close();

    return xmlReply;

}

void ClientConnection::readMessage()
{
    /*
    char message[1024] = {0};


    client.read(message,client.bytesAvailable());
    cout<<message<<endl;

    xmlReply = (QString) message;
    freshMessage = true;

    client.close();
*/
}
