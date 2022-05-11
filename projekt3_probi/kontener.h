#pragma once
#include <iostream>

using namespace std;

template <class K>
struct Wezel {
    K obiekt;
    Wezel *poprzedni_wezel;
    Wezel *nastepny_wezel;
};

template <class K>
class Kontener {
public:
    Kontener();
    void dodajElement(const K &obiekt);
    void usunElement(int numer);
    void usunOstatniElement();
    K& zwrocObiekt(int numer) const;
    void zmienKolejnosc(int x, int y);
    void zapiszObiekt(int numer, string nazwa_pliku);
    void wczytajObiekt(string nazwa_pliku);
    void wsywietlWszystkieObiekty();
    Wezel<K>* zwrocWskaznikWezla(int numer) const;
    int size();

    ~Kontener();

    K& operator[](int i) const;
    Kontener& operator=(const Kontener &);
    bool operator==(const Kontener &k);

    Kontener& operator+(Kontener& k);
    void moveToEnd(int numer);

private:
    Wezel<K> *poczatek;
    int liczba_elementow;
};

#include "kontener.cpp"
