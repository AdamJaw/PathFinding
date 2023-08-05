#include <iostream>
#include "odnajdowanieSciezki.h"
#include "ListaElementowMapy.h"
using namespace std;

SIR stworzSciezke(int *&tablicaNajkrotszychPolaczen, int start, int meta){
    int *sciezka;
    int poprzedni = tablicaNajkrotszychPolaczen[meta];
    Lista *head=nullptr;
    Lista *tmp=nullptr;
    Lista *akt=nullptr;
    int i=0,c=0;
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
            poprzedni = tablicaNajkrotszychPolaczen[poprzedni];
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
        head=head->next;
        i++;
    }
    delete tmp;
    delete head;
    return {sciezka,i};
}
