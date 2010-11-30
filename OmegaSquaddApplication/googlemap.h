#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include <QDebug>


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
    void updateIcons(int index);

signals:
    void mapItemClicked(QString name, QString id);
    void notifyMapTilesLoaded();

public slots:


private slots:
    void setCenter(qreal latitude, qreal longitude);
    void addJavaScriptObject();

};

#endif // GOOGLEMAP_H
