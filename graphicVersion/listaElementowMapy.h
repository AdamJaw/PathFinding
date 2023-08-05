#ifndef LISTAELEMENTOWMAPY_H
#define LISTAELEMENTOWMAPY_H
#include <iostream>
/**
 * \file listaElementowMapy.h
 * \brief Plik nagłówkowy modułu listaElementowMapy
 */

/** \brief Element listy jednokierunkowej
 *
 *  Definicja elementu należącego do listy jednokierunkowej
 */
struct Lista{
    /// Wartość pola o wartości zero-jedynkowej pobierana z pliku źródłowego mapy
    int wartoscPolaNaMapie;
    /// Wskaźnik do kolejnego elementu listy
    Lista *next;
};

/** \brief Funkcja zwracająca liste elementów z pliku
 *
 * Funkcja korzystając z pliku tekstowego, w którym zawarta jest mapa tworzy listę jednokierunkową, w której każdy
 * kolejny element jest kolejnym polem na mapie zaczynając od tego z zerowym indeksem. Lista zawiera informacje o tym czy
 * na danym miejscu w pliku stoi przeszkodza czy jest to pole po którym można chodzić przy pomocy zapisania ich jako
 * zero - pole, jeden - przeszkodza
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca wskaźnik do listy jednokierunkowej zawierającej informacje o tym czy pole na mapie jest przeszkodą czy polem, po którym można się poruszać
 */

Lista *listaElementowZPliku(std::string nazwaPliku);

#endif // LISTAELEMENTOWMAPY_H
