#include <iostream>

using namespace std;

int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

bool czyPierwsza(int liczba)
{
    if (liczba == 0 || liczba == 1)
    {
        return false;
    }
    else
    {
        for (size_t i = 2; i <= liczba / 2; i++)
        {
            if (liczba % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void zad1()
{
    int sumaZad1 = 0;

    while (true)
    {
        int liczba;

        cout << "Podaj liczbę: ";
        cin >> liczba;

        if (liczba >= (-15) && liczba <= 15)
        {
            sumaZad1 += liczba;
        }
        else if (liczba == 99)
        {
            break;
        }
        system("CLS");
    }

    cout << "Suma wynosi: " << sumaZad1 << endl;

    system("pause");
}

void zad2()
{
    int sumaLiczbPierszych = 0;

    for (size_t i = 0; i < 10; i++)
    {
        int liczba;

        cout << "Podaj liczbę: ";
        cin >> liczba;

        if (czyPierwsza(liczba) == true)
        {
            sumaLiczbPierszych += liczba;
        }
        system("CLS");
    }

    cout << "Podano " << sumaLiczbPierszych << " liczb pierwszych." << endl;

    system("pause");
}

void zad3()
{
    int a, b;

    cout << "Podaj pierszą liczbę: ";
    cin >> a;
    cout << "Podaj drugą liczbę: ";
    cin >> b;

    cout << "Najwiekszy wspólny dzienlnik podanych liczb to " << NWD(a, b) << endl;

    system("pause");
}

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    while (true)
    {
        int opcja;

        system("CLS");

        cout << "MENU" << endl;
        cout << "1. Zadanie 1" << endl;
        cout << "2. Zadanie 2" << endl;
        cout << "3. Zadanie 3" << endl;
        cout << "4. Wyjdź"<< endl;
        cout << endl
             << "Wybierz jedną z powyżej podanych opcji: ";
        cin >> opcja;
        system("CLS");

        switch (opcja)
        {
        case 1:
            cout << "Podaj liczby całkowite oddzielając je enterem."
                 << endl
                 << "W celu zakończenia wpisywania liczb podaj liczbę 99."
                 << endl
                 << "Program wyliczy sumę liczb z zakresu od -15 do 15 włącznie."
                 << endl;

            system("pause");
            
            system("CLS");

            zad1();

            break;

        case 2:
            cout << "Podaj 10 liczb całkowitych oddzielając je enterem."
                 << endl
                 << "Program zliczy ilość podanych liczb pierwszych."
                 << endl;

            system("pause");
            
            system("CLS");

            zad2();

            break;

        case 3:
            cout << "Podaj dwie liczby całkowite dodatnie oddzielając je enterem."
                 << endl
                 << "Program wyliczy największy wspólny dzielnik podanych liczb."
                 << endl;

            system("pause");
            
            system("CLS");

            zad3();
            
            break;

        case 4:
            return 0;

        default:
            break;
        }
    }

    return 0;
}