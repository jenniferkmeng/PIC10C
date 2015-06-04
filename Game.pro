#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T14:47:43
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    bomb.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    destructibletiles.cpp \
    tiles.cpp \
    stars.cpp \
    instructions.cpp \
    introscreen.cpp

HEADERS  += \
    player.h \
    bomb.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    destructibletiles.h \
    tiles.h \
    stars.h \
    instructions.h \
    introscreen.h

FORMS    += \
    instructions.ui \
    introscreen.ui

RESOURCES += \
    gamestuff.qrc
