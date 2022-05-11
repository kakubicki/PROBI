#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Zawodnik {
public:
    Zawodnik ();
    Zawodnik (int numer, int liczba_wystepow);
    Zawodnik (string pozycja, int numer, int liczba_wystepow);
    Zawodnik (const Zawodnik &z);
    ~Zawodnik ();

    static int ilosc_zawodnikow;
    static int getIloscZawodnikow();

    int getNumer();
    void setNumer (int numer);

    int getLiczbaWystepow();
    void setLiczbaWystepow(int liczba_wystepow);

    string m_pozycja;
    int m_numer;
    int m_liczba_wystepow;

    bool operator==(const Zawodnik &z);
    bool operator!=(const Zawodnik &z);

    operator string(); //operator konwersji
};
