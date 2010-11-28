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
    aboutCET.cpp \
    viewsupplieswindow.cpp \
    viewdiseasewindow.cpp \
    manageshipmentswindow.cpp \
    createshipmentwindow.cpp \
    addsupplywindow.cpp \
    adddiseasewindow.cpp


HEADERS  += mainwindow.h \
    googlemap.h \ 
    aboutCET.h \
    viewsupplieswindow.h \
    viewdiseasewindow.h \
    manageshipmentswindow.h \
    createshipmentwindow.h \
    addsupplywindow.h \
    adddiseasewindow.h


FORMS    += mainwindow.ui \
    aboutCET.ui \
    viewsupplieswindow.ui \
    viewdiseasewindow.ui \
    manageshipmentswindow.ui \
    createshipmentwindow.ui \
    addsupplywindow.ui \
    AddDiseaseWindow.ui

RESOURCES += \
    mapDefinitionFile.qrc
