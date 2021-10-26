#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	double a,b,c;
	vector<double> boki;
	
	cout<<"Podaj boki trojkata."<<endl;
	
	cout<<"a: ";
	cin>>a;
	if(a>0)
	{
		boki.push_back(a);
	}
	else
	{
		cout<<"Bok trójkąta musi być większy od 0."<<endl;
		return 0;
	}
	cout<<"b: ";
	cin>>b;
	if(b>0)
	{
		boki.push_back(b);
	}
	else
	{
		cout<<"Bok trójkąta musi być większy od 0."<<endl;
		return 0;
	}

	cout<<"c: ";
	cin>>c;
	if(c>0)
	{
		boki.push_back(c);
	}
	else
	{
		cout<<"Bok trójkąta musi być większy od 0."<<endl;
		return 0;
	}

	sort(boki.begin(),boki.end());

	a=boki[0];
	b=boki[1];
	c=boki[2];

	//cout<<a<<endl<<b<<endl<<c;
	
	if(c>=a&&c>=b)
	{
		if(a+b>c)
		{
			if(a==b||b==c)
			{
				if((a*a)+(b*b)==(c*c))
				{
					cout<<"Z podanych boków można stworzyć trójkąt który jest równoramienny i prostokątny"<<endl;
					return 0;
				}
				else if(a==c)
				{
					cout<<"Z podanych boków można stworzyć trójkąt który jest równoboczny"<<endl;
					return 0;
				}
				else
				{
					cout<<"Z podanych boków można stworzyć trójkąt który jest równoramienny"<<endl;
					return 0;
				}
			}
			else if((a*a)+(b*b)==(c*c))
			{
				cout<<"Z podanych boków można stworzyć trójkąt który jest prostokątny"<<endl;
				return 0;
			}
			else
			{
				cout<<"Z podanych boków można stworzyć trójkąt"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"Z podanych boków nie można stworzyć trójkąta"<<endl;
			return 0;
		}
	}
	else
	{
		cout<<"Z podanych boków nie można stworzyć trójkąta."<<endl;
		return 0;
	}


	return 0;
}
