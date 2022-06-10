#pragma once
#include <string>
#include "Student.h"

class FabrykaStudentow
{
public:
	virtual Student* stoworzStudenta(std::string imie, std::string nazwisko, std::string identyfikator, std::string dataUrodzenia, int nrAlbumu) = 0;
};

class FabrykaPolakow :public FabrykaStudentow
{
public:
	Student* stoworzStudenta(std::string imie, std::string nazwisko, std::string identyfikator, std::string dataUrodzenia, int nrAlbumu);
};

class FabrykaPortugalczykow :public FabrykaStudentow
{
public:
	Student* stoworzStudenta(std::string imie, std::string nazwisko, std::string identyfikator, std::string dataUrodzenia, int nrAlbumu);

};