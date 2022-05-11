#pragma once
#include "pracownik_klubu.h"
#include <iostream>
#include <cstring>

using namespace std;

/// Klasa potomna Trener
class Trener : public PracownikKlubu {
public:
    /// Konstruktor domyslny
    Trener();
    /// Konstruktor z parametrami
    Trener(string imie, string nazwisko, int umiejetnosci, int lataPracy, int liczbaTrofeow);
    /// Konstruktor kopiujacy
    Trener(const Trener &trener);
    /// Destruktor
    ~Trener ();

    /// Statyczna liczba pracownikow
    static int liczbaPracownikow;
    /// Metoda zwracajaca liczbe pracownikow
    static int getLiczbaPracownikow();

    /// Statyczna liczba trenerow
    static int liczbaTrenerow;
    /// Metoda zwracajaca liczbe trenerow
    static int getLiczbaTrenerow();

    /// Metoda zwracajaca lata pracy trenera
    int getLataPracy();
    /// Metoda ustawiajaca lata pracy trenera
    void setLataPracy(int lataPracy);

    /// Metoda zwracajaca liczbe trofeow trenera
    int getLiczbaTrofeow();
    /// Metoda ustawiajaca liczbe trofeow trenera
    void setLiczbaTrofeow(int liczbaTrofeow);

    /// Metoda zwiekszajaca poziom umiejetnosci trenera +1
    void trenuj(int);

    /// Operatory strumieniowe
    friend ostream& operator<<(ostream &output, Trener &trener);
    friend istream& operator>>(istream &input, Trener &trener);

private:
    int m_lataPracy;     ///< lata pracy trenera
    int m_liczbaTrofeow; ///< liczba trofeow trenera
};
