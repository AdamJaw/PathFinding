#ifndef ALGORYTMBF_H
#define ALGORYTMBF_H
#include "tworzenieMapy.h"
/**
 * \file algorytmBF.h
 * \brief Plik nagłówkowy modułu algorytmBF
 */

///Zmienna B - jej wartość to liczba sąsiadów sprawdzanych dla każdego pola ma mapie
const int B=4;

/** \brief Koordynaty punktu na mapie
 *
 *  Definicja punktu jednoznacznie identyfikującego punkt na mapie
 */
struct Punkt{
    /// Współrzędna X pola na mapie
    int X;
    /// Współrzędna Y pola na mapie
    int Y;
};

/** \brief Krawędź łącząca pola na mapie
 *
 *  Definicja krawędzi łączącej każde dwa punkty na mapie
 *  Jednoznacznie określa zależności między dwoma polami
 */
struct Krawedz{
    /// Indeks pola z którego chcemy się przemieścić
    int skad;
    /// Indeks pola na które chcemy się udać
    int dokad;
    /// Koszt jaki musimy przeznaczyć aby przemieścić się z jednego pola na drugie
    int waga;
};

/** \brief Struktura przechowująca start i metę
 *
 *  Definicja struktury zawierającej:
 *  indeks pola z którego chcemy zacząć wytyczanie ścieżki
 *  indeks pola na którym chcemy zakończyć naszą ścieżkę
 */
struct SAM{
    /// Indeks pola z którego zaczyna się tworzyć ścieżka
    int S;
    /// Indeks pola na którym zakończy się ścieżka
    int M;
};

/** \brief Funkcja zwracająca indeks pola na mapie
 *
 *  Funkcja na podstawie wymiarów mapy oraz na podstawie koordynatów
 *  ustala indeks pola na mapie (warto tu nadmienić że mapa przechowywana jest
 *  jako tablica jednowymiarowa a wyświetlana jako dwuwymiarowa)
 *  \param PM struktura zawierająca szerokosc i wysokosc mapy niezbędną do wyznaczenia indeksu pola
 *  \param X współrzędna w płaszczyźnie poziomej pola na mapie
 *  \param Y współrzędna w płaszczyźnie pionowej pola na mapie
 *  \return indeks punktu (X,Y)
 */
int znajdzIndeksPunktu(parametryMapy PM, int X, int Y);

/** \brief Funkcja zwracająca współrzędne punktu na mapie
 *
 *  Funkcja na podstawie wymiaróW mapy oraz na podstawie indeksu pola
 *  ustala współrzędne X i Y jednoznacznie identyfikujące położenie pola
 *  \param indeks to indeks na którym znajduje się punkt w tablicy jednowymiarowej zawierającej mapę
 *  \param PM struktura zawierająca szerokosc i wysokosc mapy niezbędną do wyznaczenia współrzędnych pola
 *  \return Punkt struktura zawierająca współrzędne X i Y pola na mapie
 */
Punkt znajdzWspolrzednePunktu(int indeks, parametryMapy PM);

/** \brief Funkcja tworząca tablicę najkrótszych połączeń
 *
 *  Funkcja uzupełniająca tablicę wartością 0 dla pola wskazanego jako start co oznacza, że to pole jest swoim poprzednikiem/ nie ma poprzednika
 *  wartością -1 dla każdego pola, ponieważ przy deklaracji tablicy połączeń jeszcze nie wiadomo jakie są koszty dotarcia do poszczególnych pól
 *  Funkcja nie zwraca żadnej wartości, wpisuje wartości do już istniejącej tablicy
 *  \param tabelaPolaczen jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 *  \param start to pole, które zostaję uznane przez program za pole które nie ma poprzedników i przypisana zostaje mu wartość 0
 *  \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void stworzTabeleNajkrotszychPolaczen(int *&tabelaPolaczen,int start,parametryMapy PM);

/** \brief Funkcja tworząca tablicę kosztów dotarcia do celu
 *  Funkcja uzupełniająca tablicę wartością 0 dla pola wskazanego jako start co oznacza, że koszt dotarcia do pola, z którego się zaczyna jest równy zero
 *  Dla każdego innego pola na mapie zostaje przypisana wartość nie możliwa do osiągnięcia czyli kwadrat rozmiaru całej mapy jako domyślna wartość kosztu dotarcia do tego pola
 * Funkcja nie zwraca żadnej wartości, wpisuje wartości do istniejącej tablicy
 * \param tabelaKosztow jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości wag odpowiednie dla poszczególnych punktów
 * \param start to pole, które zostaję uznane przez program za pole które nie ma poprzedników i przypisana zostaje mu wartość 0
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void stworzTabliceKosztow(int *&tabelaKosztow,int start,parametryMapy PM);

/** \brief Funkcja sprawdzająca otoczenie punktu na mapie
 *
 *  Funkcja jest niezbędna do poprawnego funkcjonowania algorytmu wyszukiwania scieżki
 *  Sprawdza dla każdego pola na mapie najbliższych sąsiadów każdego pola i przypisuje im wagę dotarcia do tego pola z poprzedniego pola
 *  Za każdym przejściem pętli aktualizuje parametry danego pola zmieniając jej sąsiada jeśli dotarcie do niego ma mniejszy koszt niż poprzednia konfiguracja
 *  Weryfikuje też pola będące przeszkodami i przypisuje im adekwatne wartości tj. bardzo wysokie koszty dotarcia niemożliwe do spełnienia
 * \param mapa jest to wskaźnik do jednowymiarowej tablicy indeksów zawierających punkty na mapie
 * \param indeks jest indeksem pola dla którego w danym przejściu pętli sprawdzana jest sytuacja z sąsiadami tego punktu
 * \param tabelaKosztow jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości wag odpowiednie dla poszczególnych punktów
 * \param tabelaPolaczen jest to wskaźnik do tablicy jednowymiarowej w której zostaną zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 */
void sprawdzWszystkichSasiadow(int *&mapa, int indeks, int *&tabelaKosztow, int *&tabelaPolaczen, parametryMapy PM);

/** \brief Funkcja wytyczająca najkrótszą scieżkę
 *
 * Jest to najważniejsza funkcja niezbędna do poprawnego funkcjonowania programu
 * Funkcja tworzy tablicę kosztów dotarcia do poszczególnych pól na mapie i tablicę poprzedników o najmniejszym kosztem dotarcia do poszczególnych pól mapy
 * Funkcja ma złożoność wykładniczą kwadratowo w zależności od zwiększających się wymiarów mapy pętla zawsze wykona się dwa razy ilość pól na mapie
 * \param PM struktura zawierająca szerokość i wysokość mapy niezbędną do przyznania wartości każdemu z pól
 * \param mapa jest to wskaźnik do jednowymiarowej tablicy indeksów zawierających punkty na mapie
 * \param rozmiar jest to ilość wszystkich pól jakie są na mapie
 * \param sam jest to struktura zawierająca indeks pola z którego zaczyna się ścieżka i indeks pola, na którym kończy się ścieżka
 * \return funkcja zwraca tablicę jednowymiarową zawierającą dla każdego indeksu tablicy indeks w polu wartość z którego do tego pola jest najmniejszy koszt dotarcia
 */
int *bellmanoFord(parametryMapy PM, int *mapa, int rozmiar,SAM sam);

#endif // ALGORYTMBF_H
