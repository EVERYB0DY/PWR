#include <iostream>
#include <cstring>

using namespace std;

void wprowadzanieTekstu(char tekst[])
{
    cout<<"Proszę podać ciąg znaków: ";

    cin.ignore();
    cin.getline(tekst,257);

    system("pause");
}

void wypisywanieTekstu(char tekst[])
{
    for (size_t i = 0; i < 257; i++)
    {
        if (tekst[i]=='\0')
        {
            break;
        }
        cout<<tekst[i];
    }
    cout<<endl;
    system("pause");
}

void iloscZnakow(char tekst[])
{
    int ilosc=0;
    
    for (size_t i = 0; i < 257; i++)
    {
        if(tekst[i]=='\0')
        {
            ilosc=i;
            break;
        }
    }

    cout<<"Ciąg znaków ma długość: "<<ilosc<<endl;
    system("pause");    
}

void zamianaWielokosci(char tekst[], bool male)
{
    for (size_t i = 0; i < 257; i++)
    {
        if (male == true)
        {
            if ((int)tekst[i] > 64 && (int)tekst[i]<91)
            {
                tekst[i]=(int)tekst[i]+32;
            }
        }
        else
        {
            if ((int)tekst[i] > 96 && (int)tekst[i] < 123)
            {
                tekst[i]=(int)tekst[i]-32;
            }   
        }   
    }
}

void histogram(char tekst[])
{
    int ilosc[26] = {0};
    
    zamianaWielokosci(tekst,true);

    for (size_t i = 0; i < 257; i++)
    {
        if(tekst[i]=='\0')
        {
            break;
        }

        if((int)tekst[i] > 96 && (int)tekst[i] < 123)
        {
            ilosc[((int)tekst[i] % 27) - 1]++;
        }
    }

    for (size_t i = 0; i < 26; i++)
    {
        cout<<(char)(97 + i)<<'\32';
        for (size_t j = 0; j < ilosc[i]; j++)
        {
            cout<<"#";
        }
        cout<<endl;        
    }
    cout<<endl;
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    
    char tablica[257] = {'\0'};

    system("cls");

    while(true)
    {
        system("cls");

        int wybor=0;
        
        cout<<"1. Wprowadź tekst."<<endl;
        cout<<"2. Wyświetl tekst."<<endl;
        cout<<"3. Wypisz liczbę znaków tekstu."<<endl;
        cout<<"4. Ustaw wszystkie litery na duże."<<endl;
        cout<<"5. Ustaw wszystkie litery na małe."<<endl;
        cout<<"6. Wyświetl histogram."<<endl<<endl;

        cout<<"Podaj wybór opcji: ";
        cin>>wybor;


        switch (wybor)
        {
        case 1:
            system("cls");
            wprowadzanieTekstu(tablica);
            break;
        
        case 2:
            system("cls");
            wypisywanieTekstu(tablica);
            break;

        case 3:
            system("cls");
            iloscZnakow(tablica);
            break;

        case 4:
            system("cls");
            zamianaWielokosci(tablica, false);
            break;

        case 5:
            system("cls");
            zamianaWielokosci(tablica, true);
            break;

        case 6:
            system("cls");
            histogram(tablica);
            break;

        //case 1:
        //    break;
        
        default:
            system("cls");
            cout<<"Brak takiej opcji."<<endl;
            break;
        }
    }

    

    
    

    
    

    return 0;
}