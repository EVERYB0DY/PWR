#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a,b,c,delta;

	cout<<"Podaj a: ";
	cin>>a;
	if(a==0)
	{
		cout<<"a nie może być równe 0"<<endl;
		return 0;
	}

	cout<<"Podaj b: ";
	cin>>b;

	cout<<"Podaj c: ";
	cin>>c;

	delta=(b*b)-(4*a*c);

	if(delta<0)
	{
		cout<<"Funkcja nie ma miejsc zerowych"<<endl;
		return 0;
	}
	else if(delta==0)
	{
		cout<<"Funkcja ma jedno miejsce zerowe które wynosi "<<(-b)/(2*a)<<endl;
		return 0;
	}
	else
	{
		cout<<"Funkcja ma dwa miejsca zerowe które wynoszą "<<((-b)+sqrt(delta))/(2*a)<<" oraz "<<((-b)+sqrt(delta))/(2*a)<<endl;
	}

	return 0;
}
