QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_enigmatests.cpp ../plugboard.cpp ../enigmaexception.cpp \
    plugboardtests.cpp

HEADERS += tst_enigmatests.h ../plugboard.h ../enigmaexception.h \
    plugboardtests.h
