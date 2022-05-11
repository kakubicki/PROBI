#include "trener.h"
#include <iostream>
#include <cstring>

using namespace std;

int Trener::ilosc_trenerow = 0;

int Trener::getIloscTrenerow() {
    return ilosc_trenerow;
}

int Trener::getLataPracy () {
    return m_lata_pracy;
}

void Trener::setLataPracy (int lata_pracy) {
    if (lata_pracy>=0) {m_lata_pracy = lata_pracy; }
    else {cout << "Nie pracuje jako trener" << endl;}
}

Trener::Trener () {
    ilosc_trenerow++;

    cout << "Konstruktor domyslny trener. Aktualna liczba obiektow klasy trener: " << ilosc_trenerow << endl;

    m_nazwisko = "Kubicki";
    m_lata_pracy = 2;
}

Trener::Trener (int lata_pracy) {
    ilosc_trenerow++;

    cout << "Konstruktor jednoargumentowy trener (lata_pracy). Aktualna liczba obiektow klasy trener: " << ilosc_trenerow << endl;

    m_nazwisko = "Kacper";
    m_lata_pracy = lata_pracy;
}

Trener::Trener (string nazwisko, int lata_pracy) {
    ilosc_trenerow++;

    cout << "Konstruktor wieloargumentowy trener (nazwisko, lata_pracy). Aktualna liczba obiektow klasy trener: " << ilosc_trenerow << endl;

    m_nazwisko = nazwisko;
    m_lata_pracy = lata_pracy;
}

Trener::Trener (const Trener &t) {
    ilosc_trenerow++;

    cout << "Konstruktor kopiujacy trener. Aktualna liczba obiektow klasy trener: " << ilosc_trenerow << endl;

    m_nazwisko = t.m_nazwisko;
    m_lata_pracy = t.m_lata_pracy;
}

Trener::~Trener () {
    ilosc_trenerow--;

    cout << "~Trener. Aktualna liczba obiektow klasy trener: " << ilosc_trenerow <<endl;
}
