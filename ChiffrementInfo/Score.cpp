#include "decrypter.h"
#include "WRfichier.h"
#include <math.h>

float score() {
	//bigramme enchainement de lettres
	char Text[1000];//on suppose l'existance
	unsigned int tpText;//on suppose l'existance
	float bigramme[26][26];
	float probabiliteEnchainementLettres = 1;
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	float score = 0;
	for (unsigned int indChar = 1; indChar < tpText; indChar++) {
		indDeuxiemeLettre = LettreToNumber(Text[indChar]);
		indPremierLettre = LettreToNumber(Text[indChar - 1]);
		probabiliteEnchainementLettres = probabiliteEnchainementLettres * bigramme[indPremierLettre][indDeuxiemeLettre];

	}

	score = log(probabiliteEnchainementLettres) / tpText;
	return score;
}