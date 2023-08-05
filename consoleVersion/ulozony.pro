TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        algorytmBF.cpp \
        listaElementowMapy.cpp \
        main.cpp \
        mozliweSciezki.cpp \
        odnajdowanieSciezki.cpp \
        plikTekstowy.cpp \
        tworzenieMapy.cpp \
        wymiaryMapy.cpp \
        wyswietlanieMapyZeSciezka.cpp

HEADERS += \
    ListaElementowMapy.h \
    algorytmBF.h \
    mozliweSciezki.h \
    odnajdowanieSciezki.h \
    plikTekstowy.h \
    tworzenieMapy.h \
    wymiaryMapy.h \
    wyswietlanieMapyZeSciezka.h
