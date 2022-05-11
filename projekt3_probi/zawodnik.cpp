#include "zawodnik.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int Zawodnik::liczbaPracownikow;

int Zawodnik::getLiczbaPracownikow() {
    return liczbaPracownikow;
}

int Zawodnik::liczbaZawodnikow = 0;

int Zawodnik::getLiczbaZawodnikow() {
    return liczbaZawodnikow;
}

int Zawodnik::getNumer() {
    return m_numer;
}

void Zawodnik::setNumer (int numer) {
    if (numer>0 && numer<51) {m_numer = numer;}
    else {cout << "Numer zawodnika pierwszej druzyny musi miescic sie w zakresie 1 - 50" << endl;}
}

int Zawodnik::getLiczbaWystepow() {
    return m_liczbaWystepow;
}

void Zawodnik::setLiczbaWystepow (int liczbaWystepow) {
    if (liczbaWystepow>=0) {m_liczbaWystepow = liczbaWystepow; }
    else {cout << "Liczba wsyetpow nie moze byc mniejsza od 0" << endl;}
}

int Zawodnik::getLiczbaGoli() {
    return m_liczbaGoli;
}

void Zawodnik::setLiczbaGoli (int liczbaGoli) {
    if (liczbaGoli>=0) {m_liczbaGoli = liczbaGoli; }
    else {cout << "Liczba wsyetpow nie moze byc mniejsza od 0" << endl;}
}

int Zawodnik::getUmiejetnosci() {
    return m_umiejetnosci;
}

void Zawodnik::setUmiejetnosci (int umiejetnosci) {
    if (umiejetnosci>=0) {m_umiejetnosci = umiejetnosci; }
    else {cout << "Umiejetnosci zawodnika pierwszej druzyny nie moga byc mniejsze od 0" << endl;}
}

void Zawodnik::trenuj(int wartoscSzkolenia) {
    m_umiejetnosci += rand() % wartoscSzkolenia;
    cout << m_imie << " " << m_nazwisko << " podczas treningu zwiekszyl swoje umiejetnosci, nowa wartosc umiejetnosci wynosi: " << m_umiejetnosci << endl;
}

//operatory strumieniowe
ostream& operator<<(ostream &output, Zawodnik &zawodnik) {
    return output << "z" << zawodnik.m_imie << " " << zawodnik.m_nazwisko << " " << zawodnik.m_umiejetnosci << " " << zawodnik.m_pozycja << " " << zawodnik.m_numer << " " << zawodnik.m_liczbaWystepow << " " << zawodnik.m_liczbaGoli;
}

istream& operator>>(istream &input, Zawodnik &zawodnik) {
    string z;
    return input >> z >> zawodnik.m_imie >> zawodnik.m_nazwisko >> zawodnik.m_umiejetnosci >> zawodnik.m_pozycja >> zawodnik.m_numer >> zawodnik.m_liczbaWystepow >> zawodnik.m_liczbaGoli;
}

Zawodnik::Zawodnik() {
    liczbaPracownikow++;
    liczbaZawodnikow++;
    m_imie = "brak danych";
    m_nazwisko = "brak danych";
    m_umiejetnosci = 0;
    m_pozycja = "brak danych";
    m_numer = 0;
    m_liczbaWystepow = 0;
    m_liczbaGoli = 0;
}

Zawodnik::Zawodnik(string imie, string nazwisko, int umiejetnosci) {
    liczbaPracownikow++;
    liczbaZawodnikow++;
    m_imie = imie;
    m_nazwisko = nazwisko;
    m_umiejetnosci = umiejetnosci;
}

Zawodnik::Zawodnik(string imie, string nazwisko, int umiejetnosci, string pozycja, int numer, int liczbaWystepow, int liczbaGoli) {
    liczbaPracownikow++;
    liczbaZawodnikow++;
    m_imie = imie;
    m_nazwisko = nazwisko;
    m_umiejetnosci = umiejetnosci;
    m_pozycja = pozycja;
    m_numer = numer;
    m_liczbaWystepow = liczbaWystepow;
    m_liczbaGoli = liczbaGoli;
}

Zawodnik::Zawodnik(const Zawodnik &zawodnik) {
    liczbaPracownikow++;
    liczbaZawodnikow++;
    m_imie = zawodnik.m_imie;
    m_nazwisko = zawodnik.m_nazwisko;
    m_umiejetnosci = zawodnik.m_umiejetnosci;
    m_pozycja = zawodnik.m_pozycja;
    m_numer = zawodnik.m_numer;
    m_liczbaWystepow = zawodnik.m_liczbaWystepow;
    m_liczbaGoli = zawodnik.m_liczbaGoli;
}

Zawodnik::~Zawodnik() {
    liczbaPracownikow--;
    liczbaZawodnikow--;
}

bool Zawodnik::operator==(const Zawodnik &z) {
    if (m_imie != z.m_imie)
        return false;
    if (m_nazwisko != z.m_nazwisko)
        return false;
    if (m_umiejetnosci != z.m_umiejetnosci)
        return false;

    return true;
}

bool Zawodnik::operator!=(const Zawodnik &z) {
    if (m_imie == z.m_imie)
        return false;
    if (m_nazwisko == z.m_nazwisko)
        return false;
    if (m_umiejetnosci == z.m_umiejetnosci)
        return false;

    return true;
}
