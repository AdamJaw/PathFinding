#include <iostream>
#include "tworzenieMapy.h"
#include "mozliweSciezki.h"

using namespace std;

int *mapaZMozliwymiPolami(int *mapa,int rozmiar){
    int *mapaZPolami = new int[rozmiar];
    for(int i=0;i<rozmiar;i++){
        if(mapa[i]==1){
            mapaZPolami[i] = -1;
        }
        if(mapa[i]==0){
            mapaZPolami[i] = i+1;
        }
    }
    return mapaZPolami;
}

void pokazMapeZMozliwymiPolaczeniami(int *mapa,parametryMapy PM){
    int *mapaZPolami = mapaZMozliwymiPolami(mapa,(PM.szerokosc*PM.wysokosc));
    for(int i=0;i<(PM.szerokosc*PM.wysokosc);i++){
        if(mapaZPolami[i]==-1){
            cout <<'#'<<'\t';
        }
        else{
            cout << mapaZPolami[i] << '\t';
        }
        if(((i+1)%PM.szerokosc==0)&&(i>0)){
            cout << endl;
        }
    }
    cout << endl << endl;
}

SAM startAndMeta(){
    SAM sam;
    cout << "\nWybierz numer pola z ktorego chcesz zaczac: ";
    cin >> sam.S;
    cout << "\nWybierz numer pola do ktorego chcesz dojsc: ";
    cin >> sam.M;
    return sam;
}

SAM OdpowiedniSAM(int *mapa, int rozmiar){
    SAM sam = startAndMeta();
    int start = sam.S;
    int meta = sam.M;
    while((mapa[start-1] == 1)||(mapa[meta-1] == 1)||(start>rozmiar)||(meta>rozmiar)||(meta<0)||(start<0)){
            cout << "\nSciezka niemozliwa do wyznaczenia sprobuj jeszcze raz!";
            sam = startAndMeta();
            start = sam.S;
            meta = sam.M;
        }
    start = start-1;
    meta = meta-1;
    sam.S = start;
    sam.M = meta;
    return sam;
}
