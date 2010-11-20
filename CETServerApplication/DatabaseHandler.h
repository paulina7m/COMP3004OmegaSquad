#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
#include <QSqlQuery>
#include <QString>
#include <QList>

/*
The following must be added to the .pro file
QT += sql
QT += xml
*/

class DatabaseHandler
{
  public:
    //Opens the database with the database path/name of db passed
    bool openDB(QString, QString, QString);

    QString queryDatabase(QString xmlString);

    QString findEntities(QString xmlString);

    //Save Entities (create entities)
    //NOTE: The client must request id numbers first, get a reply, then attach the id numbers to an object
    //Send bool back to Server Message class
    QString saveEntities(QString xmlString);

    //Get login information
    //Send status string back to Server Message class
    QString checkLogin(QString xmlString);

    //Get ID Numbers (for when creating entities)
    QString getIdNumbers(QString xmlString);

    void closeDB();
  private:
    QString xmlReply;
    QString queryString;
    QString entityType;
    QString blockSize;
    QString escapeString;
    QSqlDatabase db;
    int maxId;
};

#endif // DATABASEHANDLER_H
