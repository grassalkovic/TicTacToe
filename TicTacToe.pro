TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    log.cpp \
    textures.cpp \
    base.cpp \
    game.cpp \
    mainloop.cpp

HEADERS += \
    log.h \
    constants.h \
    textures.h \
    base.h \
    game.h \
    mainloop.h

LIBS += -L /usr/include/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx

DISTFILES += \
    red-alphabet-letter-x.png \
    red-alphabet-letter-o.png
