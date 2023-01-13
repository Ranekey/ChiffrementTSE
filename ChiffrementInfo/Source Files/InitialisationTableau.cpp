#include "utils.h"

void InitialisationTableau(float tab[], const unsigned int tpTab, float valeurInitial)
{
	for (unsigned int i = 0; i < tpTab; i++)
	{
		tab[i] = valeurInitial;
	}
}