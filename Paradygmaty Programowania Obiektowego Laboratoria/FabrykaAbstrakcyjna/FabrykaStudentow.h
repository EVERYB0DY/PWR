#pragma once
#include <string>
#include "Student.h"

class FabrykaStudentow
{
public:
	virtual Student* stoworzStudenta() = 0;
};

class FabrykaPolakow :public FabrykaStudentow
{
public:
	Student* stoworzStudenta();
};

class FabrykaPortugalczykow :public FabrykaStudentow
{
public:
	Student* stoworzStudenta();

};