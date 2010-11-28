#include "googlemap.h"

    GoogleMap::GoogleMap(QWidget *parent, QMainWindow *pwindow): QWebView(parent){
        this->pwindow = pwindow;
        mapWebPage = new QWebPage(this);
        message = "this is it. m jackson.";
        //read map definition, html file
        QFile file;
        file.setFileName(":/mapDefinition.html");
        file.open(QIODevice::ReadOnly);
        mapHTML = file.readAll();
        file.close();

        QWebFrame *frame = page()->mainFrame();
        frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
        frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
        frame->setHtml(mapHTML);
        frame = mapWebPage->mainFrame();
        frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
        frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
        frame->setHtml(mapHTML);

//        message = "testing message";
        connect(frame,
                   SIGNAL(javaScriptWindowObjectCleared()),
                   this,
                   SLOT(addJavaScriptObject()));

//        connect(frame,
//                   SIGNAL(javaScriptAlert(QWebPage, QString)),
//                   this,
//                   SLOT(processMapAlert(QWebPage, QString)));



    }


    void GoogleMap::setCenter(qreal latitude, qreal longitude) {
            QString code = "map.set_center(new google.maps.LatLng(%1, %2));";
            QWebFrame *frame = page()->mainFrame();
            frame->evaluateJavaScript(code.arg(latitude).arg(longitude));
            frame = mapWebPage->mainFrame();
            frame->evaluateJavaScript(code.arg(latitude).arg(longitude));
     }



    void GoogleMap::processMapAlert(QString name, QString id){
      // QStringList  scriptStr;


        emit mapItemClicked(name, id, name);

      // scriptStr
      //          << "for( var i=0; i<markers.length; ++i ) {"
        //        << "   bounds.extend(markers[i].getPoint());"
          //      << "   map.addOverlay(markers[i]);"
            //    <<    "}"
              //  <<    "map.setCenter(bounds.getCenter());";


        //this->page()->mainFrame()->evaluateJavaScript( scriptStr.join("\n") );

    }


    void QWebPage::javaScriptAlert ( QWebFrame * frame, const QString & msg ){
        qDebug() << "Event received!!!!:" << msg;

    }


    void GoogleMap::addJavaScriptObject()
    {
        const QString name = "GoogleMapObjectInQ";
        this->page()->mainFrame()
                         ->addToJavaScriptWindowObject(name,
                                                       this);
    }
