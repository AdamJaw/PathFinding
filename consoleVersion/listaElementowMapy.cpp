#include <iostream>
#include <fstream>
#include "ListaElementowMapy.h"
#include "wymiaryMapy.h"

using namespace std;

Lista *listaElementowZPliku(string nazwaPliku){
    int szerokosc = szerokoscMapy(nazwaPliku);
    ifstream plik;
    Lista *head=nullptr;
    Lista *tmp=nullptr;
    Lista *akt=nullptr;
    string elementMapyZJ;
    int licznik=1;
    plik.open(nazwaPliku.c_str());
    if(plik.is_open()){
        while(!plik.eof()){
            if(head==nullptr){
                head = new Lista;
                getline(plik,elementMapyZJ,' ');
                if(elementMapyZJ[0]=='0'){
                    head->wartoscPolaNaMapie=0;
                }
                if(elementMapyZJ[0]=='1'){
                    head->wartoscPolaNaMapie=1;
                }
                head->next=nullptr;
                akt=head;
            }
            if(head!=nullptr){
                tmp = new Lista;
                getline(plik,elementMapyZJ,' ');
                if(elementMapyZJ[0]=='0'){
                    tmp->wartoscPolaNaMapie=0;
                    tmp->next=nullptr;
                    akt->next=tmp;
                    akt=tmp;
                }
                if(elementMapyZJ[0]=='1'){
                    tmp->wartoscPolaNaMapie=1;
                    tmp->next=nullptr;
                    akt->next=tmp;
                    akt=tmp;
                }
                if(elementMapyZJ[0]!='\n'){
                    licznik++;
                }
                if(elementMapyZJ[0]=='\n'){
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
        }
    }
    plik.close();
    delete tmp;
    return head;
}
