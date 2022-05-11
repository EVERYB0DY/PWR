#include <iostream>
#include <string>

using namespace std;

class iOsoba
{
public:
	virtual int setIdentyfikator(string id) = 0;
	virtual string getIdentyfikator() = 0;
};

class cOsoba:public iOsoba
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

class cPolak:public cOsoba
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

class cPortugalczyk :public cOsoba
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



int main()
{
	cOsoba *tabOsoba[4];
	cPolak tabPolak[2];
	cPortugalczyk tabPortugalczyk[2];

	tabPolak[0].setIdentyfikator("01234567890");

	tabPolak[1].setIdentyfikator("09876543210");

	tabPortugalczyk[0].setIdentyfikator("06543210");
	tabPortugalczyk[1].setIdentyfikator("09543210");

	tabOsoba[0] = &tabPolak[0];
	tabOsoba[1] = &tabPolak[1];
	tabOsoba[2] = &tabPortugalczyk[0];
	tabOsoba[3] = &tabPortugalczyk[1];

	for (int i = 0; i < 4; i++)
	{
		cout << tabOsoba[i]->getIdentyfikator() << endl;
		i < 2 ? cout << tabPolak[i].getIdentyfikator() << endl : cout << tabPortugalczyk[i-2].getIdentyfikator() << endl;
		cout << endl << endl;
	}


	return 0;
}