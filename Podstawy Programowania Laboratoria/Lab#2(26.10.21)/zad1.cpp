#include <iostream>

using namespace std;

int main()
{
    double suma=0;

    while (true)
    {
        int liczba;

        cout<<"Podaj liczbe: ";
        cin>>liczba;

        if (liczba>=(-15)&&liczba<=15)
        {
            suma+=liczba;
        }
        else if (liczba==99)
        {
            break;
        } 
    }

    cout<<"Suma wynosi: "<<suma<<endl;

    return 0;
}