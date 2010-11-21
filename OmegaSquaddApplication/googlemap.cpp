#include "googlemap.h"

#define MAP_HTML "<html xmlns=\"http://www.w3.org/1999/xhtml\">" \
      "<head>" \
        "<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>" \
        "<title>The Canadian Epidemics Tracker Map</title>" \
        "<script src=\"http://maps.google.com/maps?file=api&amp;v=2&amp;sensor=false&amp;key=ABQIAAAA19_FHK__lxCbVQEWBDCrZRS07ISVuDu6rafx1guXYWrGRDe03BRevP0Sf2SaJEOpZK-3RBCzzUxsyg\"" \
        "type=\"text/javascript\"></script>" \
        "<script type=\"text/javascript\">" \
        "function initialize() {" \
            "var map = new GMap2(document.getElementById(\"map_canvas\"));" \
            "var geoXmlbritishcolumbia = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/britishcolumbia.kml\");" \
            "var geoXmlalberta = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/alberta12.kml\");" \
            "var geoXmlsaskatchewan = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/saskatchewan.kml\");" \
            "var geoXmlmanitoba = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/manitoba.kml\");" \
            "var geoXmlontariohealthunits = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/ontariohealthunits.kml\");" \
            "var geoXmlquebec = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/quebec.kml\");" \
            "var geoXmllabrador = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/labrador.kml\");" \
            "var geoXmlprinceedward = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/princeedward.kml\");" \
            "var geoXmlnovascotiazones = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/novascotiazones.kml\");" \
            "var geoXmlnewbrunswick = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/newbrunswick.kml\");" \
            "var geoXmlterritories = new GGeoXml(\"http://www.paulinamasson.com/attachments/kml/territories.kml\");" \
            "map.setCenter(new GLatLng(61.438767,-103.183594), 3);" \
            "map.setUIToDefault();" \
            "map.addOverlay(geoXmlbritishcolumbia);" \
            "map.addOverlay(geoXmlalberta);" \
            "map.addOverlay(geoXmlsaskatchewan);" \
            "map.addOverlay(geoXmlmanitoba);" \
            "map.addOverlay(geoXmlontariohealthunits);" \
            "map.addOverlay(geoXmlquebec);" \
            "map.addOverlay(geoXmllabrador);" \
            "map.addOverlay(geoXmlnovascotiazones);" \
            "map.addOverlay(geoXmlprinceedward);" \
            "map.addOverlay(geoXmlnewbrunswick);" \
            "map.addOverlay(geoXmlterritories);" \
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


