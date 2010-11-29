#-------------------------------------------------
#
# Project created by QtCreator 2010-11-12T23:53:46
#
#-------------------------------------------------

QT       += core gui webkit network xml

TARGET = OmegaSquaddApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    googlemap.cpp \ 
    aboutCET.cpp \
    adddiseaseswindow.cpp \
    addsupplieswindow.cpp \
    createshipmentswindow.cpp \
    managetheshipmentswindow.cpp \
    viewthediseaseswindow.cpp \
    viewthesupplieswindow.cpp \
    ../CETClientApplication/User.cpp \
    ../CETClientApplication/SupplyType.cpp \
    ../CETClientApplication/ShipmentDetail.cpp \
    ../CETClientApplication/Shipment.cpp \
    ../CETClientApplication/Region.cpp \
    ../CETClientApplication/Province.cpp \
    ../CETClientApplication/Inventory.cpp \
    ../CETClientApplication/DiseaseType.cpp \
    ../CETClientApplication/DataHandler.cpp \
    ../CETClientApplication/clientconnection.cpp \
    ../CETClientApplication/CaseReport.cpp


HEADERS  += mainwindow.h \
    googlemap.h \ 
    aboutCET.h \
    adddiseaseswindow.h \
    addsupplieswindow.h \
    createshipmentswindow.h \
    managetheshipmentswindow.h \
    viewthediseaseswindow.h \
    viewthesupplieswindow.h \
    ../CETClientApplication/clientconnection.h \
    ../CETClientApplication/CaseReport.h \
    viewthesupplieswindow.h \
    viewthediseaseswindow.h \
    managetheshipmentswindow.h \
    mainwindow.h \
    googlemap.h \
    createshipmentswindow.h \
    addsupplieswindow.h \
    ../CETClientApplication/DataHandler.h \
    ../CETClientApplication/DiseaseType.h \
    ../CETClientApplication/Inventory.h \
    ../CETClientApplication/Province.h \
    ../CETClientApplication/Region.h \
    ../CETClientApplication/Shipment.h \
    ../CETClientApplication/ShipmentDetail.h \
    ../CETClientApplication/SupplyType.h \
    ../CETClientApplication/User.h


FORMS    += mainwindow.ui \
    aboutCET.ui \
    adddiseaseswindow.ui \
    addsupplieswindow.ui \
    createshipmentswindow.ui \
    managetheshipmentswindow.ui \
    viewthediseaseswindow.ui \
    viewthesupplieswindow.ui

RESOURCES += \
    mapDefinitionFile.qrc

OTHER_FILES += \
    mapDefinition.html
