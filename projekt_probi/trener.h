#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Trener {
public:
    Trener ();
    Trener (int lata_pracy);
    Trener (string nazwisko, int lata_pracy);
    Trener (const Trener &t);
    ~Trener ();

    static int ilosc_trenerow;
    static int getIloscTrenerow();

    int getLataPracy();
    void setLataPracy (int lata_pracy);

    string m_nazwisko;
    int m_lata_pracy;
};
