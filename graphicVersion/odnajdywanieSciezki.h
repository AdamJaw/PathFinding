#ifndef ODNAJDYWANIESCIEZKI_H
#define ODNAJDYWANIESCIEZKI_H
/**
 * \file odnajdywanieSciezki.h
 * \brief Plik nagłówkowy modułu odnajdywanieSciezki
 */

/** \brief Struktura zawierająca scieżkę
 *
 *  Definicja elementu zawierającego istotne dane do wyznaczenia ścieżki
 */
struct SIR{
    /// Wskaźnik do listy dynamicznej zawierającej indeksy pól ścieżki
    int *sciezka;
    /// Ilość elementów scieżki (Długość ścieżki)
    int rozmiar;
};


/** \brief Funkcja zwracająca ścieżkę dla poszczególnych pól start/meta
 *
 * Funkcja przy użyciu tabeli poprzedników zawierającej informacje na temat pól, z których można dojść do danego pola z najmniejszym kosztem
 * \see stworzTabeleNajkrotszychPolaczen(int *&tabelaPolaczen,int start,parametryMapy PM);
 * tworzy listę której pierwszym elementem jest pole meta, a następnie pola o coraz mniejszej wadze, ścieżka kończy się
 * gdy indeks poprzednika będzie równy zero czyli pole to będzie polem, z którego zaczyna się ścieżka
 * Następnie tworzy tablicę dynamiczną, do której wpisywane są indeksy pól mapy zawartych w ścieżce
 * \param tablicaNajkrotszychPolaczen jest to wskaźnik do tablicy jednowymiarowej w której są zapisane wartości indeksów odpowiednie dla poszczególnych punktów
 * \param start jest to pole na którym lista się kończy, jest to początek ścieżki
 * \param meta jest to pole, z którego ścieżka się zaczyna, jest to pierwsze pole w liście
 * \return Funkcja zwraca tablicę dynamiczną indeksów pól zawartych w ścieżce i rozmiar tej tablicy
 */
SIR stworzSciezke(int *&tablicaNajkrotszychPolaczen, int start, int meta);

#endif // ODNAJDYWANIESCIEZKI_H
