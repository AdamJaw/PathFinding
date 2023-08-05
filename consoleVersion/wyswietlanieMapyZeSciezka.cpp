#include <iostream>
#include "wyswietlanieMapyZeSciezka.h"
#include "tworzenieMapy.h"
#include "odnajdowanieSciezki.h"

using namespace std;

char *pokazSciezke(SIR sciezka,int *mapa, parametryMapy PM){
    int wielkoscMapy = (PM.szerokosc*PM.wysokosc);
    int iloscElementowSciezki = sciezka.rozmiar;
    char *PS = new char [wielkoscMapy];
    for(int i=0;i<wielkoscMapy;i++){
        if(mapa[i]==1){
            PS[i]='#';
        }
        if(mapa[i]==0){
            PS[i]='.';
        }
    }
    for(int j=0;j<iloscElementowSciezki;j++){
        int id = sciezka.sciezka[j];
        PS[id] = '*';
    }
    return PS;
}

void wyswietlMapeKoncowa(char *Tsciezka,int rozmiar, parametryMapy PM){
    for(int i=0;i<rozmiar;i++){
        if((i%PM.szerokosc==0)&&(i>0)){
            cout << endl;
        }
        cout << Tsciezka[i] << '\t';
    }
}
