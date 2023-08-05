#include <iostream>
#include "tworzenieMapy.h"
#include "algorytmBF.h"

using namespace std;

/** \brief Funkcja zwracająca indeks pola na mapie
 *
 * Funkcja przyjmuje parametry związane z wielkością mapy mnoży szerokość ze współrzędną X i dodaje współrzędną Y
 * \param PM struktura zawierająca szerokosc i wysokosc mapy niezbędną do wyznaczenia indeksu pola
 * \param X współrzędna w płaszczyźnie poziomej pola na mapie
 * \param Y współrzędna w płaszczyźnie pionowej pola na mapie
 * \return indeks punktu (X,Y)
 */
int znajdzIndeksPunktu(parametryMapy PM, int X, int Y){
    return X*PM.szerokosc+Y;
}
/** \brief Funkcja zwracająca współrzędne punktu na mapie
 *  Funkcja przyjmuje indeks i parametry mapy dzieli indeks przez szerokość mapy, żeby otrzymać współrzędną X
 *  Żeby otrzymać współrzędną Y zwraca resztę z dzielenia indeksu przez szerokosc mapy
 *  \param indeks to indeks na którym znajduje się punkt w tablicy jednowymiarowej zawierającej mapę
 *  \param PM struktura zawierająca szerokosc i wysokosc mapy niezbędną do wyznaczenia współrzędnych pola
 *  \return Punkt struktura zawierająca współrzędne X i Y pola na mapie
 */
Punkt znajdzWspolrzednePunktu(int indeks, parametryMapy PM){
    int X = indeks/PM.szerokosc;
    int Y = indeks%PM.szerokosc;
    return {X,Y};
}

