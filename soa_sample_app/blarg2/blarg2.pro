#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T18:18:30
#
#-------------------------------------------------

QT       += core gui network webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blarg2
TEMPLATE = app


SOURCES += main.cpp\
    console.cpp \
    mapWidget/mapwidget.cpp \
    mapWidget/webview.cpp \
    parsy.cpp \
    blarg2window.cpp \
    logicwidget.cpp

HEADERS  += \
    console.h \
    parsy.h \
    mapWidget/mapwidget.h \
    mapWidget/webview.h \
    blarg2window.h \
    logicwidget.h

FORMS    += \
    blarg2window.ui
