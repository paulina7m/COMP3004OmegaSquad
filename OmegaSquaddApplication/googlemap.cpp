#include "googlemap.h"

GoogleMap::GoogleMap(QWidget *parent, QMainWindow *pwindow): QWebView(parent){
    this->pwindow = pwindow;
    mapWebPage = new QWebPage(this);
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

    connect(frame,
            SIGNAL(javaScriptWindowObjectCleared()),
            this,
            SLOT(addJavaScriptObject()));

    unitLocations = new QHash<QString, QString>;
    unitNames = new QHash<QString, QString>;
    setupHashMapsForLocations();
    setupIconsHash();

}


void GoogleMap::processMapAlert(QString name, QString id){
    QString thename = name;
    if(thename.isEmpty()){
        thename = unitNames->value(id);
    }
    emit mapItemClicked(thename, id);
}


void GoogleMap::mapTilesLoaded(){
    emit notifyMapTilesLoaded();
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

QString GoogleMap::getIconUrlForIndex(int index, QString level){
    int iconIndex = (index + 1) % 10;
    QString key;
    key.setNum(iconIndex);
    if(level == "low"){
        key.append("-1");
    } else if (level == "high"){
        key.append("1");
    } else {
        key.append("0");
    }
    return this->iconURLs->value(key);
}

void GoogleMap::updateIcons(int index, QList<QString>low, QList<QString> normal, QList<QString> high){
    QString indexString = "";
    indexString.setNum(index+1);

    QString scriptString;
    QString scriptString2;
    QString scriptString3;

    //update low quantity icons
    if(!low.isEmpty()){
        scriptString = "updateIcons(\"";
        QString iconurl = getIconUrlForIndex(index, "low");
        scriptString.append(iconurl+"\",[");
        for (int i = 0; i < low.size(); i++) {
            scriptString.append("marker"+low[i]+",");
        }
        scriptString = scriptString.mid(0,scriptString.lastIndexOf(","));
        scriptString.append("]);");
        qDebug() << scriptString;
    }
    //page()->mainFrame()->evaluateJavaScript(scriptString);

    //update normal quantity icons
    if(!normal.isEmpty()){
        scriptString2 = "updateIcons('";
        QString iconurl = getIconUrlForIndex(index, "normal");
        scriptString2.append(iconurl+"',[");
        for (int i = 0; i < normal.size(); i++) {
            scriptString2.append("marker"+normal[i]+",");
        }
        scriptString2 = scriptString2.mid(0,scriptString2.lastIndexOf(","));
        scriptString2.append("]);");
        qDebug() << scriptString2;
    }
    //page()->mainFrame()->evaluateJavaScript(scriptString2);

    //update high quantity icons
    if(!high.isEmpty()){
        scriptString3 = "updateIcons(\"";
        QString iconurl = getIconUrlForIndex(index, "high");

        scriptString3.append(iconurl+"\",\[");
        for (int i = 0; i < high.size(); i++) {
            scriptString3.append("marker"+high[i]+",");
        }
        scriptString3 = scriptString3.mid(0,scriptString3.lastIndexOf(","));
        scriptString3.append("]);");
        qDebug() << scriptString3;
    }
    if(!scriptString.isEmpty() || !scriptString2.isEmpty() || !scriptString3.isEmpty()){
        page()->mainFrame()->evaluateJavaScript("clearIcons();"+scriptString + scriptString2 + scriptString3);
    } else {
         page()->mainFrame()->evaluateJavaScript("clearIcons();");
    }


}

void GoogleMap::setupHashMapsForLocations(){
    //Territories
    unitLocations->insert("6201","66.23145747862573, -101.689453125");
    unitNames->insert("6201", "Nunavut");
    unitLocations->insert("6101", "65.07213008560697, -124.1015625");
    unitNames->insert("6101","Northwest Territories");
    unitLocations->insert("6001", "63.724183392123315, -135.5712890625");
    unitNames->insert("6001","Yukon");
    //British Columbia
    unitLocations->insert("5951", "57.70414723434193, -129.9462890625");
    unitNames->insert("5951","Northwest");
    unitLocations->insert("5952", "54.546579538405005, -124.013671875");
    unitNames->insert("5952","Northern Interior");
    unitLocations->insert("5933", "52.5897007687178, -126.2548828125");
    unitNames->insert("5933","North Shore/Coast Garibaldi");
    unitLocations->insert("5943", "51.20688339486559, -125.4638671875");
    unitNames->insert("5943","North Vancouver Island");
    unitLocations->insert("5942", "49.23912083246698, -124.98046875");
    unitNames->insert("5942","Central Vancouver Island");
    unitLocations->insert("5941", "48.574789910928864, -124.1455078125");
    unitNames->insert("5941","South Vancouver Island");
    unitLocations->insert("5922", "49.439556958940855, -122.6513671875");
    unitNames->insert("5922","Fraser North");
    unitLocations->insert("5921", "49.35375571830993, -121.6845703125");
    unitNames->insert("5921","Fraser East");
    unitLocations->insert("5914", "51.31688050404585, -121.728515625");
    unitNames->insert("5914","Thompson/Cariboo");
    unitLocations->insert("5913", "49.5822260446217, -119.9267578125");
    unitNames->insert("5913","Okanagan");
    unitLocations->insert("5912", "50.00773901463687, -117.5537109375");
    unitNames->insert("5912","Kootenay-Boundary");
    unitLocations->insert("5911", "49.837982453084834, -116.015625");
    unitNames->insert("5911","East Kootenay");
    unitLocations->insert("5923", "49.13859653703879, -122.904052734375");
    unitNames->insert("5923","Fraser South");
    unitLocations->insert("5931", "49.17452151806784, -123.101806640625");
    unitNames->insert("5931","Richmond");
    unitLocations->insert("5932", "49.26063518364422, -123.101806640625");
    unitNames->insert("5932","Vancouver");
    unitLocations->insert("5953", "56.559482483762245, -121.22314453125");
    unitNames->insert("5953","Northeast");
    //Alberta
    unitLocations->insert("4821", "49.5822260446217, -113.466796875");
    unitNames->insert("4821","Chinook Regional Health Authority");
    unitLocations->insert("4822", "50.56928286558243, -111.005859375");
    unitNames->insert("4822","Palliser Health Region");
    unitLocations->insert("4823", "50.792047064406866, -114.43359375");
    unitNames->insert("4823","Calgary Health Region");
    unitLocations->insert("4824", "52.29504228453735, -113.5546875");
    unitNames->insert("4824","David Thompson Regional Health Authority");
    unitLocations->insert("4825", "53.30462107510271, -111.8408203125");
    unitNames->insert("4825","East Central Health");
    unitLocations->insert("4826", "53.54030739150019, -113.6865234375");
    unitNames->insert("4826","Capital Health");
    unitLocations->insert("4827", "54.876606654108684, -113.642578125");
    unitNames->insert("4827","Aspen Regional Health Authority");
    unitLocations->insert("4828", "56.26776108757582, -117.24609375");
    unitNames->insert("4828","Peace Country Health");
    unitLocations->insert("4829", "58.63121664342478, -113.642578125");
    unitNames->insert("4829","Northern Lights Health Region");
    //Sasketchewan
    unitLocations->insert("4701", "49.468124067331644, -103.9306640625");
    unitNames->insert("4701","Sun Country Regional Health Authority");
    unitLocations->insert("4702", "50.17689812200107, -105.9521484375");
    unitNames->insert("4702","Five Hills Regional Health Authority");
    unitLocations->insert("4703", "49.89463439573421, -108.45703125");
    unitNames->insert("4703","Cypress Regional Health Authority");
    unitLocations->insert("4704", "50.792047064406866, -104.5458984375");
    unitNames->insert("4704","Regina Qu'Appelle Regional Health Authority");
    unitLocations->insert("4705", "51.72702815704774, -102.65625");
    unitNames->insert("4705","Sunrise Regional Health Authority");
    unitLocations->insert("4706", "52.1874047455997, -105.8203125");
    unitNames->insert("4706","Saskatoon Regional Health Authority");
    unitLocations->insert("4707", "51.80861475198521, -108.80859375");
    unitNames->insert("4707","Heartland Regional Health Authority");
    unitLocations->insert("4708", "53.330872983017066, -103.4912109375");
    unitNames->insert("4708","Kelsey Trail Regional Health Authority");
    unitLocations->insert("4709", "53.56641415275043, -106.5673828125");
    unitNames->insert("4709","Prince Albert Parkland Regional Health Authority");
    unitLocations->insert("4710", "53.64463782485651, -109.0283203125");
    unitNames->insert("4710","Prairie North Regional Health Authority");
    unitLocations->insert("4711", "56.728621973140726, -104.2822265625");
    unitNames->insert("4711","Mamawetan Churchill River Regional Health Authority");
    unitLocations->insert("4712", "56.80087831233043, -108.369140625");
    unitNames->insert("4712","Keewatin Yatth? Regional Health Authority");
    unitLocations->insert("4713", "59.512029386502704, -106.34765625");
    unitNames->insert("4713","Athabasca Health Authority");
    //Manitoba
    unitLocations->insert("4610", "49.866316729538674, -97.1630859375");
    unitNames->insert("4610","Winnipeg Regional Health Authority");
    unitLocations->insert("4615", "49.809631563563094, -100.01953125");
    unitNames->insert("4615","Brandon Regional Health Authority");
    unitLocations->insert("4620", "51.72702815704774, -96.064453125");
    unitNames->insert("4620","North Eastman Regional Health Authority");
    unitLocations->insert("4625", "49.210420445650286, -96.5478515625");
    unitNames->insert("4625","South Eastman Regional Health Authority");
    unitLocations->insert("4630", "52.53627304145948, -97.9541015625");
    unitNames->insert("4630","Interlake Regional Health Authority");
    unitLocations->insert("4640", "49.49667452747044, -97.998046875");
    unitNames->insert("4640","Central Regional Health Authority");
    unitLocations->insert("4645", "50.45750402042058, -100.5908203125");
    unitNames->insert("4645","Assiniboine Regional Health Authority");
    unitLocations->insert("4660", "52.26815737376817, -100.4150390625");
    unitNames->insert("4660","Parkland Regional Health Authority");
    unitLocations->insert("4670", "54.265224078605655, -100.6787109375");
    unitNames->insert("4670","Norman Regional Health Authority");
    unitLocations->insert("4680", "56.75272287205736, -96.2841796875");
    unitNames->insert("4680"," Burntwood Regional Health Authority");
    unitLocations->insert("4690", "58.75110666755426, -94.119873046875");
    unitNames->insert("4690","Churchill Regional Health Authority");
    //Ontario
    unitLocations->insert("3501", "42.5530802889558, -82.2216796875");
    unitNames->insert("3501","Erie St. Clair");
    unitLocations->insert("3502", "43.35713822211053, -81.3427734375");
    unitNames->insert("3502","South West");
    unitLocations->insert("3503", "43.67581809328341, -80.4638671875");
    unitNames->insert("3503","Waterloo Wellington");
    unitLocations->insert("3504", "43.004647127794435, -79.98046875");
    unitNames->insert("3504","Hamilton Niagara Haldimand Brant");
    unitLocations->insert("3505", "44.024421519659334, -80.2001953125");
    unitNames->insert("3505","Central West");
    unitLocations->insert("3506", "43.58039085560784, -79.892578125");
    unitNames->insert("3506","Mississauga Halton");
    unitLocations->insert("3507", "43.644025847699496, -79.365234375");
    unitNames->insert("3507","Toronto Central");
    unitLocations->insert("3508", "44.024421519659334, -79.541015625");
    unitNames->insert("3508","Central");
    unitLocations->insert("3509", "44.59046718130883, -78.7939453125");
    unitNames->insert("3509","Central East");
    unitLocations->insert("3510", "44.77793589631623, -76.9482421875");
    unitNames->insert("3510","South East");
    unitLocations->insert("3511", "45.213003555993964, -75.322265625");
    unitNames->insert("3511","Champlain");
    unitLocations->insert("3512", "44.809121700077355, -79.62890625");
    unitNames->insert("3512","North Simcoe Muskoka");
    unitLocations->insert("3513", "50.98609893339354, -82.3974609375");
    unitNames->insert("3513","North East");
    unitLocations->insert("3514", "51.944264879028765, -89.7802734375");
    unitNames->insert("3514","North West");
    //Quebec
    unitLocations->insert("2401", "48.10743118848038, -68.7744140625");
    unitNames->insert("2401","Region du Bas-Saint-Laurent");
    unitLocations->insert("2402", "49.66762782262194, -72.31201171875");
    unitNames->insert("2402","Region du Saguenay Lac-Saint-Jean");
    unitLocations->insert("2403", "47.30903424774781, -71.34521484375");
    unitNames->insert("2403","Region de la Capitale Nationale");
    unitLocations->insert("2404", "46.164614496897094, -72.333984375");
    unitNames->insert("2404","Region de la Mauricie et du Centre-du-Quebec");
    unitLocations->insert("2405", "45.30580259943578, -71.6748046875");
    unitNames->insert("2405","Region de l'Estrie");
    unitLocations->insert("2406", "45.483243508682186, -73.67431640625");
    unitNames->insert("2406","Region de Montreal");
    unitLocations->insert("2407", "46.558860303117164, -76.8603515625");
    unitNames->insert("2407"," Region de l'Outaouais");
    unitLocations->insert("2408", "47.90161354142075, -77.8271484375");
    unitNames->insert("2408"," Region de l'Abitibi-Temiscamingue");
    unitLocations->insert("2409", "49.49667452747044, -63.10546875");
    unitNames->insert("2409","Region de la Cete-Nord");
    unitLocations->insert("2410", "52.29504228453735, -75.146484375");
    unitNames->insert("2410","Region du Nord-du-Quebec");
    unitLocations->insert("2411", "48.74894534343293, -65.0830078125");
    unitNames->insert("2411","Region de la Gaspesieeles-de-la-Madeleine");
    unitLocations->insert("2412", "46.52863469527167, -70.7080078125");
    unitNames->insert("2412","Region de la Chaudiere-Appalaches");
    unitLocations->insert("2413", "45.637087095718734, -73.729248046875");
    unitNames->insert("2413","Region de Laval");
    unitLocations->insert("2414", "46.52863469527167, -73.916015625");
    unitNames->insert("2414","Region de Lanaudiere");
    unitLocations->insert("2415", "46.800059446787316, -75.0146484375");
    unitNames->insert("2415","Region des Laurentides");
    unitLocations->insert("2416", "45.55252525134013, -72.7734375");
    unitNames->insert("2416","Region de la Monteregie");
    unitLocations->insert("2417", "57.468589192089325, -71.630859375");
    unitNames->insert("2417","Region du Nunavik");
    unitLocations->insert("2418", "51.37178037591737, -78.7060546875");
    unitNames->insert("2418","Region des Terres-Cries-de-la-Baie-James");
    //New Brunswick
    unitLocations->insert("1301", "46.46813299215554, -65.0390625");
    unitNames->insert("1301","Region 1");
    unitLocations->insert("1302", "45.706179285330855, -65.7421875");
    unitNames->insert("1302","Region 2");
    unitLocations->insert("1303", "46.255846818480315, -67.0166015625");
    unitNames->insert("1303","Region 3");
    unitLocations->insert("1304", "47.60616304386874, -67.8076171875");
    unitNames->insert("1304","Region 4");
    unitLocations->insert("1305", "47.81315451752768, -66.4892578125");
    unitNames->insert("1305","Region 5");
    unitLocations->insert("1306", "47.57652571374621, -65.6103515625");
    unitNames->insert("1306","Region 6");
    unitLocations->insert("1307", "47.10004469402519, -66.0498046875");
    unitNames->insert("1307","Region 7");
    //Nova Scotia
    unitLocations->insert("1211", "44.402391829093915, -64.775390625");
    unitNames->insert("1211","DHA 1");
    unitLocations->insert("1212", "44.08758502824516, -65.7861328125");
    unitNames->insert("1212","DHA 2");
    unitLocations->insert("1213", "44.87144275016589, -65.126953125");
    unitNames->insert("1213","DHA 3");
    unitLocations->insert("1214", "45.336701909968106, -63.45703125");
    unitNames->insert("1214","DHA 4");
    unitLocations->insert("1215", "45.73685954736049, -64.0283203125");
    unitNames->insert("1215","DHA 5");
    unitLocations->insert("1216", "45.55252525134013, -62.490234375");
    unitNames->insert("1216","DHA 6");
    unitLocations->insert("1217", "45.49094569262732, -61.787109375");
    unitNames->insert("1217","DHA 7");
    unitLocations->insert("1218", "46.042735653846506, -60.3369140625");
    unitNames->insert("1218","DHA 8");
    unitLocations->insert("1219", "44.87144275016589, -63.28125");
    unitNames->insert("1219","DHA 9");
    //Prince Edward Island
    unitLocations->insert("1101", "46.37725420510028, -62.5341796875");
    unitNames->insert("1101","Kings County");
    unitLocations->insert("1102", "46.34692761055676, -63.193359375");
    unitNames->insert("1102","Queens County");
    unitLocations->insert("1103", "46.46813299215554, -63.9404296875");
    unitNames->insert("1103","Prince County");
    //Newfoundland and Labrador
    unitLocations->insert("1011", "47.96050238891509, -54.2724609375");
    unitNames->insert("1011","Eastern Regional Integrated Health Authority");
    unitLocations->insert("1012", "48.80686346108517, -55.7666015625");
    unitNames->insert("1012","Central Regional Integrated Health Authority");
    unitLocations->insert("1013", "49.23912083246698, -57.65625");
    unitNames->insert("1013","Western Regional Integrated Health Authority");
    unitLocations->insert("1014", "54.00776876193478, -61.34765625");
    unitNames->insert("1014","Labrador-Grenfell Regional Integrated Health Authority");
}


void GoogleMap::setupIconsHash(){
    iconURLs = new QHash<QString, QString>;
    iconURLs->insert("1-1","http://paulinamasson.com/attachments/kml/1red-1.png");
    iconURLs->insert("10","http://paulinamasson.com/attachments/kml/1red0.png");
    iconURLs->insert("11","http://paulinamasson.com/attachments/kml/1red1.png");
    iconURLs->insert("2-1","http://paulinamasson.com/attachments/kml/2house-1.png");
    iconURLs->insert("20","http://paulinamasson.com/attachments/kml/2house0.png");
    iconURLs->insert("21","http://paulinamasson.com/attachments/kml/2house1.png");
    iconURLs->insert("3-1","http://paulinamasson.com/attachments/kml/3tree-1.png");
    iconURLs->insert("30","http://paulinamasson.com/attachments/kml/3tree0.png");
    iconURLs->insert("31","http://paulinamasson.com/attachments/kml/3tree1.png");
    iconURLs->insert("4-1","http://paulinamasson.com/attachments/kml/4bed-1.png");
    iconURLs->insert("40","http://paulinamasson.com/attachments/kml/4bed0.png");
    iconURLs->insert("41","http://paulinamasson.com/attachments/kml/4bed1.png");
    iconURLs->insert("5-1","http://paulinamasson.com/attachments/kml/5letterr-1.png");
    iconURLs->insert("50","http://paulinamasson.com/attachments/kml/5letterr0.png");
    iconURLs->insert("51","http://paulinamasson.com/attachments/kml/5letterr1.png");
    iconURLs->insert("6-1","http://paulinamasson.com/attachments/kml/6fish-1.png");
    iconURLs->insert("60","http://paulinamasson.com/attachments/kml/6fish0.png");
    iconURLs->insert("61","http://paulinamasson.com/attachments/kml/6fish1.png");
    iconURLs->insert("7-1","http://paulinamasson.com/attachments/kml/7hbed-1.png");
    iconURLs->insert("70","http://paulinamasson.com/attachments/kml/7hbed0.png");
    iconURLs->insert("71","http://paulinamasson.com/attachments/kml/7hbed1.png");
    iconURLs->insert("8-1","http://paulinamasson.com/attachments/kml/8purple-1.png");
    iconURLs->insert("80","http://paulinamasson.com/attachments/kml/8purple0.png");
    iconURLs->insert("81","http://paulinamasson.com/attachments/kml/8purple1.png");
    iconURLs->insert("9-1","http://paulinamasson.com/attachments/kml/9green-1.png");
    iconURLs->insert("90","http://paulinamasson.com/attachments/kml/9green0.png");
    iconURLs->insert("91","http://paulinamasson.com/attachments/kml/9green1.png");
    iconURLs->insert("10-1","http://paulinamasson.com/attachments/kml/10orange-1.png");
    iconURLs->insert("100","http://paulinamasson.com/attachments/kml/10orange0.png");
    iconURLs->insert("101","http://paulinamasson.com/attachments/kml/10orange1.png");
}
