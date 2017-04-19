TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    log.cpp

HEADERS += \
    main.h \
    log.h

LIBS += -L /usr/include/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
