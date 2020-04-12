#-------------------------------------------------
#
# Project created by QtCreator 2019-12-11T20:37:11
#
#-------------------------------------------------

QT       += core gui sql xml charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SatelliteProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    corewindowform.cpp \
    faultdealingform.cpp \
    global.cpp \
    main.cpp \
    devicebutton.cpp \
    devicestatusform.cpp \
    linkbutton.cpp \
    firstmainwindow.cpp \
    navlistview.cpp \
    popselecttasknumber.cpp \
    statewidget.cpp \
    newstatewidget.cpp \
    peroptform.cpp \
    database.cpp \
    inputdatawidget.cpp \
    taskstatepage.cpp


HEADERS += \
    corewindowform.h \
    devicebutton.h \
    devicestatusform.h \
    faultdealingform.h \
    firstmainwindow.h \
    global.h \
    linkbutton.h \
    navlistview.h \
    popselecttasknumber.h \
    statewidget.h \
    newstatewidget.h \
    peroptform.h \
    database.h \
    inputdatawidget.h \
    taskstatepage.h

FORMS += \
    corewindowform.ui \
    devicestatusform.ui \
    faultdealingform.ui \
    firstmainwindow.ui \
    popselecttasknumber.ui \
    statewidget.ui \
    newstatewidget.ui \
    peroptform.ui \
    inputdatawidget.ui \
    taskstatepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    image/weixing_Main.jpg \
    readme.txt

RESOURCES += \
    images.qrc
