#ifndef TWORZENIEMAPY_H
#define TWORZENIEMAPY_H
#include <iostream>

struct parametryMapy{
   std::string nazwaPliku;
   int szerokosc;
   int wysokosc;
};

parametryMapy przypiszParametryMapy(std::string nazwaPliku);
int *stworzMape(parametryMapy PM);

#endif // TWORZENIEMAPY_H
