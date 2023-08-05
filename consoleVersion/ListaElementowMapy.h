#ifndef LISTAELEMENTOWMAPY_H
#define LISTAELEMENTOWMAPY_H
#include <iostream>

struct Lista{
    int wartoscPolaNaMapie;
    Lista *next;
};

Lista *listaElementowZPliku(std::string nazwaPliku);

#endif // LISTAELEMENTOWMAPY_H
