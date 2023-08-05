#include <iostream>
#include <string>
#include <fstream>
#include "wymiaryMapy.h"

using namespace std;

/** \brief Funkcja zwracająca szerokość aktualnej mapy
 *
 * Funkcja wyszukuje najdłuższy wiersz znajdujący się w aktualnie używanym pliku tekstowym
 * i zwraca jego długość (ilość elementów wiersza) jako szerokość mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość elementów najdłuższego wiersza w pliku, czyli szerokość mapy
 */
int szerokoscMapy(string nazwaPliku){
    ifstream plik;
    string wierszMapyZJ;
    int licznik=0,najdluzszyWiersz=0,len;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik,wierszMapyZJ,'\n');
            len = wierszMapyZJ.length();
            for(int i=0;i<len;i++){
                if(wierszMapyZJ[i] != ' '){
                    licznik++;
                }
            }
            if(licznik > najdluzszyWiersz){
                najdluzszyWiersz = licznik;
            }
            licznik=0;
        }
    }
    plik.close();
    return najdluzszyWiersz;
}

/** \brief Funkcja zwracająca wysokość aktualnej mapy
 *
 * Funkcja zlicza ile wierszy zawiera plik tekstowy aktualnie używanej mapy, a następnie
 * zwraca tą wartość jako wysokość mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość wierszy w pliku aktualnie pobieranej mapy, czyli jej wysokość
 */
int wysokoscMapy(string nazwaPliku){
    ifstream plik;
    string tmp;
    int licznik=0;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik,tmp);
            licznik++;
        }
    }
    plik.close();
    return (licznik);
}

/**
 * \brief Funkcja zwracająca ilość wszystkich pól znajdujących się na aktualnej mapie
 *
 * Funkcja przy użyciu funkcji zewnętrznych mnoży ilość wierszy przez ilość kolumn, aby otrzymać ilość elementów mapy
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca ilość wszystkich pól, z których składa się mapa
 */
int iloscElementowMapy(string nazwaPliku){
    int WM = wysokoscMapy(nazwaPliku);
    int SM = szerokoscMapy(nazwaPliku);
    return (WM*SM);
}
