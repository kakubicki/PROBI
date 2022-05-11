#pragma once
#include "kontener.h"
#include "pracownik_klubu.h"
#include "zawodnik.h"
#include "junior.h"
#include "trener.h"
#include <iostream>
#include <fstream>



template <class K>
Kontener<K>::Kontener() {
    liczba_elementow = 0;
    poczatek = NULL;
}

template <class K>
void Kontener<K>::dodajElement(const K &obiekt) {
    Wezel<K> *nowy_wezel, *pop_wezel;
    nowy_wezel = new Wezel<K>();
    nowy_wezel -> poprzedni_wezel = NULL;
    nowy_wezel -> nastepny_wezel = NULL;
    nowy_wezel -> obiekt = obiekt;

    if (liczba_elementow == 0){
        poczatek = nowy_wezel;
    }
    else {
        Wezel<K> *tmp;
        tmp = zwrocWskaznikWezla(liczba_elementow - 1);
        tmp -> nastepny_wezel = nowy_wezel;
        if (liczba_elementow > 1){
            pop_wezel = zwrocWskaznikWezla(liczba_elementow - 2);
            tmp -> poprzedni_wezel = pop_wezel;
        }
    }
    liczba_elementow++;
}

template <class K>
void Kontener<K>::usunElement(int numer) {
    if (liczba_elementow == 1 || numer == liczba_elementow - 1) {
        usunOstatniElement();
        return;
    }
    else if(numer == 0) {
        Wezel<K> *tmp;
        tmp = new Wezel<K>();
        tmp = poczatek -> nastepny_wezel;
        tmp -> poprzedni_wezel = NULL;
        delete poczatek;
        poczatek = tmp;
    }
    else {
        Wezel<K> *wezel;
        wezel = zwrocWskaznikWezla(numer);
        wezel -> poprzedni_wezel -> nastepny_wezel = wezel -> nastepny_wezel;
        wezel -> nastepny_wezel -> poprzedni_wezel = wezel -> poprzedni_wezel;
        delete wezel;
    }
    liczba_elementow--;
}

template <class K>
void Kontener<K>::usunOstatniElement() {
    if (liczba_elementow < 2) {
        delete poczatek;
        poczatek = NULL;
    }
    else {
        Wezel<K> *tmp = zwrocWskaznikWezla(liczba_elementow - 2);
        delete tmp -> nastepny_wezel;
    }
    liczba_elementow--;
}

template <class K>
void Kontener<K>::zmienKolejnosc(int a, int b) {
    K element_tmp;
    element_tmp = (*this)[a];
    (*this)[a] = (*this)[b];
    (*this)[b] = element_tmp;
}

template <class K>
void Kontener<K>::zapiszObiekt(int numer, string nazwa_pliku) {
    K obiekt = (*this)[numer];
    nazwa_pliku += string(".txt");
    ofstream plik;
    plik.open(nazwa_pliku);
    plik << obiekt;
    plik.close();
    cout << "Dane zostały zapisane do pliku: " << nazwa_pliku << endl;
}

template <class K>
void Kontener<K>::wczytajObiekt(string nazwa_pliku) {
    K obiekt;
    nazwa_pliku += string(".txt");
    ifstream plik;
    plik.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        plik.open(nazwa_pliku);
    }  catch (ifstream::failure e) {
        throw string (nazwa_pliku + " nie zostal znaleziony");
    }
    plik >> obiekt;
    plik.close();
    cout << "Wczytywanie danych z pliku: " << nazwa_pliku << endl;
}

template <class K>
void Kontener<K>::wsywietlWszystkieObiekty() {
    if (liczba_elementow != 0)
        for (int i = 0; i < liczba_elementow; i++) {
            cout << "Obiekt " << i << endl;
        }
}

template <class K>
Wezel<K>* Kontener<K>::zwrocWskaznikWezla(int numer) const {
    Wezel<K> *wezel = poczatek;
    for (int i = 0; i < numer; i++) {
        if (wezel == NULL)
            return NULL;
        wezel = wezel -> nastepny_wezel;
    }
    return wezel;
}

template <class K>
int Kontener<K>::size() {
    return liczba_elementow;
}

template <class K>
Kontener<K>::~Kontener() {
    while (liczba_elementow > 0)
        usunOstatniElement();
}

template <class K>
Kontener<K>& Kontener<K>::operator=(const Kontener &k) {
    for (int i = 0; i < k.liczba_elementow; i++)
        dodajElement(k[i]);
    return *this;
}

template <class K>
bool Kontener<K>::operator==(const Kontener &k) {
    for (int i = 0; i < k.liczba_elementow; i++)
        if (!(k[i] == (*this)[i]))
            return false;
    return true;
}

template<class K>
K& Kontener<K>::operator[](int i) const {
    return zwrocObiekt(i);
}

template <class K>
K& Kontener<K>::zwrocObiekt(int numer) const {
    return zwrocWskaznikWezla(numer) -> obiekt;
}

/*
template<class K>
Kontener<K>& Kontener<K>::operator+(Kontener& k) {
    k.liczba_elementow = this->liczba_elementow + k.liczba_elementow;
    K obiekt = new Kontener [k.liczba_elementow];
    for (int i = 0; i < k.liczba_elementow; i++) {
        (k[i] = (*this)[i] + k[i]);
    }
    return k;
}
*/



