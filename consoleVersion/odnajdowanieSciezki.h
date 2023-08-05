#ifndef ODNAJDOWANIESCIEZKI_H
#define ODNAJDOWANIESCIEZKI_H

struct SIR{
    int *sciezka;
    int rozmiar;
};

SIR stworzSciezke(int *&tablicaNajkrotszychPolaczen, int start, int meta);

#endif // ODNAJDOWANIESCIEZKI_H
