#pragma once
#include <iostream>
#include <cstring>

using namespace std;

/// Klasa abstrakcyjna Pracownik Klubu
class PracownikKlubu {
public:
    /// Konstruktor domyslny
    PracownikKlubu();
    /// Konstruktor z parametrami
    PracownikKlubu(string imie, string nazwisko, int umiejetnosci);
    /// Konstruktor kopiujacy
    PracownikKlubu(const PracownikKlubu &pracownik);
    /// Destruktor
    virtual ~PracownikKlubu();

    /// Statyczna liczba pracownikow
    static int liczbaPracownikow;
    /// Metoda zwracajaca liczbe pracownikow
    static int getLiczbaPracownikow();

    /// Metoda zwracajaca poziom umiejetnosci pracownika
    int getUmiejetnosci();

    /// Wirtualna metoda zwiekszajaca poziom umiejetnosci pracownika
    virtual void trenuj(int) = 0;

    /// Operatory strumieniowe
    friend ostream& operator<<(ostream &output, PracownikKlubu &pracownik);
    friend istream& operator>>(istream &input, PracownikKlubu &pracownik);

protected:
    string m_imie;      ///< imie pracownika
    string m_nazwisko;  ///< nazwisko pracownika
    int m_umiejetnosci; ///< poziom umiejetnosci pracownika
};
