#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "odnajdywanieSciezki.h"
#include "wyswietlanieMapyZeSciezka.h"
#include "plikTekstowy.h"
#include "tworzenieMapy.h"
#include "algorytmBF.h"
#include "wymiaryMapy.h"
#include <QPainter>
#include <QFileDialog>
#include <QPushButton>
#include <QMouseEvent>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_flag = false;
    m_flag2 = false;
    m_flag3 = false;
    m_flag4 = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] sciezka.sciezka;
    delete[] Tsciezka;
    delete[] mapa;
}
/**
 * \brief Funkcja odpowiedzialna za efekty graficzne
 *
 * Na samym początku wszystkie flagi są ustawione jako false więc w oknie programu nic nie jest wyświetlane
 * Jeśli flaga m_flag zostanie zmieniona na true, czyli został wybrany plik tekstowy w oknie dialogowym
 * zostanie utworzona mapa składająca się z zer i jedynek, identyfikujących przeszkody i pola, po których można chodzić
 * następnie na podstawie tej tablicy zostanie narysowana mapa składająca się z prostokątów, gdzie przeszkody będą miały
 * kolor czarny, a pola normalne będą miały kolor biały.
 * Jeśli flaga m_flag2 zostanie zmieniona na true to oznacza, że ustawiona została zmienna globalna start poprzez
 * podwójne kliknięcie myszy i zostanie zaznaczona na mapie jako czerwony prostokąt
 * Jeśli flaga m_flag3 zostanie zmieniona na true to oznacza, że ustawiona została zmienna globalna meta poprzez
 * podwójne kliknięcie myszy i zostanie zaznaczona na mapie jako czerwony prostokąt
 * Jeśli flaga m_flag4 zostanie zmieniona na true, to oznacza, że aktywowany został przycisk "Znajdź ścieżkę"
 * Zostaną uruchomione funkcje odpowiedzialne za poszukiwanie ścieżki, a ścieżka zostanie wyświetlona za pomocą zielonych prostokątóW
 * \see stworzSciezke(int *&tablicaNajkrotszychPolaczen, int start, int meta)
 * \see bellmanoFord(parametryMapy PM, int *mapa, int rozmiar,SAM sam)
 * \see pokazSciezke(SIR sciezka,int *mapa, parametryMapy PM)
 */

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(!m_flag){}
    else{
        string plik = fileName.toStdString();
        PM = przypiszParametryMapy(plik);
        mapa = stworzMape(PM);
        for(int i=0;i<iloscElementowMapy(plik);i++){
            Punkt point = znajdzWspolrzednePunktu(i,PM);
            if(mapa[i] == 1){
                painter.setPen(Qt::darkGray);
                painter.setBrush(Qt::black);
                painter.drawRect(point.Y*20,point.X*20,20,20);
            }
            if(mapa[i] == 0){
                painter.setPen(Qt::darkGray);
                painter.setBrush(Qt::white);
                painter.drawRect(point.Y*20,point.X*20,20,20);
            }
        }
    }
    if(!m_flag2){}
    else{
        Punkt S = znajdzWspolrzednePunktu(start,PM);
        painter.setPen(Qt::darkGray);
        painter.setBrush(Qt::red);
        painter.drawRect(S.Y*20,S.X*20,20,20);
    }
    if(!m_flag3){}
    else{
        Punkt M = znajdzWspolrzednePunktu(meta,PM);
        painter.setPen(Qt::darkGray);
        painter.setBrush(Qt::red);
        painter.drawRect(M.Y*20,M.X*20,20,20);
    }
    if(!m_flag4){}
    else{
        int rozmiar = iloscElementowMapy(fileName.toStdString());
        SAM sam = {start,meta};
        sciezka = stworzSciezke(TP,sam.S,sam.M);
        Tsciezka = pokazSciezke(sciezka,mapa,PM);
        for(int i=0;i<rozmiar;i++){
            Punkt point=znajdzWspolrzednePunktu(i,PM);
            if(Tsciezka[i] == '#'){
                painter.setPen(Qt::darkGray);
                painter.setBrush(Qt::black);
                painter.drawRect(point.Y*20,point.X*20,20,20);
            }
            if(Tsciezka[i] == '.'){
                painter.setPen(Qt::darkGray);
                painter.setBrush(Qt::white);
                painter.drawRect(point.Y*20,point.X*20,20,20);
            }
            if(Tsciezka[i] == '*'){
                painter.setPen(Qt::darkGray);
                painter.setBrush(Qt::green);
                painter.drawRect(point.Y*20,point.X*20,20,20);
            }
        }
    }
}

/** \brief Reakcja na naciśnięcie przycisku opisanego "Znajdź plik z mapą"
 *
 * Po naciśnięciu tego przycisku zostanie otwarte okno dialogowe z możliwością wyboru pliku zawierającego mapę.
 * Gdy plik zostanie wybrany funkcja sprawdzi czy dany plik zawiera w sobie tylko i wyłącznie wartości, które są
 * używane przez funkcje programu i nie spowodują żadnego błędu.
 * Jeśli plik nie może być użyty do stworzenia mapy zostanie wyświetlony adekwatny komunikat
 * Jeśli plik może być użyty flaga m_flag zostanie zmieniona na true
 */
