#include "ListaObecnosci.h"
#include <iostream>

int ListaObecnosci::dodajOsobe(Student* student)
{
	for (int i = 0; i < 30; i++)
	{
		if (this->listaStudentow[i] != NULL)
		{
			
			if (this->listaStudentow[i]->getIdentyfikator() == student->getIdentyfikator())
			{
				return 1;
			}
			
		}
		else
		{
			this->listaStudentow[i] = student;
			return 0;
		}
	}
	return 2;
}

std::string ListaObecnosci::wyswietlListe(int liczba)
{
	if (this->listaStudentow[liczba] != NULL)
		return this->listaStudentow[liczba]->getImie() + " " + this->listaStudentow[liczba]->getNazwisko() + " " + std::to_string(this->listaStudentow[liczba]->getNrAlbumu());
	
	return std::to_string(NULL);
}

int ListaObecnosci::ustawObecnosc(std::string identyfikator, std::string data, bool czyObecny)
{
	if (this->listaStudentow[0] == NULL)
	{
		return 4;
	}

	
	for (int i = 0; i < 30; i++)
	{
		if (this->listaStudentow[i]->getIdentyfikator()==identyfikator)
		{
			for (int j = 0; j < 15; j++)
			{
				if (this->listaObecnosci[j].dataZajec == std::string())
				{
					this->listaObecnosci[j].dataZajec = data;
				}

				if (this->listaObecnosci[j].dataZajec == data)
				{
					if (this->listaObecnosci[j].obecnosc[i] == NULL)
					{
						this->listaObecnosci[j].obecnosc[i] = czyObecny;
						return 0;
					}
					return 1;
				}
			}
			return 2;
		}
		if (this->listaStudentow[i + 1] == NULL)
		{
			break;
		}
	}

	
	return 3;
}

int ListaObecnosci::wyswietlObecnosc(std::string identyfikator, std::string data)
{
	if (this->listaStudentow[0] == NULL)
	{
		return 2;
	}
	else
	{
		for (int i = 0; i < 30; i++)
		{
			if (this->listaStudentow[i]->getIdentyfikator() == identyfikator)
			{
				for (int j = 0; j < 15; j++)
				{
					if (this->listaObecnosci[j].dataZajec == data)
					{
						if (this->listaObecnosci[j].obecnosc[i] == true)
						{
							return 0;
						}
						else
						{
							return 1;
						}
					}
				}

				return 3;
			}

			if (this->listaStudentow[i+1] == NULL)
			{
				break;
			}
		}
		return 4;

	}
}
