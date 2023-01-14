#include "WRfichier.h"

void Copy(const char tab2[], const unsigned int taille, char tab1[])
{
	for (unsigned int i = 0; i < taille; i++) {
		tab1[i] = tab2[i];

	}
}