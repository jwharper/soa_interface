#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T22:21:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tabwidget2
TEMPLATE = app


SOURCES += main.cpp\
        tabpanel2.cpp \
    tabWidgetFiles/OldCode/qsidepanel.cpp \
    tabWidgetFiles/OldCode/qsidepanelcontainer.cpp \
    tabWidgetFiles/OldCode/qsidepanelcontainertabwidget.cpp \
    tabWidgetFiles/Containers_Panels/bytaskpanel.cpp \
    tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.cpp \
    tabWidgetFiles/qclicklabel.cpp

HEADERS  += tabpanel2.h \
    tabWidgetFiles/OldCode/qsidepanel.h \
    tabWidgetFiles/OldCode/qsidepanelcontainer.h \
    tabWidgetFiles/OldCode/qsidepanelcontainertabwidget.h \
    tabWidgetFiles/Containers_Panels/bytaskpanel.h \
    tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.h \
    tabWidgetFiles/qclicklabel.h

FORMS    +=