/** \brief Funkcja tworząca tablicę kosztów dotarcia do celu
 *
 * Funkcja przyjmuję tablicę jednowymiarową i dla każdego pola na mapie poza polem, które jest określone jako start przypisuje wartość
 * która jest kwadratem ilości wszystkich pól znajdujących się na mapie
 * \param tabelaKosztow jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości wag odpowiednie dla poszczególnych punktów
 * \param start to pole, które zostaję uznane przez program za pole które nie ma poprzedników i przypisana zostaje mu wartość 0
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void stworzTabliceKosztow(int *&tabelaKosztow,int start,parametryMapy PM){
    for(int i=0;i<(PM.szerokosc*PM.wysokosc);i++){
            tabelaKosztow[i] = (PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc);
        }
        tabelaKosztow[start] = 0;
}

/** \brief Funkcja tworząca tablicę najkrótszych połączeń
 *
 * Funkcja przyjmuje tablicę jednowymiarową i dla każdego pola na mapie poza polem, które jest określone jako start przypisuje
 * wartość -1, a dla indeksu, który jest indeksem start przypisuje wartość zero
 * \param tabelaPolaczen jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 * \param start to pole, które zostaję uznane przez program za pole które nie ma poprzedników i przypisana zostaje mu wartość 0
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void stworzTabeleNajkrotszychPolaczen(int *&tabelaPolaczen,int start,parametryMapy PM){
    for(int i=0;i<(PM.szerokosc*PM.wysokosc);i++){
        tabelaPolaczen[i] = -1;
    }
    tabelaPolaczen[start] = 0;
}

/** \brief Funkcja sprawdzająca otoczenie punktu na mapie
 *
 * Funkcja dla każdego punktu sprawdza sąsiadów wprowadzonego punktu
 * W pierwszej kolejności sprawdza czy sąsiedzi istnieją tzn. czy współrzędne sąsiadów nie wykraczają poza wymiary mapy
 * Jeśli sąsiad mieści się w granicach mapy to jest dopisywany jako kraniec krawędzi, a jego koszt dotarcia jest o jeden większy
 * od pola, z którego sprawdzany jest dany sąsiad. Następnie sprawdzane jest czy pole nie jest przeszkodą, jeśli nie to w przypadku kiedy ścieżka
 * przeprowadzona przez tego sąsiada jest mniejsza niż ta zawarta w tabeli kosztów i połączeń to dane są aktualizowane
 * \param mapa jest to wskaźnik do jednowymiarowej tablicy indeksów zawierających punkty na mapie
 * \param indeks jest indeksem pola dla którego w danym przejściu pętli sprawdzana jest sytuacja z sąsiadami tego punktu
 * \param tabelaKosztow jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości wag odpowiednie dla poszczególnych punktów
 * \param tabelaPolaczen jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void sprawdzWszystkichSasiadow(int *&mapa, int indeks, int *&tabelaKosztow, int *&tabelaPolaczen, parametryMapy PM){
    Punkt Sasiedzi[B] = {{-1,0},{0,1},{1,0},{0,-1}};
    Punkt P = znajdzWspolrzednePunktu(indeks,PM);
    Krawedz sasiad;
    Punkt TMP={0,0};
    for(int i=0;i<B;i++){
        sasiad.skad = indeks;
        TMP.X=P.X+Sasiedzi[i].X;
        TMP.Y=P.Y+Sasiedzi[i].Y;
        if((TMP.X<0)||(TMP.X>=PM.wysokosc)||(TMP.Y<0)||(TMP.Y>=PM.szerokosc)){
            sasiad.waga=(PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc);
        }
        else{
            if(mapa[sasiad.skad]==1){
                continue;
            }
            sasiad.dokad = znajdzIndeksPunktu(PM,TMP.X,TMP.Y);
            sasiad.waga = tabelaKosztow[indeks]+1;
        }
        if(sasiad.waga<(PM.szerokosc*PM.wysokosc)*(PM.szerokosc*PM.wysokosc)){
            if(mapa[sasiad.dokad]!=1){
                if(sasiad.waga<tabelaKosztow[sasiad.dokad]){
                    tabelaKosztow[sasiad.dokad]=sasiad.waga;
                    tabelaPolaczen[sasiad.dokad] = sasiad.skad;
                }
            }
        }
    }
}
/** \brief Funkcja wytyczająca najkrótszą scieżkę
 *
 * Funkcja tworzy tablicę kosztóW i tablicę najkrótszych połączeń między punktami. Następnie przy użyciu funkcji sprawdzWszystkichSasiadow
 * \see sprawdzWszystkichSasiadow(int *&mapa, int indeks, int *&tabelaKosztow, int *&tabelaPolaczen, parametryMapy PM);
 * Aktualizuje w każdym kolejnym przejściu utworzone tablicę tak, że każdy punkt pod koniec działania funkcji ma swój koszt dotarcia od startu i
 * wybranego sąsiada z którego do tego punktu można dojść najszybciej
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 * \param mapa jest to wskaźnik do jednowymiarowej tablicy indeksów zawierających punkty na mapie
 * \param rozmiar jest to ilość wszystkich pól jakie są na mapie
 * \param sam jest to struktura zawierająca indeks pola z którego zaczyna się ścieżka i indeks pola, na którym kończy się ścieżka
 * \return funkcja zwraca tablicę jednowymiarową zawierającą dla każdego indeksu tablicy indeks w polu wartość z którego do tego pola jest najmniejszy koszt dotarcia
 */
int *bellmanoFord(parametryMapy PM, int *mapa, int rozmiar,SAM sam){
    int *tabelaKosztow = new int[rozmiar];
    stworzTabliceKosztow(tabelaKosztow,sam.S,PM);
    int *tabelaPolaczen = new int[rozmiar];
    stworzTabeleNajkrotszychPolaczen(tabelaPolaczen,sam.S,PM);
    for(int i=0;i<rozmiar;i++){
        for(int j=0;j<rozmiar;j++){
            sprawdzWszystkichSasiadow(mapa,j,tabelaKosztow,tabelaPolaczen,PM);
        }
    }
    delete[] tabelaKosztow;
    return tabelaPolaczen;
}
