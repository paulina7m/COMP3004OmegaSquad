#include "googlemap.h"

#define MAP_HTML "<html xmlns=\"http://www.w3.org/1999/xhtml\">" \
      "<head>" \
        "<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>" \
        "<title>The Canadian Epidemics Tracker Map</title>" \
        "<script src=\"http://maps.google.com/maps?file=api&amp;v=2&amp;key=abcdefg&sensor=true_or_false\"" \
        "type=\"text/javascript\"></script>" \
        "<script type=\"text/javascript\">" \
        "function initialize() {" \
          "if (GBrowserIsCompatible()) {" \
            "var map = new GMap2(document.getElementById(\"map_canvas\"));" \
            "map.setCenter(new GLatLng(60.930432,-95.800781), 3);" \
            "map.setUIToDefault();" \
          "}" \
        "}" \
        "</script>" \
      "</head>" \
      "<body onload=\"initialize()\" onunload=\"GUnload()\">" \
        "<div id=\"map_canvas\" style=\"width: 765px; height: 445px\"></div>" \
      "</body>" \
    "</html>"

    GoogleMap::GoogleMap(QWidget *parent): QWebView(parent){
        zoomPage = new QWebPage(this);
        QString content = MAP_HTML;
        QWebFrame *frame = page()->mainFrame();
        frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
        frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
        frame->setHtml(content);
        frame = zoomPage->mainFrame();
        frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
        frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
        frame->setHtml(content);

    }


    void GoogleMap::setCenter(qreal latitude, qreal longitude) {
            QString code = "map.set_center(new google.maps.LatLng(%1, %2));";
            QWebFrame *frame = page()->mainFrame();
            frame->evaluateJavaScript(code.arg(latitude).arg(longitude));
            frame = zoomPage->mainFrame();
            frame->evaluateJavaScript(code.arg(latitude).arg(longitude));
     }


