#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T09:09:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaveGame
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    character.cpp \
    level.cpp \
    enemy.cpp \
    window.cpp

HEADERS  += game.h \
    character.h \
    level.h \
    enemy.h \
    window.h

FORMS += \
    window.ui
