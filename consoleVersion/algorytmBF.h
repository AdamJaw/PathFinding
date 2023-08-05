#ifndef ALGORYTMBF_H
#define ALGORYTMBF_H
#include "tworzenieMapy.h"
#include "mozliweSciezki.h"

const int B=4;

struct Punkt{
    int X;
    int Y;
};

struct Krawedz{
    int skad;
    int dokad;
    int waga;
};

int znajdzIndeksPunktu(parametryMapy PM, int X, int Y);
Punkt znajdzWspolrzednePunktu(int indeks, parametryMapy PM);
void stworzTabliceKosztow(int *&tabelaKosztow,int start,parametryMapy PM);
void stworzTabeleNajkrotszychPolaczen(int *&tabelaPolaczen,int start,parametryMapy PM);
void sprawdzWszystkichSasiadow(int *&mapa, int indeks, int *&tabelaKosztow, int *&tabelaPolaczen, parametryMapy PM);
int *bellmanoFord(parametryMapy PM, int *mapa, int rozmiar,SAM sam);

#endif // ALGORYTMBF_H
