#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T00:14:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = piksele
TEMPLATE = app


SOURCES += main.cpp\
        matrix.cpp \
        matrixForRotation.cpp \
        matrixForScaling.cpp \
        matrixForShearingOX.cpp \
        matrixForShearingOY.cpp \
        matrixForTranslation.cpp \
        mywindow.cpp \
        punkt.cpp

HEADERS  += mywindow.h \
    matrix.h \
    matrixForRotation.h \
    matrixForScaling.h \
    matrixForShearingOX.h \
    matrixForShearingOY.h \
    matrixForTranslation.h \
    punkt.h

FORMS    += mywindow.ui

RESOURCES += \
    Obraz.qrc
