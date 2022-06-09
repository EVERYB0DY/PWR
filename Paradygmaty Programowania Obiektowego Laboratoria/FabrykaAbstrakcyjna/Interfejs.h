#pragma once
#include "FabrykaStudentow.h"
#include "ListaObecnosci.h"



class Interfejs
{
private:
	ListaObecosci lista{};
public:
	int menuListyObecnosci();
	int menuFabrykiStudentow();
	void dodawanieStudentow(Student* student);
	void ustawianieObecnosciStudentow();
	void wyswietlanieObecnosciStudentow();
};

