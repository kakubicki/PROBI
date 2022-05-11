#include "klub.h"
#include "trener.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int Klub::liczbaKlubow = 0;

int Klub::getLiczbaKlubow() {
    return liczbaKlubow;
}

void Klub::wypiszPracownikow(){
    for (int i = 0; i < pracownicy.size(); i++){
        cout << *pracownicy[i] << endl;
    }
}

void Klub::wyslijTreneraNaSzkolenie(){
    trener->trenuj(1);
}

void Klub::trenujZespol() {
    for (int i = 0; i < pracownicy.size(); i++){
        if (pracownicy[i] != trener){
            pracownicy[i]->trenuj(trener->getUmiejetnosci());
        }
    }
}

Klub::Klub () {
    liczbaKlubow++;
    m_nazwa = "brak nazwy";
    trener = new Trener();
    pracownicy.push_back(trener);
}

Klub::Klub (string nazwa) {
    liczbaKlubow++;
    m_nazwa = nazwa;
    trener = new Trener();
    pracownicy.push_back(trener);
}

Klub::Klub (const Klub &klub) {
    m_nazwa = klub.m_nazwa;
    trener = klub.trener;
    pracownicy.push_back(klub.trener);
}

Klub::~Klub () {
    liczbaKlubow--;
}
