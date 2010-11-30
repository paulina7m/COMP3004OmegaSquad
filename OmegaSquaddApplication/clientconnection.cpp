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
  address = "127.0.0.1";
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
    client.connectToHost(addr,6789);

    if(client.waitForConnected(30000)){
        client.write(xmlRequest.toAscii(),xmlRequest.length()+1);
    }

    char message[1024] = {0};

    if(client.waitForReadyRead(30000)){


        client.read(message,client.bytesAvailable());

        client.close();
    }else{
        xmlReply = "Server Timeout";
    }

    xmlReply = (QString) message;

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


