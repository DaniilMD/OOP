TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Card.cpp \
        Deck.cpp \
        Game.cpp \
        GenericPlayer.cpp \
        Hand.cpp \
        House.cpp \
        Player.cpp \
        main.cpp

HEADERS += \
    Card.h \
    Deck.h \
    Game.h \
    GenericPlayer.h \
    Hand.h \
    House.h \
    Player.h
