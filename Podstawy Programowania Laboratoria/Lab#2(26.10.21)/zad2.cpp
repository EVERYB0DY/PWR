#include <iostream>

using namespace std;

bool czyPierwsza(int liczba)
{
    if(liczba==0||liczba==1)
    {
        return false;
    }
    else
    {
        for (size_t i = 2; i <= liczba/2; i++)
        {
            if(liczba%i==0)
            {
                return false;
            }
        }
        
    }
    return true;
}

int main()
{
    int sumaLiczbPierszych=0;

    for (size_t i = 0; i < 10; i++)
    {
        int liczba;

        cout<<"Podaj liczbe: ";
        cin>>liczba;

        if (czyPierwsza(liczba)==true)
        {
            sumaLiczbPierszych++;
        }
        system("CLS");
    }
    
    cout<<"Podano "<<sumaLiczbPierszych<<" liczb pierwszych."<<endl;

    return 0;
}