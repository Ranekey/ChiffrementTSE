#include "decrypter.h"
#include <random>
#include <math.h>
using namespace std;

bool Metropolis(float scoreActuelle, const char noouvelleProposition[], float scoreNouvelleProposition, unsigned int tailleTexte) {
	float x = rand() / (float)RAND_MAX; // g�n�re un nombre al�atoire entre 0 et 1
	float p = exp((scoreNouvelleProposition - scoreActuelle) * tailleTexte);


}