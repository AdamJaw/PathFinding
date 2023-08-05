#include <iostream>
#include "algorytmBF.h"
#include "plikTekstowy.h"
#include "mozliweSciezki.h"
#include <string>
#include "odnajdowanieSciezki.h"
#include "wyswietlanieMapyZeSciezka.h"

using namespace std;

int main()
{
    string nazwa;
    int check=1;
    while(check!=0){
    nazwa = nazwaPliku();
    check = SprawdzCzyZawartoscPlikuPoprawna(nazwa);
    }
    nazwa = dostosujMape(nazwa);
    parametryMapy PM = przypiszParametryMapy(nazwa);
    int *mapa = stworzMape(PM);
    pokazMapeZMozliwymiPolaczeniami(mapa,PM);
    int rozmiar = PM.szerokosc*PM.wysokosc;
    SAM sam = OdpowiedniSAM(mapa,rozmiar);
    int *TP = bellmanoFord(PM, mapa,rozmiar,sam);
    SIR sciezka = stworzSciezke(TP,sam.S,sam.M);
    char *Tsciezka = pokazSciezke(sciezka,mapa,PM);
    wyswietlMapeKoncowa(Tsciezka,rozmiar,PM);
    return 0;
}
