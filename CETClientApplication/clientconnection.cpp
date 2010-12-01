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
  address = "192.168.0.145";
}

ClientConnection::~ClientConnection()
{
  client.close();
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
