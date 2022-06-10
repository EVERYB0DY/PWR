#include "FabrykaStudentow.h"

Student* FabrykaPolakow::stoworzStudenta(std::string imie, std::string nazwisko, std::string identyfikator, std::string dataUrodzenia, int nrAlbumu)
{
	Polak* polak = new Polak;
	polak->setImie(imie);
	polak->setNazwisko(nazwisko);
	polak->setNrAlbumu(nrAlbumu);
	if (polak->setIdentyfikator(identyfikator) != 0 || polak->setDataUrodzenia(dataUrodzenia) != 0)
		polak = NULL;
	return polak;
}

Student* FabrykaPortugalczykow::stoworzStudenta(std::string imie, std::string nazwisko, std::string identyfikator, std::string dataUrodzenia, int nrAlbumu)
{
	Portugalczyk* portugalczyk = new Portugalczyk();
	portugalczyk->setImie(imie);
	portugalczyk->setNazwisko(nazwisko);
	portugalczyk->setNrAlbumu(nrAlbumu);
	if (portugalczyk->setIdentyfikator(identyfikator) != 0 || portugalczyk->setDataUrodzenia(dataUrodzenia) != 0)
		portugalczyk = NULL;
	return portugalczyk;


	return portugalczyk;
}
