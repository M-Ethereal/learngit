#-------------------------------------------------
#
# Project created by QtCreator 2018-10-04T07:57:46
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Try1-CameraControl
TEMPLATE = app

#Configs
CONFIG += console
CONFIG -= app_bundle
#CONFIG -= qt
CONFIG += c++14

#Libraries
unix: CONFIG += link_pkgconfig

#OpenCV
unix: PKGCONFIG += opencv

SOURCES += main.cpp\
        cameracontrol.cpp

HEADERS  += cameracontrol.h

FORMS    += cameracontrol.ui
