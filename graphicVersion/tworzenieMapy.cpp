#include <iostream>
#include <string>
#include "tworzenieMapy.h"
#include "wymiaryMapy.h"
#include "ListaElementowMapy.h"

using namespace std;

/** \brief Funkcja przypisująca dane na temat aktualnie działającej mapy
 *
 * Funkcja na podstawie nazwy pliku, z którego pobierana jest mapa tworzy strukturę
 * przechowująca informacje na temat szerokości aktualnej mapy, jej wysokości i jej nazwę.
 * \see szerokoscMapy(std::string nazwaPliku);
 * \see wysokoscMapy(std::string nazwaPliku);
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca strukturę zawierająca wysokość, szerokość i nazwę pliku aktualnie działającej mapy
 */
parametryMapy przypiszParametryMapy(string nazwaPliku){
    parametryMapy PM;
    PM.nazwaPliku = nazwaPliku;
    PM.szerokosc = szerokoscMapy(PM.nazwaPliku);
    PM.wysokosc = wysokoscMapy(PM.nazwaPliku);
    return PM;
}
/** \brief Funkcja zwracająca zero-jedynkową reprezentacje mapy
 *
 * Funkcja tworzy zero-jedynkową reprezentacje mapy pobranej z pliku tekstowego przy użyciu listy jednokierunkowej
 * zawierającej te wartości
 * \see listaElementowZPliku(string nazwaPliku)
 * \see iloscElementowMapy(std::string nazwaPliku)
 * \param struktura zawierająca informacje na temat szerokości, wysokości i nazwy aktualnie działającej mapy
 * \return Funkcja zwraca wskaźnik do jednowymiarowej tablicy dynamicznej przechowującej zero-jedynkową reprezentację mapy
 */
int *stworzMape(parametryMapy PM){
    int iloscElementow = iloscElementowMapy(PM.nazwaPliku);
    Lista *Pola = listaElementowZPliku(PM.nazwaPliku);
    int *mapa = new int[iloscElementow];
    for(int i=0;i<iloscElementow;i++){
        mapa[i] = Pola->wartoscPolaNaMapie;
        Lista *tmp = Pola;
        Pola=Pola->next;
        if(i<iloscElementow-1){
            delete tmp;
        }
    }
    delete Pola;
    return mapa;
}
