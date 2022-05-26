#include <iostream>
#include <string>

using namespace std;

class cOsoba
{
private:
	string imie = "";
	string nazwisko = "";
	int nrAlbumu = NULL;
protected:
	string dataUrodzenia = "";
	string identyfikator = "";
public:
	int setImie(string imie);
	int setNazwisko(string nazwisko);
	virtual int setDataUrodzenia(string dataUrodzenia);
	int setNrAlbumu(int nrAlbumu);

	string getImie();
	string getNazwisko();
	string getDataUrodzenia();
	int getNrAlbumu();
};

class iOsoba :public cOsoba
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


string cOsoba::getImie()
{
	return imie;
}

string cOsoba::getNazwisko()
{
	return nazwisko;
}

string cOsoba::getDataUrodzenia()
{
	return dataUrodzenia;
}

int cOsoba::getNrAlbumu()
{
	return nrAlbumu;
}

class cPolak :public iOsoba
{
public:
	int setIdentyfikator(string id)
	{
		if (id.length() == 11)
		{
			this->identyfikator = id;
			setDataUrodzenia(id);
			return 0;
		}
		return 1;
	}

	int setDataUrodzenia(string pesel) override
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
		return 0;
	}

	string getIdentyfikator()
	{
		string id = "";
		id = "PL: ";
		id = id + this->identyfikator;
		return id;
	}
};