void MainWindow::on_pushButton_1_clicked(){
    fileName = QFileDialog::getOpenFileName(this);
    ui->info->clear();
    if(m_flag == false){
        if(SprawdzCzyZawartoscPlikuPoprawna(fileName.toStdString())){
            m_flag = true;
        }
        else{
            QString info = "Nie da się zbudować mapy ze wskazanego pliku!";
            ui->info->appendPlainText(info);
        }
    update();
    }
    else{
        m_flag4=false;
        m_flag2=false;
        m_flag3=false;
        m_flag=true;
        update();
    }
}

/** \brief Funkcja reagująca na podwójne naciśnięcie przycisków myszy
 *
 * Funkcja zczytuje koordynaty w jakich zostało dokonane podwójne naiśnięcie klawisza myszy.
 * Jeśli współrzędne tego punktu znajdują się poza granicami wyznaczanymi przez mapę to funkcja nie zareaguje.
 * Jeśli natomiast punkt nie jest jeszcze ustawiony, a znajduje się na mapie to w zależności czy jest to prawy czy lewy przycisk myszy
 * Zostanie ustawiona na true flaga m_flag2 albo m_flag3
 * \param event
 */
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    Qt::MouseButtons btn = event->button();
    QPointF XY = event->position();
    if(m_flag2==false){
        if((mapa[znajdzIndeksPunktu(PM,(XY.y()/20),(XY.x()/20))]==0)&&(XY.x()<PM.szerokosc*20)&&(XY.y()<PM.wysokosc*20)){
            if(btn == Qt::LeftButton) {
                start = znajdzIndeksPunktu(PM,(XY.y()/20),(XY.x()/20));
                m_flag2=true;
                update();
            }
        }
    }
    if(m_flag3==false){
        if((mapa[znajdzIndeksPunktu(PM,(XY.y()/20),(XY.x()/20))]==0)&&(XY.x()<PM.szerokosc*20)&&(XY.y()<PM.wysokosc*20)){
            if(btn == Qt::RightButton){
                meta = znajdzIndeksPunktu(PM,(XY.y()/20),(XY.x()/20));
                m_flag3=true;
                update();
            }
        }
    }
}

/** \brief Reakcja na naciśnięcie przycisku opisanego "Znajdź scieżkę"
 *
 * Funkcja na początku sprawdza czy flagi odpowiedzialne za ustawienie startu i mety zostały zmienione na true.
 * Jeśli tak to funkcja tworzy tabelę połączeń między punktami na mapie. Jeśli punkt, do którego ma być wyznaczona ma
 * wartość -1 oznacza to, że nie ma on poprzednika, z którego można do niego dojść od pola start i ścieżki nie da się wytyczyć.
 * Zostanie wtedy wyświetlony adekwatny komunikat. Jeśli natomiast do da się przejść od startu do mety to zostanie zmieniona wartość flagi m_flag4 na true
 */
void MainWindow::on_pushButton_2_clicked()
{
    ui->info->clear();
    if((m_flag2==true)&&(m_flag3==true)){
        int rozmiar = iloscElementowMapy(fileName.toStdString());
        SAM sam = {start,meta};
        TP = bellmanoFord(PM, mapa,rozmiar,sam);
        if((TP[meta]==-1)||(TP[start]==-1)){
            QString info = "Jak mam tam niby dojść!";
            ui->info->appendPlainText(info);
            m_flag4 = false;
            m_flag2 = false;
            m_flag3 = false;
            update();
        }
        else{
            m_flag4 = true;
            update();
        }
    }
}

/** \brief Reakcja na naciśnięcie przycisku opisanego "Usuń aktualną scieżkę"
 *
 * Funkcja zmienia wartość flag odpowiedzialnych za rysowanie ścieżki na mapie na false przez co wyświetlana
 * po naciśnięciu tego przycisku jest tylko czysta mapa z przeszkodami
 */
void MainWindow::on_pushButton_3_clicked()
{
    m_flag2 = false;
    m_flag3 = false;
    m_flag4 = false;
    update();
}

/** \brief Reakcja na naciśnięcie przycisku opisanego "Zapisz plik"
 *
 * Funkcja pobiera nazwę pliku pod jakim mają być zapisane dane wyjściowe, tworzy ten plik i zapisuje w nim
 * mapę oraz indeksy wyznaczonej ścieżki
 */
void MainWindow::on_pushButton_4_clicked()
{
    if((m_flag4==true)&&(m_flag2==true)&&(m_flag3==true)&&(m_flag==true)){
        string plik = ui->nazwa->text().toStdString();
        ui->nazwa->clear();
        ZapiszDoPliku(plik,mapa,sciezka,PM);
    }
}
