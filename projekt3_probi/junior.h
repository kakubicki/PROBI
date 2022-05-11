#pragma once
#include "zawodnik.h"
#include <iostream>
#include <cstring>

using namespace std;

/// Klasa potomna Junior
class Junior : public Zawodnik {
public:
    /// Konstruktor domyslny
    Junior();
    /// Konstruktor z parametrami
    Junior(string imie, string nazwisko, int umiejetnosci, int potencjal, string pozycja, int numer, int liczbaWystepow, int liczbaGoli);
    /// Konstruktor kopiujacy
    Junior(const Junior &junior);
    /// Destruktor
    ~Junior();

    /// Statyczna liczba pracownikow
    static int liczbaPracownikow;
    /// Metoda zwracajaca liczbe pracownikow
    static int getLiczbaPracownikow();

    /// Statyczna liczba juniorow
    static int liczbaJuniorow;
    /// Metoda zwracajaca liczbe juniorow
    static int getLiczbaJuniorow();

    /// Metoda zwracajaca poziom umiejetnosci juniora
    int getUmiejetnosci();
    /// Metoda ustawiajaca poziom umiejetnosci juniora
    void setUmiejetnosci(int umiejetnosci);

    /// Metoda zwracajaca potencjal juniora
    int getPotencjal();
    /// Metoda ustawiajaca potencjal juniora
    void setPotencjal(int potencjal);

    /// Metoda zwracajaca numer juniora
    int getNumer();
    /// Metoda ustawiajaca numer juniora
    void setNumer(int numer);

    /// Metoda zwiekszajaca poziom umiejetnosci juniora w zaleznosci od poziomu umiejetnosci trenera
    void trenuj(int);

    /// Operatory strumieniowe
    friend ostream& operator<<(ostream &output, Junior &junior);
    friend istream& operator>>(istream &input, Junior &junior);

private:
    int m_potencjal; ///< potencjal juniora
};
