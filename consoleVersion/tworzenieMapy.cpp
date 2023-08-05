#include <iostream>
#include <string>
#include "tworzenieMapy.h"
#include "plikTekstowy.h"
#include "wymiaryMapy.h"
#include "ListaElementowMapy.h"

using namespace std;

parametryMapy przypiszParametryMapy(string nazwaPliku){
    parametryMapy PM;
    PM.nazwaPliku = nazwaPliku;
    PM.szerokosc = szerokoscMapy(PM.nazwaPliku);
    PM.wysokosc = wysokoscMapy(PM.nazwaPliku);
    return PM;
}

int *stworzMape(parametryMapy PM){
    int iloscElementow = iloscElementowMapy(PM.nazwaPliku);
    Lista *Pola = listaElementowZPliku(PM.nazwaPliku);
    int *mapa = new int[iloscElementow];
    for(int i=0;i<iloscElementow;i++){
        mapa[i] = Pola->wartoscPolaNaMapie;
        Pola=Pola->next;
    }
    return mapa;
}
