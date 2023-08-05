#include <iostream>
#include "wyswietlanieMapyZeSciezka.h"
#include "tworzenieMapy.h"
#include "odnajdywanieSciezki.h"

using namespace std;

/** \brief Funkcja zwracająca mapę z wytyczoną ścieżką
 *
 * Funkcja tworzy tablicę znaków o rozmiarze takim jak ilość elementów z pliku tekstowego i przypisuje znak (#) polom, które
 * mają w wartości zero-jedynkowej mapy wartość 1, a (.) tym, które są reprezentowane przez wartość 0. Następnie nanosi na
 * tak utworzoną mapę znaki (*), które reprezentują wytyczoną ścieżkę
 * \see stworzMape(parametryMapy PM)
 * \see pokazSciezke(SIR sciezka,int *mapa, parametryMapy PM)
 * \param sciezka jest to struktura zawierająca tablicę dynamiczną indeksów pól zawartych w ścieżce i rozmiar tej tablicy
 * \param mapa to wskaźnik do jednowymiarowej tablicy dynamicznej przechowującej zero-jedynkową reprezentację mapy
 * \param PM to struktura zawierająca szerokość mapy, jej wysokość i nazwę pliku ją przechowującego
 * \return Funkcja zwraca wskaźnik do tablicy znaków przechowującej mapę z wytyczoną ścieżką
 */
char *pokazSciezke(SIR sciezka,int *mapa, parametryMapy PM){
    int wielkoscMapy = (PM.szerokosc*PM.wysokosc);
    int iloscElementowSciezki = sciezka.rozmiar;
    char *PS = new char [wielkoscMapy];
    for(int i=0;i<wielkoscMapy;i++){
        if(mapa[i]==1){
            PS[i]='#';
        }
        if(mapa[i]==0){
            PS[i]='.';
        }
    }
    for(int j=0;j<iloscElementowSciezki;j++){
        int id = sciezka.sciezka[j];
        PS[id] = '*';
    }
    return PS;
}
