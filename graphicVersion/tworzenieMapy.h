#ifndef TWORZENIEMAPY_H
#define TWORZENIEMAPY_H
#include <iostream>
/**
 * \file tworzenieMapy.h
 * \brief Plik nagłówkowy modułu tworzenieMapy
 */

/** \brief Struktura zawierająca parametry mapy
 *
 *  Definicja struktury zawierającej dane charakteryzujące daną mapę
 */
struct parametryMapy{
   /// Zmienna przechowująca nazwę pliku aktualnej mapy
   std::string nazwaPliku;
   /// Zmienna przechowująca szerokość mapy
   int szerokosc;
   /// Zmienna przechowująca wysokość mapy
   int wysokosc;
};


/** \brief Funkcja przypisująca dane na temat aktualnie działającej mapy
 *
 * Funkcja na podstawie nazwy pliku tekstowego, w którym mapa jest zawarta przypisuje wysokość i szerokość mapy
 * \see szerokoscMapy(std::string nazwaPliku);
 * \see wysokoscMapy(std::string nazwaPliku);
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca strukturę zawierająca wysokość, szerokość i nazwę pliku aktualnie działającej mapy
 */
parametryMapy przypiszParametryMapy(std::string nazwaPliku);

/** \brief Funkcja zwracająca zero-jedynkową reprezentacje mapy
 *
 * Funkcja zwraca zero-jedynkową reprezentacje aktualnej mapy w formie wskaźnika do tablicy dynamicznej
 * używa przy tym zewnętrznych funkcji
 * \see listaElementowZPliku(string nazwaPliku)
 * \see iloscElementowMapy(std::string nazwaPliku)
 * \param struktura zawierająca informacje na temat szerokości, wysokości i nazwy aktualnie działającej mapy
 * \return Funkcja zwraca wskaźnik do jednowymiarowej tablicy dynamicznej przechowującej zero-jedynkową reprezentację mapy
 */
int *stworzMape(parametryMapy PM);

#endif // TWORZENIEMAPY_H
