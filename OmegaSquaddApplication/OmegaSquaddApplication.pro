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
    adddiseasewindow.cpp \
    adddiseaseswindow.cpp \
    addsupplieswindow.cpp \
    createshipmentswindow.cpp \
    managetheshipmentswindow.cpp \
    viewthediseaseswindow.cpp \
    viewthesupplieswindow.cpp


HEADERS  += mainwindow.h \
    googlemap.h \ 
    aboutCET.h \
    viewsupplieswindow.h \
    viewdiseasewindow.h \
    manageshipmentswindow.h \
    createshipmentwindow.h \
    addsupplywindow.h \
    adddiseasewindow.h \
    adddiseaseswindow.h \
    addsupplieswindow.h \
    createshipmentswindow.h \
    managetheshipmentswindow.h \
    viewthediseaseswindow.h \
    viewthesupplieswindow.h


FORMS    += mainwindow.ui \
    aboutCET.ui \
    viewsupplieswindow.ui \
    viewdiseasewindow.ui \
    manageshipmentswindow.ui \
    createshipmentwindow.ui \
    addsupplywindow.ui \
    AddDiseaseWindow.ui \
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
