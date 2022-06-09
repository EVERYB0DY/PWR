#pragma once
#include <string>
#include "Student.h"

class ListaObecosci
{
private:
	struct
	{
		bool obecnosc[30] = { NULL };
		std::string dataZajec = std::string();
	}listaObecnosci[15];
	Student *listaStudentow[30]={NULL};

public:
	int dodajOsobe(Student *student);
	int wyswietlListe();
	int ustawObecnosc(std::string identyfikator, std::string data, bool czyObecny);
	void wyswietlObecnosc(std::string identyfikator, std::string data);
};