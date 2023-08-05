#ifndef MOZLIWESCIEZKI_H
#define MOZLIWESCIEZKI_H
#include "tworzenieMapy.h"

struct SAM{
    int S;
    int M;
};

int *mapaZMozliwymiPolami(int *mapa,int rozmiar);
void pokazMapeZMozliwymiPolaczeniami(int *mapa,parametryMapy PM);
SAM OdpowiedniSAM(int *mapa, int rozmiar);
SAM startAndMeta();

#endif // MOZLIWESCIEZKI_H
