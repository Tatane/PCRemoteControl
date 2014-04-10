#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T21:29:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCRemoteControl
TEMPLATE = app



SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/TCPClient.cpp

HEADERS  += src/mainwindow.h \
    src/TCPClient.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

