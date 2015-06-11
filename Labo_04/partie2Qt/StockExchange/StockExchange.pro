#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T09:23:29
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StockExchange
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    bourse.cpp \
    graph.cpp \
    qcustomplot.cpp

HEADERS  += widget.h \
    bourse.h \
    graph.h \
    qcustomplot.h

RESOURCES += \
    Ressources.qrc
