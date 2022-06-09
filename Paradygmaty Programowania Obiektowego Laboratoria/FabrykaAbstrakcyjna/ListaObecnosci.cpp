#include "ListaObecnosci.h"
#include <iostream>

int ListaObecosci::dodajOsobe(Student* student)
{
	for (int i = 0; i < 30; i++)
	{
		Student* tmp;
		tmp = listaStudentow[i];
		if (tmp != NULL)
		{
			
			if (tmp->getIdentyfikator() == student->getIdentyfikator())
			{
				delete tmp;
				return 1;
			}
			
		}
		else
		{
			delete tmp;
			this->listaStudentow[i] = student;
			return 0;
		}
	}
	return 2;
}

int ListaObecosci::wyswietlListe()
{
	if (this->listaStudentow[0] == NULL)
	{
		return 1;
	}

	for (int i = 0; i < 30; i++)
	{
		Student* tmp;
		tmp = listaStudentow[i];
		std::cout << i+1 << ". " << tmp->getImie() << " " << tmp->getNazwisko() << " " << tmp->getNrAlbumu() << "\n";
		delete tmp;
	}
	return 0;
}

int ListaObecosci::ustawObecnosc(std::string identyfikator, std::string data, bool czyObecny)
{
	if (this->listaStudentow[0] == NULL)
	{
		return 4;
	}

	int numerNaLiscie = 0;
	for (int i = 0; i < 30; i++)
	{
		Student* tmp;
		tmp = listaStudentow[i];
		if (tmp->getIdentyfikator()==identyfikator)
		{
			numerNaLiscie = i;
		}
		delete tmp;
	}

	if (numerNaLiscie == 0)
	{
		return 1;
	}

	for (int i = 0; i < 15; i++)
	{
		if (this->listaObecnosci[i].dataZajec == std::string())
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

void ListaObecosci::wyswietlObecnosc(std::string identyfikator, std::string data)
{
	if (this->listaStudentow[0] == NULL)
	{
		std::cout << "Lista pusta.\n";
	}
	else
	{
		int numerNaLiscie = 0;
		for (int i = 0; i < 30; i++)
		{
			Student* tmp;
			tmp = listaStudentow[i];
			if (tmp->getIdentyfikator() == identyfikator)
			{
				numerNaLiscie = i;
			}
			delete tmp;
		}

		for (int i = 0; i < 15; i++)
		{
			if (this->listaObecnosci[i].dataZajec == data)
			{
				if (this->listaObecnosci[i].obecnosc[numerNaLiscie] == true)
				{
					std::cout << "Osoba byla obecna.\n";
				}
				else
				{
					std::cout << "Osoba byla nieobecna.\n";
				}
			}
		}
	}
}
