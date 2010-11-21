#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>


class GoogleMap : public QWebView
{
    Q_OBJECT

private:
    QWebPage *zoomPage;

public:
    explicit GoogleMap(QWidget *parent = 0);


signals:

public slots:

private slots:
    void setCenter(qreal latitude, qreal longitude);




};

#endif // GOOGLEMAP_H
