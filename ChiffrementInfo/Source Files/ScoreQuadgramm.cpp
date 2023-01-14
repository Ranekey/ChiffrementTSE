#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// à suppprimer
#include <math.h>

float ScoreQuadgramm(const char texte[], const unsigned int tpTexte, float quadgramm[42][42][42][42])
{
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	unsigned int indTroisiemeLettre;
	unsigned int indQuatriemeLettre;
	float score = 0;
	for (unsigned int indChar = 3; indChar < tpTexte; indChar++)
	{
		indPremierLettre = LettreToNumberComplet(texte[indChar - 3]);
		indDeuxiemeLettre = LettreToNumberComplet(texte[indChar - 2]);
		indTroisiemeLettre = LettreToNumberComplet(texte[indChar - 1]);
		indQuatriemeLettre = LettreToNumberComplet(texte[indChar]);
		
		if (indPremierLettre != -1 && indDeuxiemeLettre != -1) {

			score = score + quadgramm[indPremierLettre][indDeuxiemeLettre][indTroisiemeLettre][indQuatriemeLettre];
		}

	}


	return score / tpTexte; // on normalise par le nombre de charactères
}