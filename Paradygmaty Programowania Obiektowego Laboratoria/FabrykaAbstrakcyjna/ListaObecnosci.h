#pragma once
#include <string>
#include "Student.h"

class ListaObecnosci
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
	std::string wyswietlListe(int liczba);
	int ustawObecnosc(std::string identyfikator, std::string data, bool czyObecny);
	int wyswietlObecnosc(std::string identyfikator, std::string data);
};