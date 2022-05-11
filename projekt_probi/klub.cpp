#include "klub.h"
#include <iostream>
#include <cstring>

using namespace std;

int Klub::ilosc_klubow = 0;

int Klub::getIloscKlubow() {
    return ilosc_klubow;
}

void Klub::dodajZawodnika(Zawodnik zawodnik) {
    m_liczba_zawodnikow++;

    Zawodnik *zawodnicy = new Zawodnik[m_liczba_zawodnikow];

    zawodnicy[m_liczba_zawodnikow - 1] = zawodnik;

        for(int i = 0; i < m_liczba_zawodnikow - 1; i++) {
            zawodnicy[i] = m_zawodnicy[i];
        }
    delete [] m_zawodnicy;
    m_zawodnicy = zawodnicy;
}

/*
void Klub::dodajZawodnika(Zawodnik *zawodnik) {
    m_liczba_zawodnikow++;

    Zawodnik **zawodnicy = new Zawodnik*[m_liczba_zawodnikow];

    zawodnicy[m_liczba_zawodnikow - 1] = zawodnik;

        for(int i = 0; i < m_liczba_zawodnikow - 1; i++) {
            *zawodnicy[i] = m_zawodnicy[i];
        }
    delete [] m_zawodnicy;
    m_zawodnicy = *zawodnicy;
    delete [] zawodnicy;
}
*/

bool Klub::operator==(const Klub & k) {
    if (m_nazwa != k.m_nazwa)
        return false;

    if (m_liczba_zawodnikow != k.m_liczba_zawodnikow)
        return false;

    for (int i = 0; i < m_liczba_zawodnikow; i++)
        if (m_zawodnicy[i] != k.m_zawodnicy[i])
            return false;

    return true;
}

ostream& operator<<(ostream &s, Klub &k) {
    return s << "W klubie " << k.m_nazwa << " jest " << k.m_liczba_zawodnikow << " zawodnikow." << endl;
}

Klub& Klub::operator=(const Klub &k) {
    m_nazwa = k.m_nazwa;
    m_liczba_zawodnikow = k.m_liczba_zawodnikow;

    if(m_zawodnicy)
        delete[] m_zawodnicy;

    if(k.m_zawodnicy) {
        m_zawodnicy = new Zawodnik[m_liczba_zawodnikow];

        for (int i = 0; i < m_liczba_zawodnikow; i++)
            m_zawodnicy[i] = k.m_zawodnicy[i];

    }
    else m_zawodnicy = 0;

    return *this;
}

Klub::Klub () {
    ilosc_klubow++;
    cout << "Konstruktor domyslny klub. Aktualna liczba obiektow klasy klub: " << ilosc_klubow << endl;
    m_liczba_zawodnikow = 0;
    m_nazwa = "brak nazwy";
}

Klub::Klub (string nazwa) {
    ilosc_klubow++;
    cout << "Konstruktor wieloargumentowy (nazwa) klub. Aktualna liczba obiektow klasy klub: " << ilosc_klubow << endl;
    m_nazwa = nazwa;
    m_liczba_zawodnikow = 0;
}


Klub::Klub (const Klub &k) {
    ilosc_klubow++;

    cout << "Konstruktor kopiujacy klub. Aktualna liczba obiektow klasy klub: " << ilosc_klubow << endl;

    m_nazwa = k.m_nazwa;
    m_liczba_zawodnikow = k.m_liczba_zawodnikow;

    if (k.m_zawodnicy) {
        m_zawodnicy = new Zawodnik[m_liczba_zawodnikow];

        for(int i = 0; i < m_liczba_zawodnikow; i++) {
            m_zawodnicy[i] = k.m_zawodnicy[i];
        }
    }
    else { m_zawodnicy = nullptr;
    }
}

Klub::~Klub () {
    ilosc_klubow--;

    cout << "~Klub. Aktualna liczba obiektow klasy klub: " << ilosc_klubow <<endl;

    if (m_zawodnicy != nullptr)
        delete[] m_zawodnicy;
}
