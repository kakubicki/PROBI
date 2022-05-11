#pragma once
#include "pracownik_klubu.h"
#include <iostream>
#include <cstring>

using namespace std;

/// Klasa potomna Zawodnik
class Zawodnik : public PracownikKlubu {
public:
    /// Konstruktor domyslny
    Zawodnik();
    /// Konstruktor z parametrami
    Zawodnik(string imie, string nazwisko, int umiejetnosci, string pozycja, int numer, int liczbaWystepow, int liczbaGoli);
    /// Konstruktor kopiujacy
    Zawodnik(const Zawodnik &zawodnik);
    /// Destruktor
    ~Zawodnik();

    /// Statyczna liczba pracownikow
    static int liczbaPracownikow;
    /// Metoda zwracajaca liczbe pracownikow
    static int getLiczbaPracownikow();

    /// Statyczna liczba zawodnikow
    static int liczbaZawodnikow;
    /// Metoda zwracajaca liczbe zawodnikow
    static int getLiczbaZawodnikow();

    /// Metoda zwracajaca poziom umiejetnosci zawodnika
    int getUmiejetnosci();
    /// Metoda ustawiajaca poziom umiejetnosci zawodnika
    void setUmiejetnosci(int umiejetnosci);

    /// Metoda zwracajaca numer zawodnika
    int getNumer();
    /// Metoda ustawiajaca numer zawodnika
    void setNumer(int numer);

    /// Metoda zwracajaca liczbe wystepow zawodnika
    int getLiczbaWystepow();
    /// Metoda ustawiajaca liczbe wystepow zawodnika
    void setLiczbaWystepow(int liczbaWystepow);

    /// Metoda zwracajaca liczbe goli zawodnika
    int getLiczbaGoli();
    /// Metoda ustawiajaca liczbe goli zawodnika
    void setLiczbaGoli(int liczbaGoli);

    /// Metoda zwiekszajaca poziom umiejetnosci zawodnika w zaleznosci od poziomu umiejetnosci trenera
    void trenuj(int);

    /// Operatory strumieniowe
    friend ostream& operator<<(ostream &output, Zawodnik &zawodnik);
    friend istream& operator>>(istream &input, Zawodnik &zawodnik);

protected:
    string m_pozycja;     ///< pozycja na boisku zawodnika
    int m_numer;          ///< numer zawodnika
    int m_liczbaWystepow; ///< liczba wystepow zawodnika
    int m_liczbaGoli;     ///< liczba goli zawodnika
};
