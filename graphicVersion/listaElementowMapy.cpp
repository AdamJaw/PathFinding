#include <iostream>
#include <fstream>
#include "ListaElementowMapy.h"
#include "wymiaryMapy.h"

using namespace std;


/** \brief Funkcja zwracająca liste elementów z pliku
 *
 * Funkcja pobiera wartości zero-jedynkowe z pliku tekstowego do momentu, aż nie napotka jego końca.
 * Funkcja automatycznie uzupełnia mapę przeszkodami, aby powstała mapa, która w każdym wierszu ma tyle samo pól, licząc od najdłuższego wiersza zawartego w pliku
 * \param nazwaPliku to nazwa pliku, z którego pobierana jest aktualna mapa
 * \return Funkcja zwraca wskaźnik do listy jednokierunkowej zawierającej informacje o tym czy pole na mapie jest przeszkodą czy polem, po którym można się poruszać
 */
Lista *listaElementowZPliku(string nazwaPliku){
    int szerokosc = szerokoscMapy(nazwaPliku);
    ifstream plik;
    Lista *head=nullptr;
    Lista *tmp=nullptr;
    Lista *akt=nullptr;
    string wierszMapyZJ;
    int dlugosc;
    int licznik=0;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            getline(plik,wierszMapyZJ,'\n');
            dlugosc = (wierszMapyZJ.length());
            for(int i=0;i<dlugosc;i++)
            {
                if(head!=nullptr){
                    tmp = new Lista;
                    if(wierszMapyZJ[i]=='0'){
                        tmp->wartoscPolaNaMapie=0;
                        tmp->next=nullptr;
                        akt->next=tmp;
                        akt=tmp;
                        licznik++;
                    }
                    if(wierszMapyZJ[i]=='1'){
                        tmp->wartoscPolaNaMapie=1;
                        tmp->next=nullptr;
                        akt->next=tmp;
                        akt=tmp;
                        licznik++;
                    }
                }
                if(head==nullptr){
                    head = new Lista;
                    if(wierszMapyZJ[i]=='0'){
                        head->wartoscPolaNaMapie=0;
                    }
                    if(wierszMapyZJ[i]=='1'){
                        head->wartoscPolaNaMapie=1;
                    }
                    head->next=nullptr;
                    akt=head;
                    licznik++;
                }
            }
            if(licznik<szerokosc){
                int ileBrakuje=szerokosc-licznik;
                for(int i=0;i<ileBrakuje;i++){
                    tmp = new Lista;
                    tmp->wartoscPolaNaMapie=1;
                    tmp->next=nullptr;
                    akt->next=tmp;
                    akt=tmp;
                }
            }
            licznik=0;
        }
    }
    plik.close();
    return head;
}
