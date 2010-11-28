#-------------------------------------------------
#
# Project created by QtCreator 2010-11-12T23:53:46
#
#-------------------------------------------------

QT       += core gui webkit network

TARGET = OmegaSquaddApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    googlemap.cpp \ 
    aboutCET.cpp


HEADERS  += mainwindow.h \
    googlemap.h \ 
    aboutCET.h


FORMS    += mainwindow.ui \
    aboutCET.ui

RESOURCES += \
    mapDefinitionFile.qrc
