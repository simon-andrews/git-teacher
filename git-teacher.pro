#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T18:11:30
#
#-------------------------------------------------

QT       += core gui
LIBS     += -lgit2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = git-teacher
TEMPLATE = app


SOURCES += main.cpp\
        homewindow.cpp \
    messages.cpp \
    git.cpp \
    scanning.cpp

HEADERS  += homewindow.h \
    messages.h \
    git.h \
    scanning.h

FORMS    += homewindow.ui
