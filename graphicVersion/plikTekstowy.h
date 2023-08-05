#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
#include <iostream>
#include "tworzenieMapy.h"
#include "odnajdywanieSciezki.h"
/**
 * \file plikTekstowy.h
 * \brief Plik nagłówkowy modułu plikTekstowy
 */

using namespace std;

/** \brief Funkcja zwracająca wartość true/false czy plik jest poprawny
 *
 * Funkcja zwraca wartość false jeśli plik nie może zostać użyty do wyznaczenia ścieżki, to znaczy jeśli znajdują
 * się w nim inne wartości niż przewidziane przez program czyli zera i jedynki zostanie zwrócona wartość false. Błąd zostanie
 * również wykryty jeśli liczby w pliku nie będą oddzielone spacjami. Jeśli wszystko jest zgodne z wymaganiami programu
 * zwrócona zostanie wartość true
 * \param nazwaMapy to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca wartość true/false w zależności od tego czy plik spełnia wymogi programu, czy też nie można z niego wyznaczyć ścieżki
 */
bool SprawdzCzyZawartoscPlikuPoprawna(std::string nazwaMapy);

/**
 * \brief Funkcja zapisująca mapę i ścieżkę do pliku
 *
 * Funkcja zapisuje bieżącą mapę za pomocą zer i jedynek, a także zapisuje indeksy pól wchodzących w skład aktualnej ścieżki
 * \param nazwaPliku to nazwa pliku, pod jaką scieżka z mapą mają zostać zapisane
 * \param mapa plik przechowujący zero-jedynkową reprezentację mapy
 * \param sciezka struktura przechowująca indeksy ścieżki za pomocą tablicy dynamicznej jednowymiarowej
 * \param PM struktura przechowująca informacje o szerokości i długości mapy
 */
void ZapiszDoPliku(string nazwaPliku, int *mapa, SIR sciezka, parametryMapy PM);
#endif // PLIKTEKSTOWY_H
