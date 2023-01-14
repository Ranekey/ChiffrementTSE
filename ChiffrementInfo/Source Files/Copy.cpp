#include "utils.h"

void Copy(unsigned int taille, char tab1[], const char tab2[]) {
	for (unsigned int i = 0; i < taille; i++) {
		tab1[i] = tab2[i];

	}
}