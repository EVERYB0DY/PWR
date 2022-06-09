#include "FabrykaStudentow.h"

Student* FabrykaPolakow::stoworzStudenta()
{
	return new Polak;
}

Student* FabrykaPortugalczykow::stoworzStudenta()
{
	return new Portugalczyk;
}
