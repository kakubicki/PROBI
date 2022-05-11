#pragma once
#include <iostream>
#include <cstring>
#include "zawodnik.h"
#include "trener.h"

using namespace std;

class Klub {
public:
    Klub ();
    Klub (string nazwa);
    Klub (const Klub &k);
    ~Klub ();

    static int ilosc_klubow;
    static int getIloscKlubow();

    string m_nazwa;
    int m_liczba_zawodnikow;
    Trener trener;

    Zawodnik *m_zawodnicy = nullptr;

    void dodajZawodnika(Zawodnik zawodnik);
    //void dodajZawodnika(Zawodnik *zawodnik);

    bool operator==(const Klub &k); //operator dwuargumentowy

    friend ostream& operator<<(ostream &s, Klub &k); //operator strumieniowy

    Klub& operator=(const Klub & k); //operator przypisania
};
