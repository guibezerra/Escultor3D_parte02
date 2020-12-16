TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sculptor.cpp \
    figurageometrica.cpp \
    putvoxel.cpp \
    cutvoxel.cpp \
    putbox.cpp \
    cutbox.cpp \
    putsphere.cpp \
    cutsphere.cpp \
    putellipsoid.cpp \
    cutellipsoid.cpp \
    interpretador.cpp

HEADERS += \
    sculptor.h \
    figurageometrica.h \
    putvoxel.h \
    cutvoxel.h \
    putbox.h \
    cutbox.h \
    putsphere.h \
    cutsphere.h \
    putellipsoid.h \
    cutellipsoid.h \
    interpretador.h
