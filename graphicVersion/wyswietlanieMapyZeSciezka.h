#ifndef WYSWIETLANIEMAPYZESCIEZKA_H
#define WYSWIETLANIEMAPYZESCIEZKA_H
#include "tworzenieMapy.h"
#include "odnajdywanieSciezki.h"
/**
 * \file wyswietlanieMapyZeSciezka.h
 * \brief Plik nagłówkowy modułu wyswietlanieMapyZeSciezka
 */

/** \brief Funkcja zwracająca mapę z wytyczoną ścieżką
 *
 * Funkcja nanosi ścieżkę na zero-jedynkową mapę i zwraca ją w postaci tablicy znaków, gdzie (*) to pole ścieżki
 * (#) to przeszkoda, a (.) to pole normalne, po którym może być wytyczana ścieżka
 * \param sciezka jest to struktura zawierająca tablicę dynamiczną indeksów pól zawartych w ścieżce i rozmiar tej tablicy
 * \param mapa to wskaźnik do jednowymiarowej tablicy dynamicznej przechowującej zero-jedynkową reprezentację mapy
 * \param PM to struktura zawierająca szerokość mapy, jej wysokość i nazwę pliku ją przechowującego
 * \return Funkcja zwraca wskaźnik do tablicy znaków przechowującej mapę z wytyczoną ścieżką
 */
char *pokazSciezke(SIR sciezka,int *mapa, parametryMapy PM);
#endif // WYSWIETLANIEMAPYZESCIEZKA_H