class cPortugalczyk :public iOsoba
{
public:
	int setIdentyfikator(string id)
	{
		if (id.length() == 8)
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

class cListaOsob
{
private:
	struct
	{
		bool obecnosc[30] = { NULL };
		string dataZajec = NULL;
	}listaObecnosci[15];
	cOsoba* osoby[30];

public:
	int dodajOsobe(cOsoba osoba); // Zwraca: 0 -> sukces		1 -> taka osoba ju¿ jest na liœcie		2 -> brak miejsca na liœcie osób
	void wyswietlListe();
	int ustawObecnosc(cOsoba osoba, string data, bool czyObecny); // Zwraca: 0 -> sukces		1 -> brak osoby na liœcie		2 -> b³¹d daty		3 -> obecnoœæ ju¿ ustawiona
	void wyswietlObecnosc(cOsoba osoba, string data);
};

int cListaOsob::dodajOsobe(cOsoba osoba)
{
	for (size_t i = 0; i < 30; i++)
	{
		if (this->osoby[i]->getImie() != "")
		{
			if (this->osoby[i]->getImie() == osoba.getImie() && this->osoby[i]->getNazwisko() == osoba.getNazwisko() && this->osoby[i]->getNrAlbumu() == osoba.getNrAlbumu())
			{
				return 1;
			}
		}
		else
		{
			this->osoby[i] = &osoba;
			return 0;
		}
	}
	return 2;
}

void cListaOsob::wyswietlListe()
{
	for (size_t i = 0; i < 30; i++)
	{
		cout << i << ". " << this->osoby[i]->getImie() << " " << this->osoby[i]->getNazwisko() << " " << this->osoby[i]->getNrAlbumu() << endl;
	}
}

int cListaOsob::ustawObecnosc(cOsoba osoba, string data, bool czyObecny)
{
	int numerNaLiscie = NULL;
	for (int i = 0; i < 30; i++)
	{
		if (this->osoby[i]->getImie() == osoba.getImie() && this->osoby[i]->getNazwisko() == osoba.getNazwisko() && this->osoby[i]->getNrAlbumu() == osoba.getNrAlbumu())
		{
			numerNaLiscie = i;
		}
	}

	if (numerNaLiscie == NULL)
	{
		return 1;
	}

	for (size_t i = 0; i < 15; i++)
	{
		if (this->listaObecnosci[i].dataZajec == "")
		{
			this->listaObecnosci[i].dataZajec = data;
		}

		if (this->listaObecnosci[i].dataZajec == data)
		{
			if (this->listaObecnosci[i].obecnosc[numerNaLiscie] == NULL)
			{
				this->listaObecnosci[i].obecnosc[numerNaLiscie] = czyObecny;
				return 0;
			}
			return 3;
		}

	}
	return 2;
}

void cListaOsob::wyswietlObecnosc(cOsoba osoba, string data)
{
	int numerNaLiscie = NULL;
	for (int i = 0; i < 30; i++)
	{
		if (this->osoby[i]->getImie() == osoba.getImie() && this->osoby[i]->getNazwisko() == osoba.getNazwisko() && this->osoby[i]->getNrAlbumu() == osoba.getNrAlbumu())
		{
			numerNaLiscie = i;
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (this->listaObecnosci[i].dataZajec == data)
		{
			if (this->listaObecnosci[i].obecnosc[numerNaLiscie] == true)
			{
				cout << "Osoba byla obecna" << endl;
			}
			else
			{
				cout << "Osoba byla nieobecna" << endl;
			}
		}
	}
}

class iUzytkownika
{
public:
	int menuGlowne();
	int dodawanieOsoby(cListaOsob lista);
	int wyswietlanieListy(cListaOsob lista);
	int wyswietlanieObecnosci(cListaOsob lista);
	int ustawianieObecnosci(cListaOsob lista);
};

int iUzytkownika::menuGlowne()
{

	int opcja = NULL;

	/*
		Czyszczenie konsoli
	*/
	system("cls");

	/*
		Menu g³ówne
	*/
	cout << "1. Dodaj osobe" << endl;
	cout << "2. Ustaw obecnosc" << endl;
	cout << "3. Wyswietl obecnosc" << endl;
	cout << "4. Wyswietl liste osob" << endl;
	cout << "Prosze podac wybrana opcje: ";
	cin >> opcja;

	/*
		Wybór opcji
	*/
	switch (opcja)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	default:
		return 0;
		break;
	}
}

int iUzytkownika::dodawanieOsoby(cListaOsob lista)
{
	/*
		Czyszczenie konsoli
	*/
	system("cls");

	/*
		Wybór narodowoœci
	*/

	string kraj;
	cout << "Porsze podac kraj (PL/PT): ";
	cin >> kraj;
	if (kraj == "PL")
	{
		cPolak polak;
		string tmp="";
		int tmp2=NULL;

		cout << "Prosze podac imie: ";
		cin >> tmp;
		polak.setImie(tmp);
		tmp = "";

		cout << "Prosze podac nazwisko: ";
		cin >> tmp;
		polak.setNazwisko(tmp);
		tmp = "";

		cout << "Prosze podac PESEL: ";
		cin >> tmp;
		polak.setIdentyfikator(tmp);
		tmp = "";

		cout << "Prosze podac numer albumu: ";
		cin >> tmp2;
		polak.setNrAlbumu(tmp2);
		tmp2 = NULL;

		return lista.dodajOsobe(polak);


	}
	else if (kraj == "PT")
	{
		cPortugalczyk portugalczyk;
		string tmp = "";
		int tmp2 = NULL;

		cout << "Prosze podac imie: ";
		cin >> tmp;
		portugalczyk.setImie(tmp);
		tmp = "";

		cout << "Prosze podac nazwisko: ";
		cin >> tmp;
		portugalczyk.setNazwisko(tmp);
		tmp = "";

		cout << "Prosze podac identyfikator: ";
		cin >> tmp;
		portugalczyk.setIdentyfikator(tmp);
		tmp = "";

		cout << "Prosze podac numer albumu: ";
		cin >> tmp2;
		portugalczyk.setNrAlbumu(tmp2);
		tmp2 = NULL;

		return lista.dodajOsobe(portugalczyk);
	}
	else
	{
		return 3;
	}
}

int iUzytkownika::wyswietlanieListy(cListaOsob lista)
{
	system("cls");
	lista.wyswietlListe();
	return 0;
}

int iUzytkownika::wyswietlanieObecnosci(cListaOsob lista)
{
	system("cls");
	cOsoba osoba;
	string tmp;
	int tmp2;

	cout << "Prosze podac imie: ";
	cin >> tmp;
	osoba.setImie(tmp);
	tmp = "";

	cout << "Prosze podac nazwisko: ";
	cin >> tmp;
	osoba.setNazwisko(tmp);
	tmp = "";

	cout << "Prosze podac numer albumu: ";
	cin >> tmp2;
	osoba.setNrAlbumu(tmp2);
	tmp2 = NULL;

	cout << "Prosze podac date zajec: ";
	cin >> tmp;

	system("cls");

	lista.wyswietlObecnosc(osoba, tmp);

	return 0;
}

int iUzytkownika::ustawianieObecnosci(cListaOsob lista)
{
	system("cls");

	cOsoba osoba;
	string tmp;
	string obecnosc;
	int tmp2;

	cout << "Prosze podac imie: ";
	cin >> tmp;
	osoba.setImie(tmp);
	tmp = "";

	cout << "Prosze podac nazwisko: ";
	cin >> tmp;
	osoba.setNazwisko(tmp);
	tmp = "";

	cout << "Prosze podac numer albumu: ";
	cin >> tmp2;
	osoba.setNrAlbumu(tmp2);
	tmp2 = NULL;

	cout << "Prosze podac date zajec: ";
	cin >> tmp;

	cout << "Czy osoba jest obecna? (t/n)" << endl;
	cin >> obecnosc;
	if (obecnosc == "t")
	{
		return lista.ustawObecnosc(osoba, tmp, 1);
	}
	else
	{
		return lista.ustawObecnosc(osoba, tmp, 0);
	}
}

class mainLoop:public iUzytkownika
{
public:
	void Loop();
};

void mainLoop::Loop()
{
	cListaOsob lista;
	
	while (true)
	{
		switch (this->menuGlowne())
		{
		case 1:
			switch (this->dodawanieOsoby(lista))
			{
			case 0:
				cout << "Pomyslnie dodano osobe" << endl;
				break;
			case 1:
				cout << "Taka osoba istnieje juz na liscie!!" << endl;
				break;
			case 2:
				cout << "Brak miejsca na liscie osob!!" << endl;
				break;
			default:
				cout << "Bledny kraj!!" << endl;
				break;
			}
			break;
		case 2:
			switch (this->ustawianieObecnosci(lista))
			{
			case 0:
				cout << "Pomyslnie ustawiono obecnosc" << endl;
				break;
			case 1:
				cout << "Brak osoby na liscie!!" << endl;
				break;
			case 2:
				cout << "Blad daty !!" << endl;
				break;
			case 3:
				cout << "Obecnosc jest juz ustawiona !!" << endl;
				break;
			default:
				break;
			}
			break;
		case 3:
			this->wyswietlanieObecnosci(lista);
			break;
		case 4:
			this->wyswietlanieListy(lista);
			break;
		default:
			cout << "Bledna opcja!!" << endl;
			break;
		}
	}
}

int main()
{
	mainLoop test;
	test.Loop();
	return 0;
}