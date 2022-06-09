#include "Interfejs.h"
#include <iostream>
#include <string>

using namespace std;

int Interfejs::menuListyObecnosci()
{
    while (true)
    {
        system("cls");
        int opcja = 0;
        cout << "MENU\n";
        cout << "1. Wyswietl liste obecnosci.\n";
        cout << "2. Dodaj studenta do listy obecnosci.\n";
        cout << "3. Ustaw obecnosc studenta w danym dniu.\n";
        cout << "4. Wyswietl obecnosc studenta w danym dniu.\n";
        cout << "5. Zamknij program.\n";
        cout << endl;
        cout << "Prosze wybarc opcje: ";
        cin >> opcja;

        switch (opcja)
        {
        case 1:
            system("cls");
            if (this->lista.wyswietlListe() == 1)
            {
                cout << "Lista pusta, dodaj studenta.\n";
            }
            break;
        case 2:
            system("cls");
            this->menuFabrykiStudentow();
            break;
        case 3:
            system("cls");
            this->ustawianieObecnosciStudentow();
            break;
        case 4:
            system("cls");
            this->wyswietlanieObecnosciStudentow();
            break;
        case 5:
            return 0;
        default:
            break;
        }
        system("pause");
    }
}

int Interfejs::menuFabrykiStudentow()
{
    FabrykaStudentow* fabryka{};
    Student* student{};

    int opcja = 0;
    cout << "Jakiej narodowosci jest student?\n";
    cout << "1. Polak.\n";
    cout << "2. Portugalczyk.\n";
    cout << "3. Cofnij.\n";
    cout << endl;
    cout << "Prosze wybarc opcje: ";
    cin >> opcja;

    switch (opcja)
    {
    case 1:
        fabryka = new FabrykaPolakow;
        student = fabryka->stoworzStudenta();
        system("cls");
        this->dodawanieStudentow(student);
        break;
    case 2:
        fabryka = new FabrykaPortugalczykow;
        student = fabryka->stoworzStudenta();
        system("cls");
        this->dodawanieStudentow(student);
        break;
    case 3:
        return 0;
    default:
        return 2; //b³êdny wybór
    }
    return 1;
}

void Interfejs::dodawanieStudentow(Student* student)
{
    string tmp;
    int pmt = NULL;

    cout << "Prosze podac imie studenta: ";
    cin >> tmp;
    if (student->setImie(tmp) == 0)
    {
        cout << "OK" << endl << endl;
    }
    tmp.clear();

    cout << "Prosze podac nazwisko studenta: ";
    cin >> tmp;
    if (student->setNazwisko(tmp) == 0)
    {
        cout << "OK" << endl << endl;
    }
    tmp.clear();

    cout << "Prosze podac numer albumu studenta: ";
    cin >> pmt;
    if (student->setNrAlbumu(pmt) == 0)
    {
        cout << "OK" << endl << endl;
    }
    pmt=NULL;

    cout << "Prosze podac identyfikator studenta: ";
    cin >> tmp;
    if (student->setIdentyfikator(tmp) == 0)
    {
        cout << "OK" << endl << endl;
    }
    else
    {
        cout << "Nieprawidlowy identyfikator dla danej narodowosci." << endl << endl;
    }
    tmp.clear();

    cout << "Prosze podac date urodzenia studenta (dd/mm/rrrr): ";
    cin >> tmp;
    if (student->setDataUrodzenia(tmp) == 0)
    {
        cout << "OK" << endl << endl;
    }
    else
    {
        cout << "Nieprawidlowa data urodzenia studenta." << endl << endl;
    }
    tmp.clear();

    this->lista.dodajOsobe(student);
}

void Interfejs::ustawianieObecnosciStudentow()
{
    string identyfikator, data;
    bool obecnosc;
    int tmp;
    cout << "Prosze podac identyfikator studenta: ";
    cin >> identyfikator;
    cout << "Prosze podac date zajec (dd/mm/rrrr): ";
    cin >> data;
    cout << "Czy student jest obecny (1-tak, 0-nie): ";
    cin >> tmp;
    obecnosc = tmp;

    tmp = this->lista.ustawObecnosc(identyfikator, data, obecnosc);
    if (tmp != 0)
    {
        if (tmp == 1)
            cout << "Osoby nie ma na liscie.\n";
        else if (tmp == 2)
            cout << "Brak miejsca w tablicy obecnosci.\n";
        else if (tmp == 3)
            cout << "Obecnosc juz ustawiona.\n";
        else
            cout << "Pusta lista osob.\n";
    }
    else
    {
        cout << "OK" << endl;
    }
}

void Interfejs::wyswietlanieObecnosciStudentow()
{
    string identyfikator, data;
    cout << "Prosze podac identyfikator studenta: ";
    cin >> identyfikator;
    cout << "Prosze podac date zajec (dd/mm/rrrr): ";
    cin >> data;

    system("cls");

    this->lista.wyswietlObecnosc(identyfikator, data);
}
