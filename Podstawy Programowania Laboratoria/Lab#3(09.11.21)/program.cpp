#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int tab[100], index=100;

void userData()
{
    for (size_t i = 0; i < index; i++)
    {
        system("CLS");
        cout<<endl<<"Porszę podać "<<i+1<<" liczbę: ";
        cin>>tab[i];
    }

    cout<<"Wypełnono całą tablicę."<<endl;

    system("pause");
}

void naturalData()
{
    system("CLS");

    for (size_t i = 0; i < index; i++)
    {
        tab[i] = i + 1;
    }

    cout<<"Automatyczne uzupełniono tablicę kolejnymi liczbami naturalnymi od 1.."<<endl;

    system("pause");
}

void randomData()
{
    system("CLS");

    int min,max;
    cout<<"Proszę podać zakres z którego będą losowane liczby"<<endl;

    cout<<"Wartość minimalna: ";
    cin>>min;

    cout<<"Wartość maksumalna: ";
    cin>>max;

    srand(time(NULL));

    for (size_t i = 0; i < index; i++)
    {
        tab[i] = min + (
        rand() % (max-min+1));
    }
    system("pause");
}

void sumOfArray()
{
    system("CLS");

    int suma=tab[0];

    for (size_t i = 1; i < index; i++)
    {
        suma+=tab[i];
    }

    cout<<"Suma wszystkich elementów tablicy jest równa: "<<suma<<endl;

    system("pause");
}

void biggestOfArray()
{
    system("CLS");

    int najwiekszy=0;
    
    for (size_t i = 0; i < index; i++)
    {
        if (tab[i] > najwiekszy)
        {
            najwiekszy = tab[i];
        }
    }
    
    cout<<"Największy element w tablicy to: "<<najwiekszy<<endl;

    system("pause");
}

void writeArray()
{
    system("CLS");

    for (size_t i = 0; i < index; i++)
    {
        cout<<"Tab["<<i<<"]="<<tab[i]<<endl;
    }

    system("pause");    
}

void bubbleSort()
{
    system("CLS");

    int tmp;

    for (size_t i = 1; i < index; i++) 
    {
        for (size_t j = 0; j < index - i; j++) 
        {
            if (tab[j] > tab[j + 1]) 
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

void binarySearch()
{
    system("CLS");
    int x, l=0, p=index;

    cout<<"Proszę podać szukaną liczbę: ";
    cin>>x;

    int mid = NULL;
    bool found = false;

    bubbleSort();

    while(l<=p)
	{
		mid = (l + p)/2;
		
		if(tab[mid] == x)
        {
            cout<<"Szukana liczba znajduje się na "<<mid<<" miejscu."<<endl;
            found = true;
            break;
        }			
		if(tab[mid] > x)
		{
        	p = mid - 1;
        }
		else
        {
			l = mid + 1;
        }
    }

    if (found==false)
    {
        cout<<"Szukana liczba nie znajduje się w tablicy."<<endl;
    }
        

    system("pause"); 
}

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    
    for (size_t i = 0; i < index; i++)
    {
        tab[i]=0;
    }
    
    while (true)
    {
        system("CLS");

        int wybor;

        cout<<"Pracujemy na tablicy 100 elementów."<<endl<<endl;
        cout<<"1. Wprowadzenie kolejnych wartości do tablicy przez użytkownika."<<endl;
        cout<<"2. Automatyczne uzupełnienie tablicy kolejnymi liczbami naturalnymi od 1."<<endl;
        cout<<"3. Uzupełnienie tablicy liczbami losowymi z zakresu podanego przez użytkownika."<<endl;
        cout<<"4. Zwrócenie sumy wszystkich elementów w tablicy."<<endl;
        cout<<"5. Zwrócenie największego elementu w tablicy."<<endl;
        cout<<"6. Wyświetlenie wartości zapisanych w tablicy."<<endl;
        cout<<"7. Posortuj tablice poprzez sortowanie bąbelelkowe."<<endl;
        cout<<"8. Przeszukaj binarnie na którym miejscu znajduje się zadana liczba w tablicy posortowanej rosnąco."<<endl<<endl;
        cout<<"Proszę wybrać jedną z podanych opcji: ";
        cin>>wybor;
        switch (wybor)
        {
        case 1:
            userData();
            break;

        case 2:
            naturalData();
            break;
        
        case 3:
            randomData();
            break;

        case 4:
            sumOfArray();
            break;

        case 5:
            biggestOfArray();
            break;

        case 6:
            writeArray();
            break;

        case 7:
            bubbleSort();
            break;
        case 8:
            binarySearch();
            break;
        default:
            break;
        }
    }

    return 0;
}