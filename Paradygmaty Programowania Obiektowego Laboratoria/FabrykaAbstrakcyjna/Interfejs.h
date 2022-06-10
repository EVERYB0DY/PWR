#pragma once
#include "FabrykaStudentow.h"
#include "ListaObecnosci.h"



class Interfejs
{
public:
	Interfejs(){};
	Interfejs(ListaObecnosci* lista);
	int menuListyObecnosci(ListaObecnosci* lista);
	int menuFabrykiStudentow(ListaObecnosci* lista);
	void ustawianieObecnosciStudentow(ListaObecnosci* lista);
	void wyswietlanieObecnosciStudentow(ListaObecnosci* lista);
};

