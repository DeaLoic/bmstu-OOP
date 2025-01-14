QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw.cpp \
    error_code.cpp \
    graphics.cpp \
    link.cpp \
    link_array.cpp \
    load.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    move.cpp \
    point.cpp \
    point_array.cpp \
    point_draw.cpp \
    rotate.cpp \
    scale.cpp \
    target.cpp

HEADERS += \
    draw.h \
    error_code.h \
    graphics.h \
    link.h \
    link_array.h \
    load.h \
    mainwindow.h \
    model.h \
    move.h \
    point.h \
    point_array.h \
    point_draw.h \
    rotate.h \
    scale.h \
    target.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
