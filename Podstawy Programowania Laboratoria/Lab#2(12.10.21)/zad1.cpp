#include <iostream>

int main()
{
	double a,b,wynik;
	char znak;

	std::cout<<"Podaj pierwsza liczbe: ";
	std::cin>>a;

	std::cout<<"Podaj druga liczbe: ";
	std::cin>>b;

	std::cout<<"Podaj operator matematyczny (+,-,*,/): ";
	std::cin>>znak;

	if(znak=='+')
	{
		wynik=a+b;
	}
	else if(znak=='-')
	{
		wynik=a-b;
	}
	else if(znak=='*')	
	{
		wynik=a*b;
	}
	else if(znak=='/')
	{
		if(b==0)
		{
			std::cout<<"Nie dzielimy przez ZERO!!!"<<std::endl;
			return 0;
		}
		else
		{
			wynik=a/b;
		}
	}
	else
	{
		std::cout<<"Nieprawidlowy operator logiczny"<<std::endl;
	}

	std::cout<<std::endl;

	std::cout<<a<<znak<<b<<"="<<wynik<<std::endl;

	return 0;
}
