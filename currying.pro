TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    currying.hpp \
    test.hpp

QMAKE_CXXFLAGS += -std=c++1y
LIBS += -lboost_unit_test_framework
