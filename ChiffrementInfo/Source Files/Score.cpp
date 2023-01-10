#include "decrypter.h"
#include "WRfichier.h"
#include <math.h>

float score(char texte[], unsigned int tpTexte, float bigramme[26][26]) {
	float probabiliteEnchainementLettres = 1;
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	float score = 0;
	for (unsigned int indChar = 1; indChar < tpTexte; indChar++) {
		indDeuxiemeLettre = LettreToNumber(texte[indChar]);
		indPremierLettre = LettreToNumber(texte[indChar - 1]);
		probabiliteEnchainementLettres = probabiliteEnchainementLettres * bigramme[indPremierLettre][indDeuxiemeLettre];
	}

	score = log(probabiliteEnchainementLettres) / tpTexte;
	return score;
}