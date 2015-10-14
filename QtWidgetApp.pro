#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T11:24:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWidgetApp
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        analogclock.cpp \
    tabdialog.cpp \
    customdialog.cpp \
    simplewizard.cpp \
    controllerwindow.cpp \
    helloGLwindow.cpp \
    helloglwidget.cpp \
    glwidget.cpp \
    logo.cpp

HEADERS  += mainwindow.h \
    analogclock.h \
    customlogger.h \
    tabdialog.h \
    customdialog.h \
    simplewizard.h \
    controllerwindow.h \
    helloGLwindow.h \
    helloglwidget.h \
    glwidget.h \
    logo.h

FORMS    += mainwindow.ui
