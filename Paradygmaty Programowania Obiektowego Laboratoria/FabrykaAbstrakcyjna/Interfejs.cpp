#include "Interfejs.h"
#include <iostream>
#include <string>

using namespace std;

Interfejs::Interfejs(ListaObecnosci* lista)
{
    this->menuListyObecnosci(lista);
}

int Interfejs::menuListyObecnosci(ListaObecnosci* lista)
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
            if (lista->wyswietlListe(0) == to_string(NULL))
            {
                cout << "Lista pusta, dodaj studenta\n";
            }
            else
            {
                for (int i = 0; i < 30; i++)
                {
                    if (lista->wyswietlListe(i) == to_string(NULL))
                        break;
                    cout << i + 1 << ". " << lista->wyswietlListe(i) << endl;
                }
            }
            break;
        case 2:
            system("cls");
            this->menuFabrykiStudentow(lista);
            break;
        case 3:
            system("cls");
            this->ustawianieObecnosciStudentow(lista);
            break;
        case 4:
            system("cls");
            this->wyswietlanieObecnosciStudentow(lista);
            break;
        case 5:
            return 0;
        default:
            break;
        }
        system("pause");
    }
}

int Interfejs::menuFabrykiStudentow(ListaObecnosci* lista)
{
    FabrykaStudentow* fabryka{};
    Student* student{};

    string imie, nazwisko, identyfikator, dataUrodzenia;
    int nrAlbumu;

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
        system("cls");

        cout << "Prosze podac imie studenta: ";
        cin >> imie;

        cout << "Prosze podac nazwisko studenta: ";
        cin >> nazwisko;


        cout << "Prosze podac numer albumu studenta: ";
        cin >> nrAlbumu;


        cout << "Prosze podac identyfikator studenta: ";
        cin >> identyfikator;


        cout << "Prosze podac date urodzenia studenta (dd/mm/rrrr): ";
        cin >> dataUrodzenia;

        system("cls");

        fabryka = new FabrykaPolakow;
        student = fabryka->stoworzStudenta(imie,nazwisko,identyfikator,dataUrodzenia,nrAlbumu);
        if (student == NULL)
        {
            cout << "Nie dodano studenta.\n";
            break;
        }
        else
        {
            switch (lista->dodajOsobe(student))
            {
            case 0:
                cout << "Dodano studenta\n";
                break;
            case 1:
                cout << "Student jest juz na liscie\n";
                break;
            case 2:
                cout << "Brak miejsca na liscie.\n";
                break;
            default:
                break;
            }
        }
        

        break;
    case 2:
        system("cls");

        cout << "Prosze podac imie studenta: ";
        cin >> imie;

        cout << "Prosze podac nazwisko studenta: ";
        cin >> nazwisko;


        cout << "Prosze podac numer albumu studenta: ";
        cin >> nrAlbumu;


        cout << "Prosze podac identyfikator studenta: ";
        cin >> identyfikator;


        cout << "Prosze podac date urodzenia studenta (dd/mm/rrrr): ";
        cin >> dataUrodzenia;

        fabryka = new FabrykaPortugalczykow;
        student = fabryka->stoworzStudenta(imie, nazwisko, identyfikator, dataUrodzenia, nrAlbumu);

        lista->dodajOsobe(student);
        break;
    case 3:
        return 0;
    default:
        return 2; //b³êdny wybór
    }
    return 1;
}

void Interfejs::ustawianieObecnosciStudentow(ListaObecnosci* lista)
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

    system("cls");

    switch (lista->ustawObecnosc(identyfikator, data, obecnosc))
    {
    case 0:
        cout << "OK\n";
        break;
    case 1:
        cout << "Obecnosc juz ustawiona.\n";
        break;
    case 2:
        cout << "Brak miejsca na liscie.\n";
        break;
    case 3:
        cout << "Nie ma takiej osoby.\n";
        break;
    case 4:
        cout << "Lista studentow jest pusta.\n";
        break;
    default:
        break;
    }
    }

void Interfejs::wyswietlanieObecnosciStudentow(ListaObecnosci* lista)
{
    string identyfikator, data;
    cout << "Prosze podac identyfikator studenta: ";
    cin >> identyfikator;
    cout << "Prosze podac date zajec (dd/mm/rrrr): ";
    cin >> data;

    system("cls");
    switch (lista->wyswietlObecnosc(identyfikator, data))
    {
    case 0:
        cout << "Osoba byla obecna.\n";
        break;
    case 1:
        cout << "Osoba byla nieobecna.\n";
        break;
    case 2:
        cout << "Lista pusta.\n";
        break;
    case 3:
        cout << "Brak zajec o takiej dacie.\n";
        break;
    case 4:
        cout << "Brak osoby na liscie.\n";
        break;
    default:
        break;
    }
    
}
