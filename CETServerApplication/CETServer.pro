#-------------------------------------------------
#
# Project created by QtCreator 2010-11-18T22:59:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xml
QT 		 += network

TARGET = CETServer
TEMPLATE = app


SOURCES += main.cpp\
        cetserver.cpp \
    DatabaseHandler.cpp

HEADERS  += cetserver.h \
    DatabaseHandler.h

FORMS    += cetserver.ui
