#pragma once
#include "pracownik_klubu.h"
#include "trener.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/// Klasa wizualizujaca mechanizmy dziedziczenia Klub
class Klub {
public:
    /// Konstruktor domyslny
    Klub ();
    /// Konstruktor z parametrem
    Klub (string nazwa);
    /// Konstruktor kopiujacy
    Klub (const Klub &klub);
    /// Destruktor
    ~Klub ();

    /// Statyczna liczba klubow
    static int liczbaKlubow;
    /// Metoda zwracajaca liczbe klubow
    static int getLiczbaKlubow();

    /// Metoda wypisujaca na konsoli wszystkich pracownikow znajdujacych sie w klubie
    void wypiszPracownikow();
    /// Metoda zwiekszajaca poziom umiejetnosci trenera
    void wyslijTreneraNaSzkolenie();
    /// Metoda zwiekszajaca poziom umiejetnosci wszystkich zawodnikow i juniorow bedacych w klubie
    void trenujZespol();

    /// Kontener wszystkich pracownikow klubu
    vector<PracownikKlubu*> pracownicy;

private:
    string m_nazwa; ///< nazwa klubu
    Trener *trener; ///< dynamicznie dodawany do klubu trener, bezposrednio dodawany do wektora pracownikow klubu
};
