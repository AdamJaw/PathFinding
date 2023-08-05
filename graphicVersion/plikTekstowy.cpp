#include <iostream>
#include <fstream>
#include <string>
#include "plikTekstowy.h"
#include "tworzenieMapy.h"
#include "odnajdywanieSciezki.h"
#include "algorytmBF.h"

using namespace std;

/** \brief Funkcja zwracająca wartość true/false czy plik jest poprawny
 *
 * Funkcja sprawdza czy zawartość pliku spełnia wymogi przewidziane przez program czyli czy są w nim same zera i jedynki,
 * a także czy każda z tych liczb jest oddzielona spacją. Jeśli założenia pliku nie będą spełnione funkcja zwróci wartość false.
 * \param nazwaMapy to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca wartość true/false w zależności od tego czy plik spełnia wymogi programu, czy też nie można z niego wyznaczyć ścieżki
 */
bool SprawdzCzyZawartoscPlikuPoprawna(string nazwaMapy){
    ifstream plik;
    string wiersz;
    int rozmiar;
    plik.open(nazwaMapy.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik, wiersz);
            rozmiar = wiersz.length();
            for(int i=0;i<rozmiar;i++){
                if(i%2==0){
                    if((wiersz[i]!='1')&&(wiersz[i]!='0')){
                        return false;
                    }
                }
                if(i%2!=0){
                    if(wiersz[i]!=' '){
                        return false;
                    }
                }
            }
        }
    }
    plik.close();
    return true;
}

/**
 * \brief Funkcja zapisująca mapę i ścieżkę do pliku
 *
 * Funkcja zapisuje bieżącą mapę za pomocą zer i jedynek, a także zapisuje indeksy pól wchodzących w skład aktualnej ścieżki
 * \param nazwaPliku to nazwa pliku, pod jaką scieżka z mapą mają zostać zapisane
 * \param mapa plik przechowujący zero-jedynkową reprezentację mapy
 * \param sciezka struktura przechowująca indeksy ścieżki za pomocą tablicy dynamicznej jednowymiarowej
 * \param PM struktura przechowująca informacje o szerokości i długości mapy
 */
void ZapiszDoPliku(string nazwaPliku, int *mapa, SIR sciezka, parametryMapy PM){
    ofstream plik;
    string nazwa=nazwaPliku+".txt";
    string wiersz="";
    int indeks;
    char znak;
    plik.open(nazwa);
    if(plik.is_open()){
        for(int i=0;i<PM.wysokosc;i++){
            for(int j=0;j<PM.szerokosc;j++){
                indeks = znajdzIndeksPunktu(PM,i,j);
                if(mapa[indeks]==1){
                    znak='1';
                }
                else{
                    znak='0';
                }
                wiersz=wiersz+znak+' ';
            }
            wiersz+='\n';
            plik << wiersz;
            wiersz="";
        }
        plik << '\n';
        for(int i=0;i<sciezka.rozmiar;i++){
            plik << sciezka.sciezka[i];
            plik << ' ';
        }
    }
    plik.close();
}
