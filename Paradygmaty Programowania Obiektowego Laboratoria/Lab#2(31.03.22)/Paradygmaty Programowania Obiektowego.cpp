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
	void DataUrodzenia(string pesel);

public:
	//string imie;
	//string nazwisko;
	//string pesel;
	//string dataUrodzenia;

	void setImie(string imie);
	void setNazwisko(string nazwisko);
	void setPesel(string pesel);
	//void setDataUrodzenia(string dataUrodzenia);

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

void cOsoba::DataUrodzenia(string pesel)
{
	string data;
	if (pesel[2] > '1')
	{
		data = pesel[4];
		data += pesel[5];
		data += "/";
		data += ((int)pesel[2] - 2);
		data += pesel[3];
		data += "/";
		data += "20";
		data += pesel[0];
		data += pesel[1];
	}
	else
	{
		data = pesel[4];
		data += pesel[5];
		data += "/";
		data += pesel[2];
		data += pesel[3];
		data += "/";
		data += "19";
		data += pesel[0];
		data += pesel[1];
	}

	this->dataUrodzenia = data;
}

void cOsoba::setPesel(string pesel)
{
	if (pesel.size() == 11)
	{
		this->pesel = pesel;
		DataUrodzenia(pesel);
	}
	else
	{
		cout << "\n\n\t\t!!!!!!UWAGA!!!!!!!          Nieprawidlowy pesel.\n\n\n\n";
	}
}

/*void cOsoba::setDataUrodzenia(string dataUrodzenia)
{
	this->dataUrodzenia = dataUrodzenia;
}*/

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

class ListaOsob
{
private:
	cOsoba osoby[30];
public:
	int dodajOsobe(cOsoba osoba); // Zwraca: 0 -> sukces		1 -> taka osoba już jest na liście		2 -> brak miejsca na liście osób
	void wyswietlListe();
	int ustawObecnosc(cOsoba osoba, string data, bool czyObecny); // Zwraca: 0 -> sukces		1 -> brak osoby na liście		2 -> błąd daty		3 -> obecność już ustawiona
	void wyswietlObecnosc(cOsoba osoba, string data);
};

int ListaOsob::dodajOsobe(cOsoba osoba)
{
	for (size_t i = 0; i < 30; i++)
	{
		if ()
		{

		}
	}
}

int main()
{
	cOsoba anon;
	anon.setImie("Anon");
	anon.setNazwisko("Anonowicz");
	anon.setPesel("01232567890");
	//anon.setDataUrodzenia("25/03/2001");

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

