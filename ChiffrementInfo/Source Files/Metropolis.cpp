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

bool Metropolis(float score_courant,float score_actuelle, unsigned int taille) {
	float x = (float)rand()/(float)RAND_MAX; // génére un nombre aléatoire entre 0 et 1
	float p = exp((score_courant - score_actuelle) * taille);
	return x < p; // Si vrai on accepte la proposition
}

float MetropolisBoucle(char proposition_initiale[43], char texte[], char proposition_courante[43], char proposition_actuelle[43], char best_proposition[43], unsigned int tailleTexte, float quadgramm[42][42][42][42]) {
	//initialisation variable pour decrypter
	float best_score, score_courant, score_actuelle;
	float score_initiale = ScoreQuadgramm(texte, tailleTexte, quadgramm);
	score_courant = score_initiale;
	best_score = score_initiale;
	score_actuelle = score_initiale;
	//ca fait beaucoup de variable mais c++ me laisse pas faire de variable locale
	proposition_courante = proposition_initiale;
	proposition_actuelle = proposition_initiale;
	best_proposition = proposition_initiale;
	//initialisation variable pour boucle
	const unsigned int MINITER = 2000;
	const unsigned int MAXITER = 10000;
	const float scoreExcellent = -2.10; // à adapter et tester
	unsigned int i = 0;
	while (i < MAXITER) {
		//Nouvelle proposition
		//proposition_courante = Proposition(); A faire Proposition
		score_courant = ScoreQuadgramm(texte, tailleTexte, quadgramm); // score à changer
		if (Metropolis(score_courant, score_actuelle, tailleTexte)) {
			proposition_actuelle = proposition_courante;
			score_actuelle = score_courant;

		}
		if (score_actuelle > best_score) {
			best_score = score_actuelle;
			best_proposition = proposition_actuelle;
		}

		if (i > MINITER && best_score >= scoreExcellent) {
			break; // faut casser la boucle alors
		}
	}
	return best_score;
}

