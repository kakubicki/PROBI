#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "trener.h"
#include "zawodnik.h"
#include "pracownik_klubu.h"
#include "junior.h"
#include "klub.h"

using namespace std;

/// Metoda zapisujaca stan klubu do pliku txt
void zapiszPlik(Klub k1, string filename) {
    ofstream plik;
    plik.open(filename.c_str(), ios_base::out | ios_base::app);

    if(!plik.good()){
        cout << "Plik nie zostal otwarty poprawnie" << endl;
        return;
    }

    if(plik.is_open()){
        for (int i = 0; i < k1.pracownicy.size(); ++i){
            plik << k1.pracownicy[i] << endl;
        }
    plik.close();
    }
}

/**
    / Próbna metoda odczytujaca stan klubu z pliku txt
    / Nie bylem w stanie dobrze zaprojektowac metody bez możliwości zarejestrownaia w jaki sposob dane zapisuja sie do pliku
*/
void odczytajPlik(string filename){
    ifstream plik;
    plik.open(filename.c_str(), ios_base::in);
    string tmp;

    if(!plik.good()){
        cout << "Plik nie zostal otwarty poprawnie" << endl;
        return;
    }

    if(plik.good()){
        while(plik >> tmp){
            cout << tmp << " " << endl;
        }

    plik.close();
    }
}

/**
    / Próbne metoda odczutujace i zapisujace byle jaki plik txt
    / w celu upewnienia sie czy na pewno funkcja odczytywania i zapisywania danych z i do pliku txt nie dziala
*/
void loadFile(string filename){
    ifstream plik(filename.c_str(), ios::in);
    string tmp;

    if(!plik.good()){
        cout << "Plik nie zostal otwarty poprawnie" << endl;
        return;
    }

    while(plik >> tmp){
        cout << tmp << " ";
    }
    plik.close();
}

void saveToFile(string filename){
    ofstream plik(filename.c_str(), ios::out | ios::trunc);

    if(!plik.good()){
        cout <<"plik nie zostal otwarty poprawnie" << endl;
        return;
    }

    plik << "czy tym razem sie otworzy?" << endl;

    plik.close();
}

int main1()
{

/**
     / inicjalizacja danych z pliku, badz gdy sie plik nie otwiera to z wpisania obiektow na sztywno

     / niestety mialem problem z utowrzeniem pliku tekstowego, po roznych probach wywolania funkcji zapisujacych pracownikow klubu do pliku txt
     / wykonalem probe utworzenia przykladowego pliku txt stosujac kod dr Kryszyna z projektu w06_03_pliki
     / jednakze i w tym przypadku plik nie chcial sie utworzyc,
     / zatem ze zwazajac na problemy techniczne jestem zmuszony oddac prace bez wykonanaia zadania nr 5 z tresci projektu
*/

    Klub k1("Legia Warszawa");

    Zawodnik z1 ("Leo", "Messi", 70, "Napastnik", 10, 770, 800);
    Zawodnik z2 ("Cristiano", "Ronaldo", 60, "Napastnik", 7, 900, 500);
    Zawodnik z3 ("Robert", "Lewandowski", 80, "Napastnik", 9, 400, 999);
    Junior j1 ("Kylian", "Mbappe", 50, 30, "Napastnik", 7, 200, 100);
    Junior j2 ("Kacper", "Kubicki", 90, 20, "Pomocnik", 11, 2, 10);

    k1.pracownicy.push_back(&z1);
    k1.pracownicy.push_back(&z2);
    k1.pracownicy.push_back(&z3);
    k1.pracownicy.push_back(&j1);
    k1.pracownicy.push_back(&j2);

    //zapiszPlik(k1, "k1.txt");

    while(true){
        cout << "MENU PROGRAMU" << endl;
        cout << "-----------------------" << endl;
        cout << "Wybierz opcje:" << endl;
        cout << "1. Wypisz pracownikow klubu" << endl;
        cout << "2. Wyslij trenera na szkolenie" << endl;
        cout << "3. Zrob trening druzynowy" << endl;
        cout << "4. Wyjscie" << endl;
        int wybor;
        cin >> wybor;
        system("cls");
        switch(wybor){
        case 1:
            cout << "Lista pracownikow klubu" << endl;
            k1.wypiszPracownikow();
            cout << " " << endl;
            break;
        case 2:
            k1.wyslijTreneraNaSzkolenie();
            cout << " " << endl;
            break;
        case 3:
            k1.trenujZespol();
            cout << " " << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Bledny wybor" << endl;
            break;
        }
    }
    return 0;
}

int main(){
    main1();
    return 0;
}

