#include "pracownik_klubu.h"
#include <iostream>
#include <cstring>

using namespace std;

int PracownikKlubu::liczbaPracownikow = 0;

int PracownikKlubu::getLiczbaPracownikow() {
    return liczbaPracownikow;
}

int PracownikKlubu::getUmiejetnosci(){
    return m_umiejetnosci;
}

//operatory strumieniowe
ostream& operator<<(ostream &output, PracownikKlubu &pracownik) {
    return output << "imie: " << pracownik.m_imie << " nazwisko: " << pracownik.m_nazwisko << " umiejetnosci: " << pracownik.m_umiejetnosci;
}

istream& operator>>(istream &input, PracownikKlubu &pracownik) {
    return input >> pracownik.m_imie >> pracownik.m_nazwisko >> pracownik.m_umiejetnosci;
}

PracownikKlubu::PracownikKlubu() {
    liczbaPracownikow++;
    m_imie = "brak danych";
    m_nazwisko = "brak danych";
    m_umiejetnosci = 0;
}

PracownikKlubu::PracownikKlubu(string imie, string nazwisko, int umiejetnosci) {
    liczbaPracownikow++;
    m_imie = imie;
    m_nazwisko = nazwisko;
    m_umiejetnosci = umiejetnosci;
}

PracownikKlubu::PracownikKlubu(const PracownikKlubu &pracownik) {
    liczbaPracownikow++;
    m_imie = pracownik.m_imie;
    m_nazwisko = pracownik.m_nazwisko;
    m_umiejetnosci = pracownik.m_umiejetnosci;
}

PracownikKlubu::~PracownikKlubu() {
    liczbaPracownikow--;
}
