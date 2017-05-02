#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T20:20:59
#
#-------------------------------------------------

QT       += core gui network webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface_20JUN16
TEMPLATE = app


SOURCES += main.cpp\
        interfacewindow.cpp \
    ../blarg2/console.cpp \
    ../blarg2/logicwidget.cpp \
    ../blarg2/parsy.cpp \
    ../blarg2/mapWidget/mapwidget.cpp \
    ../blarg2/mapWidget/webview.cpp \
    ../taskpanelwidget/taskpanelwidget.cpp \
    ../tabpanelwidget/tabpanelwidget.cpp \
    borderlayout.cpp

HEADERS  += interfacewindow.h \
    ../blarg2/console.h \
    ../blarg2/logicwidget.h \
    ../blarg2/parsy.h \
    ../blarg2/mapWidget/mapwidget.h \
    ../blarg2/mapWidget/webview.h \
    ../taskpanelwidget/taskpanelwidget.h \
    ../tabpanelwidget/tabpanelwidget.h \
    borderlayout.h

FORMS    += interfacewindow.ui \
    ../taskpanelwidget/taskpanelwidget.ui \
    ../tabpanelwidget/tabpanelwidget.ui
