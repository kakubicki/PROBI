#include "trener.h"
#include <iostream>
#include <cstring>

using namespace std;

int Trener::liczbaPracownikow;

int Trener::getLiczbaPracownikow() {
    return liczbaPracownikow;
}

int Trener::liczbaTrenerow = 0;

int Trener::getLiczbaTrenerow() {
    return liczbaTrenerow;
}

int Trener::getLataPracy() {
    return m_lataPracy;
}

void Trener::setLataPracy (int lataPracy){
    if(lataPracy>0) {m_lataPracy = lataPracy;}
    else {cout << "Ten czlowiek nie ma doswiadczenia w prowadzeniu zespolu" << endl;}
}

int Trener::getLiczbaTrofeow() {
    return m_liczbaTrofeow;
}

void Trener::setLiczbaTrofeow (int liczbaTrofeow){
    if(liczbaTrofeow>=0) {m_liczbaTrofeow = liczbaTrofeow;}
    else {cout << "Liczba trofeow musi sie miejscic w zakresie 0 - niesk." << endl;}
}

void Trener::trenuj(int wartoscSzkolenia) {
    m_umiejetnosci += wartoscSzkolenia;
    cout << m_imie << " " << m_nazwisko << " podczas szkolenia zwiekszyl swoje zdolnosci trenerskie, nowa wartosc umiejetnosci wynosi: " << m_umiejetnosci << endl;
}

//operatory strumieniowe
ostream& operator<<(ostream &output, Trener &trener) {
    return output << "t " << trener.m_imie << " " << trener.m_nazwisko << " " << trener.m_umiejetnosci << " " << trener.m_lataPracy << " " << trener.m_liczbaTrofeow;
}

istream& operator>>(istream &input, Trener &trener) {
    string t;
    return input >> t >> trener.m_imie >> trener.m_nazwisko >> trener.m_umiejetnosci >> trener.m_lataPracy >> trener.m_liczbaTrofeow;
}

Trener::Trener() {
    liczbaPracownikow++;
    liczbaTrenerow++;
    m_imie = "Jerzy";
    m_nazwisko = "Brzeczek";
    m_umiejetnosci = 20;
    m_lataPracy = 2;
    m_liczbaTrofeow = 0;
}

Trener::Trener(string imie, string nazwisko,int umiejetnosci, int lataPracy, int liczbaTrofeow) {
    liczbaPracownikow++;
    liczbaTrenerow++;
    m_imie = imie;
    m_nazwisko = nazwisko;
    m_umiejetnosci = umiejetnosci;
    m_lataPracy = lataPracy;
    m_liczbaTrofeow = liczbaTrofeow;
}

Trener::Trener(const Trener &trener) {
    liczbaPracownikow++;
    liczbaTrenerow++;
    m_imie = trener.m_imie;
    m_nazwisko = trener.m_nazwisko;
    m_umiejetnosci = trener.m_umiejetnosci;
    m_lataPracy = trener.m_lataPracy;
    m_liczbaTrofeow = trener.m_liczbaTrofeow;
}

Trener::~Trener() {
    liczbaPracownikow--;
    liczbaTrenerow--;
}
