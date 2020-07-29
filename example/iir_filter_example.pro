#-------------------------------------------------
#
# Project created by QtCreator 2020-07-23T21:43:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FIR_FILTER
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../iir_filter/iir_filter.cpp


HEADERS  += mainwindow.h \
    ../iir_filter/iir_filter.h

FORMS    += mainwindow.ui
