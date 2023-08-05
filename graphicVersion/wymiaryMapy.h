#ifndef WYMIARYMAPY_H
#define WYMIARYMAPY_H
#include <iostream>
/**
 * \file wymiaryMapy.h
 * \brief Plik nagłówkowy modułu wymiaryMapy
 */

/** \brief Funkcja zwracająca szerokość aktualnej mapy
 *
 * Funkcja dla każdego wiersza w pliku tekstowym zlicza ilość cyfr się w nim znajdującym
 * Stale nadpisuje długość najdłuższego wiersza, który pod koniec działania funkcji staje się szerokością mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość elementów najdłuższego wiersza w pliku, czyli szerokość mapy
 */
int szerokoscMapy(std::string nazwaPliku);

/** \brief Funkcja zwracająca wysokość aktualnej mapy
 *
 * Funkcja zlicza wszystkie wiersze jakie występują w pliku tekstowym i otrzymaną wartość zwraca jako wysokość mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość wierszy w pliku aktualnie pobieranej mapy, czyli jej wysokość
 */
int wysokoscMapy(std::string nazwaPliku);

/**
 * \brief Funkcja zwracająca ilość wszystkich pól znajdujących się na aktualnej mapie
 *
 * Funkcja przy użyciu funkcji zewnętrznych mnoży ilość wierszy przez ilość kolumn, aby otrzymać ilość elementów mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość wszystkich pól, z których składa się mapa
 */
int iloscElementowMapy(std::string nazwaPliku);

#endif // WYMIARYMAPY_Hs
