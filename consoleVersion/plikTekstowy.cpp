#include <iostream>
#include <fstream>
#include <string>
#include "plikTekstowy.h"

using namespace std;

string nazwaPliku(){
    string nazwa;
    ifstream plik;
    do{
        cout << "Podaj nazwe pliku z mapa: ";
        cin >> nazwa;
        plik.open(nazwa.c_str());
    }while(!plik);
    return nazwa;
}

string dostosujMape(string nazwaMapy){
    ifstream plik;
    ofstream Mplik;
    string wiersz;
    plik.open(nazwaMapy.c_str());
    string nowaNazwaMapy = 'M'+nazwaMapy;
    Mplik.open(nowaNazwaMapy.c_str());
    if(plik.is_open()){
        if(Mplik.is_open()){
            while(!plik.eof()){
                getline(plik, wiersz);
                wiersz = wiersz+" \n ";
                Mplik << wiersz;
            }
        }
    }
    plik.close();
    Mplik.close();
    return nowaNazwaMapy;
}

int SprawdzCzyZawartoscPlikuPoprawna(string nazwaMapy){
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
                        return 1;
                    }
                }
                if(i%2!=0){
                    if(wiersz[i]!=' '){
                        return 1;
                    }
                }
            }
        }
    }
    plik.close();
    return 0;
}
