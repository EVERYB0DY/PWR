#include <iostream>
#include <string>

using namespace std;



class cOsoba
{
private:
	string imie = "";
	string nazwisko = "";
	string dataUrodzenia = "";
	int nrAlbumu = NULL;
protected:
	string identyfikator = "";
public:
	int setImie(string imie);
	int setNazwisko(string nazwisko);
	int setDataUrodzenia(string dataUrodzenia);
	int setNrAlbumu(int nrAlbumu);
};

class IOsoba :public cOsoba
{
public:
	virtual int setIdentyfikator(string id) = 0;
	virtual string getIdentyfikator() = 0;
};

int cOsoba::setImie(string imie)
{
	this->imie = imie;
	return 0;
}

int cOsoba::setNazwisko(string nazwisko)
{
	this->nazwisko = nazwisko;
	return 0;
}

int cOsoba::setDataUrodzenia(string dataUrodzenia)
{
	this->dataUrodzenia = dataUrodzenia;
	return 0;
}

int cOsoba::setNrAlbumu(int nrAlbumu)
{
	this->nrAlbumu = nrAlbumu;
	return 0;
}

class cPolak:public IOsoba
{
public:
	int setIdentyfikator(string id)
	{
		if (id.length() == 11)
		{
			this->identyfikator = id;
			return 0;
		}
		return 1;
	}

	string getIdentyfikator()
	{
		string id = "";
		id = "PL: ";
		id = id + this->identyfikator;
		return id;
	}
};

class cPortugalczyk :public IOsoba
{
public:
	int setIdentyfikator(string id)
	{
		if (id.length()==8)
		{
			this->identyfikator = id;
			return 0;
		}
		return 1;
	}

	string getIdentyfikator()
	{
		string id = "";
		id = "PT: ";
		id = id + this->identyfikator;
		return id;
	}
};

class IUzytkownika
{
private:
	void portuaglczyk();
	void polak();

public:
	void jakiKraj();

};

void IUzytkownika::jakiKraj()
{
	string kraj;
	cout << "Porsze podac kraj (PL/PT): ";
	cin >> kraj;
	if (kraj == "PL")
	{
		polak();
		cout << "Gotowe" << endl;
	}
	else if (kraj=="PT")
	{
		portuaglczyk();
		cout << "Gotowe" << endl;
	}
	else
	{
		cout << "Nieprawidlowy kraj" << endl;
	}

}

void IUzytkownika::portuaglczyk()
{
	cPortugalczyk osoba;
	string dane;
	int dane2;

	cout << "Prosze podac imie: ";
	cin >> dane;
	osoba.setImie(dane);
	dane.clear();

	cout << "Prosze podac nazwisko: ";
	cin >> dane;
	osoba.setNazwisko(dane);
	dane.clear();

	cout << "Prosze podac date urodzenia: ";
	cin >> dane;
	osoba.setDataUrodzenia(dane);
	dane.clear();

	cout << "Prosze podac numer albumu: ";
	cin >> dane2;
	osoba.setNrAlbumu(dane2);
	dane2 = NULL;

	cout << "Prosze podac identyfikator: ";
	cin >> dane;
	osoba.setIdentyfikator(dane);
	dane.clear();
}

void IUzytkownika::polak()
{
	cPolak osoba;
	string dane;
	int dane2;

	cout << "Prosze podac imie: ";
	cin >> dane;
	osoba.setImie(dane);
	dane.clear();

	cout << "Prosze podac nazwisko: ";
	cin >> dane;
	osoba.setNazwisko(dane);
	dane.clear();

	cout << "Prosze podac date urodzenia: ";
	cin >> dane;
	osoba.setDataUrodzenia(dane);
	dane.clear();

	cout << "Prosze podac numer albumu: ";
	cin >> dane2;
	osoba.setNrAlbumu(dane2);
	dane2 = NULL;

	cout << "Prosze podac identyfikator: ";
	cin >> dane;
	if (osoba.setIdentyfikator(dane)==1)
	{
		cout << "bledny identyfikator" << endl;
	}
	dane.clear();
}


int main()
{
	IUzytkownika interfejs;

	interfejs.jakiKraj();


	return 0;
}