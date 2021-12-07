#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct student
{
    int ID;
    string imie;
    string nazwisko;
    int wiek;
    string plec;
};

void odczytaj(vector<student> &baza)
{
    fstream plik;
    plik.open("student.db", fstream::in);

    if(plik.is_open())
    {
        while (!plik.eof())
        {
            student tmp;
            plik >> tmp.ID;
            plik >> tmp.imie;
            plik >> tmp.nazwisko;
            plik >> tmp.wiek;
            plik >> tmp.plec;

            baza.push_back(tmp);
        }
    }
    else
    {
        cout<<"Nie można otworzyć pliku!\n";
    }
    
    plik.close();
    baza.shrink_to_fit();
}

void wyswietl(vector<student> baza)
{
    for (size_t i = 0; i < baza.size(); i++)
    {
        cout<<baza[i].ID<<" "<<baza[i].imie<<" "<<baza[i].nazwisko<<" "<<baza[i].wiek<<" "<<baza[i].plec<<"\n";
    }    
}

void zapisz(vector<student> baza)
{
    fstream plik;
    plik.open("student.db", fstream::out);

    if (plik.is_open())
    {
        for (size_t i = 0; i < baza.size(); i++)
        {
            plik<<baza[i].ID<<" "<<baza[i].imie<<" "<<baza[i].nazwisko<<" "<<baza[i].wiek<<" "<<baza[i].plec<<"\n";
        }
    }
    else
    {
        cout<<"Nie można otworzyć pliku!\n";
    }

    plik.close();
}

void usun(vector<student> &baza)
{
    wyswietl(baza);

    int indeks;
    cout<<"Którego studenta chcesz usunąć (1 - "<<baza.size()<<")? ";
    cin>>indeks;

    baza.erase(baza.begin()+indeks-1);
    baza.shrink_to_fit();
}

void dodaj(vector<student> &baza)
{
    student tmp;
    cout<<"Wszelkie wartości wpisywać cyframi lub małymi literami.\n";
    cout<<"ID: ";
    cin>>tmp.ID;
    cout<<"Imię: ";
    cin>>tmp.imie;
    cout<<"Nazwisko: ";
    cin>>tmp.nazwisko;
    cout<<"Wiek: ";
    cin>>tmp.wiek;
    cout<<"Płeć: ";
    cin>>tmp.plec;

    baza.push_back(tmp);
    baza.shrink_to_fit();
}

void losuj(vector<student> &baza)
{
    srand(time(NULL));

    student tmp;

    tmp.ID = 1 + rand() % 300000;

    string imiona[20] = {"Zuzanna", "Zofia", "Hanna", "Julia", "Maja", "Laura", "Oliwia", "Alicja", "Lena", "Pola", "Antoni", "Jan", "Aleksander", "Franciszek", "Jakub", "Szymon", "Mikołaj", "Leon", "Filip", "Stanisław"};

    tmp.imie = imiona[(rand()%20)];

    int liczba;
    liczba = 1 + rand()%2;

    if (liczba % 2 == 0)
    {
        tmp.plec = "kobieta";
        tmp.nazwisko = imiona[(rand()%20)] + "owska";
    }
    else
    {
        tmp.plec = "mężczyzna";
        tmp.nazwisko = imiona[(rand()%20)] + "owski";
    }
    

    tmp.wiek = 1 + rand() % 99;
    
    baza.push_back(tmp);
    baza.shrink_to_fit();
}

void wyszukaj(vector<student> baza)
{
    int indeks;

    cout<<"Proszę podać indeks szukanego studenta: ";
    cin>>indeks;

    for (size_t i = 0; i < baza.size(); i++)
    {
        if (indeks==baza[i].ID)
        {
            cout<<baza[i].ID<<" "<<baza[i].imie<<" "<<baza[i].nazwisko<<" "<<baza[i].wiek<<" "<<baza[i].plec<<"\n";
            break;
        }
    }
    
}

void filtruj(vector<student> baza)
{
    int opcja;
    cout<<"Opcje filtru.\n";
    cout<<"1. Po imieniu.\n";
    cout<<"2. Po płci.\n";
    cout<<"Proszę wprowadzić opcję: ";
    cin>>opcja;

    if (opcja==1)
    {
        cout<<"Porszę podać imię(z dużej litery): ";
        string imie;
        cin>>imie;
        for (size_t i = 0; i < baza.size(); i++)
        {
            if (imie==baza[i].imie)
            {
                cout<<baza[i].ID<<" "<<baza[i].imie<<" "<<baza[i].nazwisko<<" "<<baza[i].wiek<<" "<<baza[i].plec<<"\n";
            }
        }
        
    }
    else if(opcja==2)
    {
        cout<<"Porszę podać płeć(z małej litery): ";
        string plec;
        cin>>plec;
        for (size_t i = 0; i < baza.size(); i++)
        {
            if (plec==baza[i].plec)
            {
                cout<<baza[i].ID<<" "<<baza[i].imie<<" "<<baza[i].nazwisko<<" "<<baza[i].wiek<<" "<<baza[i].plec<<"\n";
            }
        }
    }
}

void sortuj(vector<student> &baza)
{
    int opcja;
    cout<<"Opcje sortowania.\n";
    cout<<"1. Po indeksie.\n";
    cout<<"2. Po wieku.\n";
    cout<<"Proszę wprowadzić opcję: ";
    cin>>opcja;

    if (opcja==1)
    {
        sort(baza.begin(), baza.end(),[](student a, student b){return a.ID<b.ID;});
    }
    else if(opcja==2)
    {
        sort(baza.begin(), baza.end(),[](student a, student b){return a.wiek>b.wiek;});
    }
}

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    vector<student> student;

    while (true)
    {
        system("cls");
        cout<<"MENU\n";
        cout<<"1. wczytanie z pliku\n";
        cout<<"2. zapis do pliku\n";
        cout<<"3. wyświetlenie bazy\n";
        cout<<"4. usuwanie\n";
        cout<<"5. dodawanie\n";
        cout<<"6. losowanie\n";
        cout<<"7. wyszukiwanie\n";
        cout<<"8. filtrowanie\n";
        cout<<"9. sortowanie\n";
        cout<<"Proszę wybrać opcję: ";
        int opcja;
        cin>>opcja;
        switch (opcja)
        {
            case 1:
                system("cls");
                odczytaj(student);
                cout<<"Dane odczytane z pliku poprawnie.\n";
                system("pause");
                break;
            case 2:
                system("cls");
                zapisz(student);
                cout<<"Dane zapisane do pliku poprawnie.\n";
                system("pause");
                break;
            case 3:
                system("cls");
                wyswietl(student);
                system("pause");
                break;
            case 4:
                system("cls");
                usun(student);
                cout<<"Poprawnie usunięto studenta z bazy.\n";
                system("pause");
                break;
            case 5:
                system("cls");
                dodaj(student);
                cout<<"Poprawnie dodano studenta do bazy.\n";
                system("pause");
                break;
            case 6:
                system("cls");
                losuj(student);
                cout<<"Poprawnie wylosowano i dodano studenta do bazy.\n";
                system("pause");
                break;
            case 7:
                system("cls");
                wyszukaj(student);
                system("pause");
                break;
            case 8:
                system("cls");
                filtruj(student);
                system("pause");
                break;
            case 9:
                system("cls");
                sortuj(student);
                cout<<"Poprawnie posortowano bazę.\n";
                system("pause");
                break;
            default:
                break;
        }
        
    }
    
    return 0;
}