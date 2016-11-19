QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = curso-qt-osl-tareas-exe
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp

HEADERS  += \
    dbconnection.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
