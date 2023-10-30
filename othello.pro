TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        manejo_archivos.cpp \
        player.cpp \
        tablero.cpp

HEADERS += \
    manejo_archivos.h \
    player.h \
    tablero.h
