#include <iostream>
#include "odnajdywanieSciezki.h"
#include "ListaElementowMapy.h"
using namespace std;


/** \brief Funkcja zwracająca ścieżkę dla poszczególnych pól start/meta
 *
 * Funkcja przy użyciu tablicy poprzedników (pól o najmniejszych kosztach dotarcia z pola start) tworzy listę
 * zaczynając od mety i cofając się aż do pola start, którego poprzednik ma wartość równą zero, czyli nie ma poprzednika/
 * sam jest swoim własnym poprzednikiem. Następnie tworzy tablice dynamiczną, do której wpisuje indeksy pól mapy zawartych w ścieżce
 * \param tablicaNajkrotszychPolaczen jest to wskaźnik do tablicy jednowymiarowej w której są zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 * \param start jest to pole na którym lista się kończy, jest to początek ścieżki
 * \param meta jest to pole, z którego ścieżka się zaczyna, jest to pierwsze pole w liście
 * \return Funkcja zwraca tablicę dynamiczną indeksów pól zawartych w ścieżce i rozmiar tej tablicy
 */
SIR stworzSciezke(int *&tablicaNajkrotszychPolaczen, int start, int meta){
    int *sciezka;
    int poprzedni = tablicaNajkrotszychPolaczen[meta];
    Lista *head=nullptr;
    Lista *tmp=nullptr;
    Lista *akt=nullptr;
    int i=1,c=0;
    while((poprzedni!=0)||(c!=2)){
        i++;
        if(head==nullptr){
            head = new Lista;
            head->wartoscPolaNaMapie = meta;
            head->next=nullptr;
            akt=head;
        }
        if(head!=nullptr){
            tmp = new Lista;
            tmp->wartoscPolaNaMapie = poprzedni;
            tmp->next=nullptr;
            akt->next=tmp;
            akt=tmp;
            poprzedni=tablicaNajkrotszychPolaczen[poprzedni];
            if((start==0)&&(poprzedni==0)){
                c++;
            }
            if(start!=0){
                c=2;
            }
        }
    }
    sciezka = new int[i];
    i=0;
    while(head!=nullptr){
        sciezka[i] = head->wartoscPolaNaMapie;
        tmp=head->next;
        delete head;
        head=tmp;
        i++;
    }
    //delete[] tablicaNajkrotszychPolaczen;
    return {sciezka,i};
}
