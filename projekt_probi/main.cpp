#include <iostream>
#include <cstring>
#include "klub.h"


using namespace std;



int main1() {
    Zawodnik z1;
    Zawodnik z2 (8, 30);
    Zawodnik z3 ("Bramkarz", 1, 40);
    Zawodnik z4 (z3);

    Trener t1;
    Trener t2 (11);
    Trener t3 ("Kubicki", 2);
    Trener t4 (t2);

    Klub k1 ("Legia Warszawa");
    Klub k2 (k1);

    cout << "Istnieje obecnie " << Klub::ilosc_klubow << " klubow" << endl;


    return 0;
}

int main2() {
    Klub k1("Legia Warszawa");
    Zawodnik z1 ("Bramkarz", 1, 96);
    Zawodnik z2 ("Napastnik", 9, 170);
    k1.dodajZawodnika(z1);
    cout << k1;
    k1.dodajZawodnika(z2);
    cout << k1; //operator strumieniowy
    return 0;
}

int main3() {
    Zawodnik z1 ("Napastnik", 9, 50);
    Zawodnik z2 ("Napastnik", 9, 50);
    Zawodnik z3 ("Bramkarz", 1, 49);
    cout << "Z1 i Z2 to jest ten sam zawodnik - " << (z1 == z2) << endl; //operator dwuargumentowy
    cout << "Z1 i Z3 to jest ten sam zawodnik - " << (z1 == z3) << endl;
    Klub k1 ("Legia Warszawa");
    k1.dodajZawodnika(z1);
    cout << k1;
    Klub k2;
    k2 = k1; //operator przypisania
    cout << k2;
    cout << "To jest ten sam klub - " << (k1 == k2) << endl;
    k1.dodajZawodnika(z2);
    cout << k1;
    k2.dodajZawodnika(z3);
    cout << k2;
    cout << "To jest ten sam klub - " << (k1 == k2) << endl;
    return 0;
}

int main4() {
    Zawodnik z1 ("Napastnik", 9, 340);
    string s = "Robert Lewandowski" + (string)z1; //operator konwersji
    return 0;
}

int main5() {
    Klub k1 ("FC BARCELONA");
    Zawodnik z1 ("Napastnik", 9, 50);
    k1.dodajZawodnika(z1);
    cout << k1;
    Klub k2;
    k2 = k1;
    cout << k2;
    Zawodnik z2;
    k2.dodajZawodnika(z2);
    cout << k2;
    return 0;
}

int main() {
    //main1();
    //main2();
    //main3();
    //main4();
    main5();

    getchar();
    return 0;
}
