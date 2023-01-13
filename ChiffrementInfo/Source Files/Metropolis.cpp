#include "decrypter.h"
#include <random>
#include <math.h>
using namespace std;

/*
variable dans le main

best_score
best_proposition

score_actuelle
proposition_actuelle

score_courant
proposition_courante

*/

bool Metropolis(float best_score, char best_proposition[26], float score_actuelle, char proposition_actuelle[26], float score_courant, char proposition_courante[26], unsigned int taille) {
	float best_score_temp = best_score;
	float x = rand() / (float)RAND_MAX; // génére un nombre aléatoire entre 0 et 1
	float p = exp((score_courant - score_actuelle) * taille);
	if (x < p) {
		proposition_actuelle = proposition_courante;
	}
	


}