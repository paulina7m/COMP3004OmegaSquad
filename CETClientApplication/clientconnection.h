#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <QtNetwork>
#include <QtCore>

class ClientConnection: public QObject
{
Q_OBJECT
public:
  ClientConnection(QObject* parent = 0);
  //Client(QString, QObject* parent = 0);
  ~ClientConnection();

  void start(QString address, quint16 port);
  QString sendRequest(QString);
  void setAddress(QString);
  QString getAddress();
  bool connectionOpen();

public slots:
  void startTransfer();
  void readMessage();
private:

  QString address;
  QTcpSocket client;
  QTcpSocket test;
  bool freshMessage;
  QString xmlReply;
  QString xmlRequest;
};


#endif // CLIENTCONNECTION_H
