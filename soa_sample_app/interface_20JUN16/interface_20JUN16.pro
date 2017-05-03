#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T20:20:59
#
#-------------------------------------------------

QT       += core gui network webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface_20JUN16
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        interfacewindow.cpp \
    ../blarg2/logicwidget.cpp \
    ../blarg2/mapWidget/mapwidget.cpp \
    ../blarg2/mapWidget/webview.cpp \
    ../taskpanelwidget/taskpanelwidget.cpp \
    borderlayout.cpp \
    ../tabwidget2/tabpanel2.cpp \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanel.cpp \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainer.cpp \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainertabwidget.cpp \
    ../tabwidget2/tabWidgetFiles/Containers_Panels/bytaskpanel.cpp \
    ../tabwidget2/tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.cpp \
    ../tabwidget2/tabWidgetFiles/qclicklabel.cpp

HEADERS  += interfacewindow.h \
    ../blarg2/logicwidget.h \
    ../blarg2/mapWidget/mapwidget.h \
    ../blarg2/mapWidget/webview.h \
    ../taskpanelwidget/taskpanelwidget.h \
    ../include/SoaAutonomy.h \
    ../include/WorldDataManager.h \
    ../include/WorldLocation.h \
    ../include/Belief_Actor.h \
    borderlayout.h \
    ../tabwidget2/tabpanel2.h \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanel.h \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainer.h \
    ../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainertabwidget.h \
    ../tabwidget2/tabWidgetFiles/Containers_Panels/bytaskpanel.h \
    ../tabwidget2/tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.h \
    ../tabwidget2/tabWidgetFiles/qclicklabel.h

FORMS    += interfacewindow.ui \
    ../taskpanelwidget/taskpanelwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/Linux/release/ -lwdm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/Linux/debug/ -lwdm
else:unix: LIBS += -L$$PWD/../lib/Linux/ -lwdm

INCLUDEPATH += $$PWD/../lib/Linux
DEPENDPATH += $$PWD/../lib/Linux
