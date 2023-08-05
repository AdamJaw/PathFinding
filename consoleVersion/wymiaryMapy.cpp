#include <iostream>
#include <string>
#include <fstream>
#include "wymiaryMapy.h"

using namespace std;

int szerokoscMapy(string nazwaPliku){
    ifstream plik;
    string elementMapyZJ;
    int licznik=0,najdluzszyWiersz=0;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik,elementMapyZJ,' ');
            if(elementMapyZJ[0] != '\n'){
                licznik++;
            }
            if(elementMapyZJ[0] == '\n'){
                if(licznik > najdluzszyWiersz){
                    najdluzszyWiersz = licznik;
                }
                licznik=0;
            }
        }
    }
    plik.close();
    return najdluzszyWiersz;
}

int wysokoscMapy(string nazwaPliku){
    ifstream plik;
    string tmp;
    int licznik=0;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik,tmp);
            licznik++;
        }
    }
    plik.close();
    return (licznik-1);
}

int iloscElementowMapy(string nazwaPliku){
    int WM = wysokoscMapy(nazwaPliku);
    int SM = szerokoscMapy(nazwaPliku);
    return (WM*SM);
}
