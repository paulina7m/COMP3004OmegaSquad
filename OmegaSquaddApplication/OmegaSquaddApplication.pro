#-------------------------------------------------
#
# Project created by QtCreator 2010-11-12T23:53:46
#
#-------------------------------------------------

QT       += core gui webkit network xml sql

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
    ../CETClientApplication/Province.cpp \
    ../CETClientApplication/Inventory.cpp \
    ../CETClientApplication/DiseaseType.cpp \
    ../CETClientApplication/DataHandler.cpp \
    ../CETClientApplication/clientconnection.cpp \
    ../CETClientApplication/CaseReport.cpp \
    updatecasereport.cpp \
    updateinventory.cpp \
    ../CETClientApplication/Region1.cpp \
    configurecet.cpp


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
    ../CETClientApplication/Shipment.h \
    ../CETClientApplication/ShipmentDetail.h \
    ../CETClientApplication/SupplyType.h \
    ../CETClientApplication/User.h \
    updatecasereport.h \
    updateinventory.h \
    ../CETClientApplication/Region1.h \
    configurecet.h


FORMS    += mainwindow.ui \
    aboutCET.ui \
    adddiseaseswindow.ui \
    addsupplieswindow.ui \
    createshipmentswindow.ui \
    managetheshipmentswindow.ui \
    viewthediseaseswindow.ui \
    viewthesupplieswindow.ui \
    updatecasereport.ui \
    updateinventory.ui \
    configurecet.ui

RESOURCES += \
    mapDefinitionFile.qrc

OTHER_FILES += \
    mapDefinition.html \
    CET.png
