#include <iostream>
#include <string>

using namespace std;

class Osoba {
public:
	virtual void drukujKraj()=0;
};

class Polak :public Osoba {
public:
	void drukujKraj() {
		cout << "Polska" << endl;
	}
};

class Portugalczyk :public Osoba {
public:
	void drukujKraj() {
		cout << "Portugalia" << endl;
	}
};

int main()
{
	//Osoba os1;
	Portugalczyk os2;
	Polak os3;

	//os1.drukujKraj();//Nieznane
	os2.drukujKraj();//Portugalczyk
	os3.drukujKraj();//Polska

	cout << endl << endl;

	Osoba *tabOs[3];
	//tabOs[0] = &os1;
	tabOs[1] = &os2;
	tabOs[2] = &os3;

	//tabOs[0]->drukujKraj();//Nieznany
	tabOs[1]->drukujKraj();//Nieznany
	tabOs[2]->drukujKraj();//Nieznany
	

	return 0;
}