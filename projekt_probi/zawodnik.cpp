#include "zawodnik.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int Zawodnik::ilosc_zawodnikow = 0;

int Zawodnik::getIloscZawodnikow() {
    return ilosc_zawodnikow;
}

int Zawodnik::getNumer () {
    return m_numer;
}

void Zawodnik::setNumer (int numer) {
    if (numer>0 && numer<100) {m_numer = numer;}
    else {cout << "Numer musi miescic sie w zakresie 1 - 99" << endl;}
}

int Zawodnik::getLiczbaWystepow () {
    return m_liczba_wystepow;
}

void Zawodnik::setLiczbaWystepow (int liczba_wystepow) {
    if (liczba_wystepow>=0) {m_liczba_wystepow = liczba_wystepow; }
    else {cout << "Liczba wsyetpow nie moze byc mniejsza od 0" << endl;}
}

bool Zawodnik::operator==(const Zawodnik &z) {
    if (m_pozycja != z.m_pozycja)
        return false;
    if (m_numer != z.m_numer)
        return false;
    if (m_liczba_wystepow != z.m_liczba_wystepow)
        return false;

    return true;
}

bool Zawodnik::operator!=(const Zawodnik &z) {
    if (m_pozycja == z.m_pozycja)
        return false;
    if (m_numer == z.m_numer)
        return false;
    if (m_liczba_wystepow == z.m_liczba_wystepow)
        return false;

    return true;
}

Zawodnik::operator string() {
    return " - " + m_pozycja;
}

Zawodnik::Zawodnik () {
    ilosc_zawodnikow++;

    cout << "Konstruktor domyslny zawodnik. Aktualna liczba obiektow klasy zawodnik: " << ilosc_zawodnikow << endl;

    m_pozycja = "brak pozycji";
    m_numer = 0;
    m_liczba_wystepow = 0;
}

Zawodnik::Zawodnik (int numer, int liczba_wystepow) {
    ilosc_zawodnikow++;

    cout << "Konstruktor wieloargumentowy (numer, liczba wystepow) zawodnik. Aktualna liczba obiektow klasy zawodnik: " << ilosc_zawodnikow << endl;

    m_pozycja = "brak pozycji";
    m_numer = numer;
    m_liczba_wystepow = liczba_wystepow;
}

Zawodnik::Zawodnik (string pozycja, int numer, int liczba_wystepow) {
    ilosc_zawodnikow++;

    cout << "Konstruktor wieloargumentowy (pozycja, numer, liczba wystepow) zawodnik. Aktualna liczba obiektow klasy zawodnik: " << ilosc_zawodnikow << endl;

    m_pozycja = pozycja;
    m_numer = numer;
    m_liczba_wystepow = liczba_wystepow;
}


Zawodnik::Zawodnik (const Zawodnik &z) {
    ilosc_zawodnikow++;

    cout << "Konstruktor kopiujacy zawodnik. Aktualna liczba obiektow klasy zawodnik: " << ilosc_zawodnikow << endl;

    m_pozycja = z.m_pozycja;
    m_numer = z.m_numer;
    m_liczba_wystepow = z.m_liczba_wystepow;
}

Zawodnik::~Zawodnik () {
    ilosc_zawodnikow--;

    cout << "~Zawodnik. Aktualna liczba obiektow klasy zawodnik: " << ilosc_zawodnikow <<endl;

}


