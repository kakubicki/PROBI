#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "kontener.h"
#include "pracownik_klubu.h"
#include "zawodnik.h"
#include "junior.h"
#include "trener.h"


using namespace std;

int main()
{
    cin.exceptions(ifstream::failbit | ifstream::badbit);

    Kontener<Zawodnik> kontener;
    int obiekt = 0;
    string plik ="";

    while(true) {
        cout << "MENU PROGRAMU" << endl;
        cout << "-----------------------" << endl;
        cout << "Wybierz opcje:" << endl;
        cout << "1. Dodaj obiekty do kontenera" << endl;
        cout << "2. Usun obiekt z kontenera" << endl;
        cout << "3. Wyswietl aktualny stan kontenera" << endl;
        cout << "4. Wybierz obiekt" << endl;
        cout << "5. Zmien kolejnosc obiektow" << endl;
        cout << "6: Zapisz stan obiektu do pliku" << endl;
        cout << "7: Odczytaj stan obiektu z pliku" << endl;
        cout << "8. Testowanie kontenera" << endl;
        cout << "9. Wyjscie z programu" << endl;
        int wybor;
        cin >> wybor;
        switch(wybor) {
        case 1:
            int numer;
            do {
                cout << "Liczba obeiktow do dodania: " << endl;
                try {
                    numer = 0;
                    cin >> numer;
                }
                catch (ifstream::failure) {
                    cout << "Nie podano liczby: " << endl;
                    cin.clear();
                    cin.ignore();
                }
            }
            while (numer <= 0);
            for (int i = 0; i < numer; i++) {
                string m_imie, m_nazwisko;
                int m_umiejetnosci;
                cout << "Obiekt" << i + 1 << endl;
                cout << "Imie pracownika: ";
                cin >> m_imie;
                cout << "Nazwisko pracownika: ";
                cin >> m_nazwisko;
                do {
                    m_umiejetnosci = 0;
                    cout << "Rating pracownika: ";
                    try {
                       cin >> m_umiejetnosci;
                    }
                    catch (ifstream::failure) {
                        cout << "Rating nie zostal podany" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                }
                while (m_umiejetnosci <= 0);
                Zawodnik zawodnik(m_imie, m_nazwisko, m_umiejetnosci);
                kontener.dodajElement(zawodnik);
            }
            system("cls");
            cout << "Liczba dodanych obiektow: " << numer << endl;
            break;
        case 2:
            system("cls");
            if (obiekt < kontener.size()) {
                string usun;
                cout << "Czy na pewno chcesz usunac obiekt " << obiekt << "? - kliknij t aby potwierdzic lub inny klawisz aby anulowac: ";
                cin >> usun;
                if (usun == "t"){
                    kontener.usunElement(obiekt);
                    cout << "Usunieto obiekt " << obiekt << endl;
                }
            }
            else {
                cout << "Obiekt " << obiekt << " nie istnieje" << endl;
            }
            break;
        case 3:
            system("cls");
            cout << "Liczba wszystkich obiektow: " << kontener.size() << endl;
            kontener.wsywietlWszystkieObiekty();
            fflush(stdin);
            cout << endl << "Nacisnij [ENTER] aby kontynuowac" << endl;
            cin.get();
            system("cls");
            break;
        case 4:
            system("cls");
            if (kontener.size() != 0) {
                kontener.wsywietlWszystkieObiekty();
                do {
                    cout << "Zmien obiekt: (podaj liczbe z zakresu 0 - " << kontener.size()-1 << " : ";
                    try {
                        cin >> obiekt;
                    }
                    catch (ifstream::failure) {
                        cout << "Nie podano zadnej liczby" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                }
                while (!(obiekt >= 0 && obiekt < kontener.size()));
                system("cls");
                cout << "wybrano obiekt nr " << obiekt << endl;
            }
            else
                cout << "pusty kontener" << endl;
            break;
        case 5:
            system("cls");
            int a, b;
            if (kontener.size() > 1) {
                cout << "Podaj nr obiektow do zamiany" << endl;
                do {
                    cout << "podaj pierwszy obiekt: ";
                    cin >> a;
                    cout << "podaj drugi obiekt: ";
                    cin >> b;
                }
                while (a == b && a, b < 0 && a, b >= kontener.size());
                kontener.zmienKolejnosc(a, b);
                cout << "zmieniono kolejnosc" << endl;
            }
            else {
                cout << "nie mozna dokonac zamiany obiektow w konetnerze" << endl;
            }
            break;
        case 6:
        {
            system("cls");
            cout << "Wpisz nazwe pliku (bez .txt): ";
            cin >> plik;
            kontener.zapiszObiekt(obiekt, plik);

            break;
        }
        case 7:
        {
            system("cls");
            cout << "Wpisz nazwe pliku (bez .txt): ";
            cin >> plik;
            try {
                kontener.wczytajObiekt(plik);
            }
            catch (string e){
                cout << e << endl;
            }
            break;
        }
        case 8:
        {
            system("cls");
            Kontener<Zawodnik> k1, k2, k3;
            Zawodnik z1 ("Leo", "Messi", 70);
            Zawodnik z2 ("Cristiano", "Ronaldo", 60);
            Zawodnik z3 ("Robert", "Lewandowski", 80);
            Zawodnik z4 ("Piotr", "Zielinski", 50);
            cout << "TESTOWANIE KONTENERA" << endl;
            k1.dodajElement(z1);
            k1.dodajElement(z2);
            k1.dodajElement(z3);
            k1.dodajElement(z4);
            cout << "Kontener nr 1 ma " << k1.size() << " obiekty" << endl;
            k2 = k1;
            cout << "wykorzystano operator przypisania k2 = k1" << endl;
            cout << "Kontener nr 2 ma " << k2.size() << " obiekty" << endl;
            if (k1 == k2)
                cout << "Oba kontenery sa takie same" << endl;
            else
                cout << "Kontenery sa rozne" << endl;
            cout << "z kontenera 1 usunieto ostatnio dodany obiekt" << endl;
            k1.usunOstatniElement();
            if (k1 == k2)
                cout << "Oba kontenery sa takie same" << endl;
            else
                cout << "Kontenery sa rozne" << endl;
            cout << "do kontenera 1 ponownie wprowadzono usuniety obiekt" << endl;
            k1.dodajElement(z4);
            if (k1 == k2)
                cout << "Oba kontenery sa takie same" << endl;
            else
                cout << "Kontenery sa rozne" << endl;
            cout << "z kontenera 1 usunieto obiekt nr 2" << endl;
            k1.usunElement(2);
            if (k1 == k2)
                cout << "Oba kontenery są takie same" << endl;
            else
                cout << "Kontenery sa rozne" << endl;
            //k3 = k1 + k2;
            //cout << "Kontener 3 ma " << k3.size() << " obiekty" << endl;


            break;
        }
        case 9:
            return 0;

        }
    }







    return 0;
}
