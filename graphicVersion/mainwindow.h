#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "odnajdywanieSciezki.h"
#include "tworzenieMapy.h"
#include <string>
/**
 * \file mainwindow.h
 * \brief Plik nagłówkowy modułu mainwindow
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /// Wskaźnik przechowujący zero-jedynkowe wartości odpowiadające za to czy pole jest przeszkodą czy zwykłym polem
    int *mapa;
    /// W tej zmiennej zawarte są informacje o szerokości i długości mapy, a także o nazwie samej mapy
    parametryMapy PM;
    //// Zmienna przechowująca nazwę pliku pobraną z eksploratora plików
    QString fileName;
    /// Zmienna odpowiedzialna za to, czy pewne zdarzenie miało miejsce i czy dana sytuacja programu musi zostać zaktualizowana
    bool m_flag;
    /// Zmienna odpowiedzialna za to, czy pewne zdarzenie miało miejsce i czy dana sytuacja programu musi zostać zaktualizowana
    bool m_flag2;
    /// Zmienna odpowiedzialna za to, czy pewne zdarzenie miało miejsce i czy dana sytuacja programu musi zostać zaktualizowana
    bool m_flag3;
    /// Zmienna odpowiedzialna za to, czy pewne zdarzenie miało miejsce i czy dana sytuacja programu musi zostać zaktualizowana
    bool m_flag4;
    /// Zmienna przechowująca indeks pola, z którego zaczyna się ścieżka
    int start;
    /// Zmienna przechowująca indeks pola, na którym kończy się ścieżka
    int meta;

    int *TP;

    SIR sciezka;

    char *Tsciezka;

private slots:
    /** \brief Funkcja odpowiedzialna za efekty graficzne
     *
     * Funkcja rysuje prostokąty w odpowiednim miejcu i w wyznaczonym kolorze aby stworzyć graficzny obraz
     * ścieżki wyświetlonej na mapie z przeszkodami
     */
    void paintEvent(QPaintEvent*);

    /** \brief Funkcja reagująca na podwójne naciśnięcie przycisków myszy
     *
     * Funkcja na podstawie koordynatów naciśnięcia klawisza myszy na wybranym polu ustawia to pole jako pole start lub meta
     * w zależności od użytego klawisza. Zawiera szereg ograniczeń np. polem tym nie może być przeszkoda ani żaden punkt, który
     * mieści się poza granicami wyświetlanej mapy
     * \param event
     */
    void mouseDoubleClickEvent(QMouseEvent *event);

    /** \brief Reakcja na naciśnięcie przycisku opisanego "Znajdź plik z mapą"
     *
     * Funkcja po naciśnięciu przycisku otwiera okno dialogowe, z którego można wybrać plik z mapą.
     * W zależności od wybranego pliku funkcja albo pobiera jego nazwę albo zwraca błąd jeśli plik jest nieodpowiedni
     */
    void on_pushButton_1_clicked();

    /** \brief Reakcja na naciśnięcie przycisku opisanego "Znajdź scieżkę"
     *
     * Funkcja po naciśnięciu przycisku sprawdza czy punktu startu i początku zostały odpowiednio dobrane (to znaczy tak, żeby
     * można było wytyczyć ścieżkę. Jeśli wszystko zostało wprowadzone poprawnie funkcja aktualizuje paintEvent poprzez flagę ustawioną jako true
     * przez co na wyświetlonej mapie zostaję pokazana ścieżka
     */
    void on_pushButton_2_clicked();

    /** \brief Reakcja na naciśnięcie przycisku opisanego "Usuń aktualną scieżkę"
     *
     * Funkcja zmienia wszystkie flagi odpowiedzialne za aktualizowanie wyświetlanej mapy na false czego efektem jest
     * usunięcie wyświetlanej ścieżki i punktów zaznaczonych jako start i meta. Zostaje jedynie czysta mapa z przeszkodami.
     */
    void on_pushButton_3_clicked();

    /** \brief Reakcja na naciśnięcie przycisku opisanego "Zapisz plik"
     *
     * Funkcja pobiera nazwę pliku pod jakim mają być zapisane dane wyjściowe, tworzy ten plik i zapisuje w nim
     * mapę oraz indeksy wyznaczonej ścieżki
     */
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
