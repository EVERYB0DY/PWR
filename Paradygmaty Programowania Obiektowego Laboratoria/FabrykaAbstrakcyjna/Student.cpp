#include "Student.h"
#include <string>

int Student::setImie(std::string imie)
{
    this->imie = imie;
    return 0;
}

int Student::setNazwisko(std::string nazwisko)
{
    this->nazwisko = nazwisko;
    return 0;
}

int Student::setDataUrodzenia(std::string dataUrodzenia)
{
    this->dataUrodzenia = dataUrodzenia;
    return 0;
}

int Student::setNrAlbumu(int nrAlbumu)
{
    this->nrAlbumu = nrAlbumu;
    return 0;
}

std::string Student::getImie()
{
    return this->imie;
}

std::string Student::getNazwisko()
{
    return this->nazwisko;
}

std::string Student::getDataUrodzenia()
{
    return this->dataUrodzenia;
}

int Student::getNrAlbumu()
{
    return this->nrAlbumu;
}

std::string Student::getIdentyfikator()
{
    return this->identyfikator;
}

int Polak::setIdentyfikator(std::string identyfikator)
{
	if (identyfikator.length() == 11)
	{
		this->identyfikator = identyfikator;

		std::string data;

		if (identyfikator[2] == '2')
		{
			data = identyfikator[4];
			data += identyfikator[5];
			data += "/";
			data += ((int)identyfikator[2] - 2);
			data += identyfikator[3];
			data += "/";
			data += "20";
			data += identyfikator[0];
			data += identyfikator[1];
		}
		else
		{
			data = identyfikator[4];
			data += identyfikator[5];
			data += "/";
			data += identyfikator[2];
			data += identyfikator[3];
			data += "/";
			data += "19";
			data += identyfikator[0];
			data += identyfikator[1];
		}

		this->dataUrodzenia = data;

		return 0;
	}
	return 1;
}

int Polak::setDataUrodzenia(std::string dataUrodzenia)
{
	if (this->dataUrodzenia == dataUrodzenia)
	{
		return 0;
	}

	return 1;
}

int Portugalczyk::setIdentyfikator(std::string identyfikator)
{
	if (identyfikator.length() == 8)
	{
		this->identyfikator = identyfikator;
		return 0;
	}
	return 1;
}