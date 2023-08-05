#include <iostream>
#include "odnajdowanieSciezki.h"
#include "tworzenieMapy.h"
#include "algorytmBF.h"
#include "wyswietlanieMapyZeSciezka.h"
#include "mozliweSciezki.h"

using namespace std;

int znajdzIndeksPunktu(parametryMapy PM, int X, int Y){
    return X*PM.szerokosc+Y;
}

Punkt znajdzWspolrzednePunktu(int indeks, parametryMapy PM){
    int X = indeks/PM.szerokosc;
    int Y = indeks%PM.szerokosc;
    return {X,Y};
}

void stworzTabliceKosztow(int *&tabelaKosztow,int start,parametryMapy PM){
    for(int i=0;i<(PM.szerokosc*PM.wysokosc);i++){
            tabelaKosztow[i] = (PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc);
        }
        tabelaKosztow[start] = 0;
}

void stworzTabeleNajkrotszychPolaczen(int *&tabelaPolaczen,int start,parametryMapy PM){
    for(int i=0;i<(PM.szerokosc*PM.wysokosc);i++){
        tabelaPolaczen[i] = -1;
    }
    tabelaPolaczen[start] = 0;
}

void sprawdzWszystkichSasiadow(int *&mapa, int indeks, int *&tabelaKosztow, int *&tabelaPolaczen, parametryMapy PM){
    Punkt Sasiedzi[B] = {{-1,0},{0,1},{1,0},{0,-1}};
    Punkt P = znajdzWspolrzednePunktu(indeks,PM);
    Krawedz sasiad;
    Punkt TMP={0,0};
    for(int i=0;i<B;i++){
        sasiad.skad = indeks;
        TMP.X=P.X+Sasiedzi[i].X;
        TMP.Y=P.Y+Sasiedzi[i].Y;
        if((TMP.X<0)||(TMP.X>=PM.wysokosc)||(TMP.Y<0)||(TMP.Y>=PM.szerokosc)){
            sasiad.waga=(PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc);
        }
        else{
            if(mapa[sasiad.skad]==1){
                continue;
            }
            sasiad.dokad = znajdzIndeksPunktu(PM,TMP.X,TMP.Y);
            sasiad.waga = tabelaKosztow[indeks]+1;
        }
        if(sasiad.waga<(PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc)){
            if(mapa[sasiad.dokad]!=1){
                if(sasiad.waga<tabelaKosztow[sasiad.dokad]){
                    tabelaKosztow[sasiad.dokad]=sasiad.waga;
                    tabelaPolaczen[sasiad.dokad] = sasiad.skad;
                }
            }
        }
    }
}

int *bellmanoFord(parametryMapy PM, int *mapa, int rozmiar,SAM sam){
    int *tabelaKosztow = new int[rozmiar];
    stworzTabliceKosztow(tabelaKosztow,sam.S,PM);
    int *tabelaPolaczen = new int[rozmiar];
    stworzTabeleNajkrotszychPolaczen(tabelaPolaczen,sam.S,PM);
    for(int i=0;i<rozmiar;i++){
        for(int j=0;j<rozmiar;j++){
            sprawdzWszystkichSasiadow(mapa,j,tabelaKosztow,tabelaPolaczen,PM);
        }
    }
    return tabelaPolaczen;
}
