#-------------------------------------------------
#
# Project created by QtCreator 2010-11-23T20:24:23
#
#-------------------------------------------------

QT       += core
QT       += xml
QT       -= gui

TARGET = CETClientApplication
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    User.cpp \
    SupplyType.cpp \
    ShipmentDetail.cpp \
    Shipment.cpp \
    Region.cpp \
    Province.cpp \
    Inventory.cpp \
    DiseaseType.cpp \
    DataHandler.cpp \
    CaseReport.cpp

HEADERS += \
    User.h \
    SupplyType.h \
    ShipmentDetail.h \
    Shipment.h \
    Region.h \
    Province.h \
    Inventory.h \
    DiseaseType.h \
    DataHandler.h \
    CaseReport.h
