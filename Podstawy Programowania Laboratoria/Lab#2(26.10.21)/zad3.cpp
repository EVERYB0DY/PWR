#include <iostream>

using namespace std;

int NWD(int a, int b)
{
    while (a!=b)
    {
        if (a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}

int main()
{
    int a,b;

    cout<<"Podaj piersza liczbe: ";
    cin>>a;
    cout<<"Podaj druga liczbe: ";
    cin>>b;

    cout<<"Najwiekszy wspolny dzienlnik podanych liczb to "<<NWD(a,b)<<endl;

    return 0;
}