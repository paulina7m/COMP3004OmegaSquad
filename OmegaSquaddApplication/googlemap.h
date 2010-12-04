#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

//#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include <QDebug>
#include "../CETClientApplication/DataHandler.h"


class GoogleMap : public QWebView
{
    Q_OBJECT

private:
    QString mapHTML;
    QNetworkAccessManager *manager;
    QWebPage *mapWebPage;
    QString message;
    QMainWindow *pwindow;
    QHash<QString, QString> *unitLocations;
    QHash<QString, QString> *unitNames;
    QHash<QString, QString> *iconURLs;
    void setupIconsHash();

private:
    void setupHashMapsForLocations();

public Q_SLOTS:
    void processMapAlert(QString name, QString id);
    void mapTilesLoaded();

public:
    explicit GoogleMap(QWidget *parent = 0, QMainWindow *pwindow = 0);
    void updateIcons(int index, QList<QString>low, QList<QString> normal, QList<QString> high);
    QString getIconUrlForIndex(int index, QString level);

signals:
    void mapItemClicked(QString name, QString id);
    void notifyMapTilesLoaded();

public slots:


private slots:
    void addJavaScriptObject();

};

#endif // GOOGLEMAP_H
