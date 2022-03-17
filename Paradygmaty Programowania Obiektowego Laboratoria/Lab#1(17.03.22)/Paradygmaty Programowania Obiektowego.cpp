#include <iostream>
#include <string>

using namespace std;

struct sOsoba
{
	string imie;
	string nazwisko;
	string pesel;
	string dataUrodzenia;
};

class cOsoba
{
private:
	string imie;
	string nazwisko;
	string pesel;
	string dataUrodzenia;

public:
	//string imie;
	//string nazwisko;
	//string pesel;
	//string dataUrodzenia;

	void setImie(string imie);
	void setNazwisko(string nazwisko);
	int setPesel(string pesel);
	void setDataUrodzenia(string dataUrodzenia);

	string getImie();
	string getNazwisko();
	string getPesel();
	string getDataUrodzenia();
};

void cOsoba::setImie(string imie)
{
	this->imie = imie;
}

void cOsoba::setNazwisko(string nazwisko)
{
	this->nazwisko = nazwisko;
}

int cOsoba::setPesel(string pesel)
{
	this->pesel = pesel;
	return 0;
}

void cOsoba::setDataUrodzenia(string dataUrodzenia)
{
	this->dataUrodzenia = dataUrodzenia;
}

string cOsoba::getImie()
{
	return imie;
}

string cOsoba::getNazwisko()
{
	return nazwisko;
}

string cOsoba::getPesel()
{
	return pesel;
}

string cOsoba::getDataUrodzenia()
{
	return dataUrodzenia;
}


int main()
{
	cOsoba anon;
	anon.setImie("Anon");
	anon.setNazwisko("Anonowicz");
	anon.setPesel("01232567890");
	anon.setDataUrodzenia("25/03/2001");

	sOsoba anon2;
	anon2.imie = "Anon";
	anon2.nazwisko = "Anonowicz";
	anon2.pesel = "01232567890";
	anon2.dataUrodzenia = "25/03/2001";

	cout << "Klasa" << endl << endl;

	cout << "Imie: " << anon.getImie() << endl;
	cout << "Nazwisko: " << anon.getNazwisko() << endl;
	cout << "Pesel: " << anon.getPesel() << endl;
	cout << "Data Urodzenia: " << anon.getDataUrodzenia() << endl;

	cout << "\n\n\nStruktura" << endl << endl;

	cout << "Imie: " << anon2.imie << endl;
	cout << "Nazwisko: " << anon2.nazwisko << endl;
	cout << "Pesel: " << anon2.pesel << endl;
	cout << "Data Urodzenia: " << anon2.dataUrodzenia << endl << endl;

	return 0;
}

