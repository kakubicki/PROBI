#include "junior.h"
#include <iostream>
#include <cstring>

using namespace std;

int Junior::liczbaPracownikow;

int Junior::getLiczbaPracownikow() {
    return liczbaPracownikow;
}

int Junior::liczbaJuniorow = 0;

int Junior::getLiczbaJuniorow() {
    return liczbaJuniorow;
}

int Junior::getNumer() {
    return m_numer;
}

void Junior::setNumer (int numer) {
    if (numer>50 && numer<100) {m_numer = numer;}
    else {cout << "Numer juniora musi miescic sie w zakresie 51 - 99" << endl;}
}

int Junior::getUmiejetnosci() {
    return m_umiejetnosci;
}

void Junior::setUmiejetnosci (int umiejetnosci) {
    if (umiejetnosci>=0) {m_umiejetnosci = umiejetnosci; }
    else {cout << "Umiejetnosci juniora nie moze byc mniejsza od 0" << endl;}
}

int Junior::getPotencjal() {
    return m_potencjal;
}

void Junior::setPotencjal (int potencjal) {
    if (potencjal>=m_umiejetnosci) {m_potencjal = potencjal; }
    else {cout << "Przewidywane umiejetnosci juniora musi być wiekszy lub rowny umiejetnoscia juniora" << endl;}
}

void Junior::trenuj(int wartoscSzkolenia) {
    m_umiejetnosci += rand() % wartoscSzkolenia;
    cout << m_imie << " " << m_nazwisko << " zwiekszyl umiejetnosci, nowa wartsoc wynosi: " << m_umiejetnosci << endl;
}

//operatory strumieniowe
ostream& operator<<(ostream &output, Junior &junior) {
    return output << "j " << junior.m_imie << " " << junior.m_nazwisko << " " << junior.m_umiejetnosci << " " << junior.m_potencjal << " " << junior.m_pozycja << " " << junior.m_numer << " " << junior.m_liczbaWystepow << " " << junior.m_liczbaGoli;
}

istream& operator>>(istream &input, Junior &junior) {
    string j;
    return input >> j >> junior.m_imie >> junior.m_nazwisko >> junior.m_umiejetnosci >> junior.m_potencjal >> junior.m_pozycja >> junior.m_numer >> junior.m_liczbaWystepow >> junior.m_liczbaGoli;
}

Junior::Junior() {
    liczbaPracownikow++;
    liczbaJuniorow++;
    m_imie = "brak danych";
    m_nazwisko = "brak danych";
    m_umiejetnosci = 0;
    m_potencjal = 0;
    m_pozycja = "brak danych";
    m_numer = 0;
    m_liczbaWystepow = 0;
    m_liczbaGoli = 0;
}

Junior::Junior(string imie, string nazwisko, int umiejetnosci, int potencjal, string pozycja, int numer, int liczbaWystepow, int liczbaGoli) {
    liczbaPracownikow++;
    liczbaJuniorow++;
    m_imie = imie;
    m_nazwisko = nazwisko;
    m_umiejetnosci = umiejetnosci;
    m_potencjal = potencjal;
    m_pozycja = pozycja;
    m_numer = numer;
    m_liczbaWystepow = liczbaWystepow;
    m_liczbaGoli = liczbaGoli;
}

Junior::Junior(const Junior &junior) {
    liczbaPracownikow++;
    liczbaJuniorow++;
    m_imie = junior.m_imie;
    m_nazwisko = junior.m_nazwisko;
    m_umiejetnosci = junior.m_umiejetnosci;
    m_potencjal = junior.m_potencjal;
    m_pozycja = junior.m_pozycja;
    m_numer = junior.m_numer;
    m_liczbaWystepow = junior.m_liczbaWystepow;
    m_liczbaGoli = junior.m_liczbaGoli;
}

Junior::~Junior() {
    liczbaPracownikow--;
    liczbaJuniorow--;
}

