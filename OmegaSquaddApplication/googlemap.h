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


public Q_SLOTS:
    void processMapAlert(QString name, QString id);

public:
    explicit GoogleMap(QWidget *parent = 0, QMainWindow *pwindow = 0);


signals:
    void mapItemClicked(QString name, QString id, QString value);

public slots:


private slots:
    void setCenter(qreal latitude, qreal longitude);
    void addJavaScriptObject();



};

#endif // GOOGLEMAP_H
