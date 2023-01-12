#include "decrypter.h"
#include "WRfichier.h"
#include <math.h>

float Score(char texte[], unsigned int tpTexte, float bigramme[26][26])
{
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	long float score = 0;
	for (unsigned int indChar = 1; indChar < tpTexte; indChar++)
	{
		indDeuxiemeLettre = LettreToNumber(texte[indChar]);
		indPremierLettre = LettreToNumber(texte[indChar - 1]);
		score = score + bigramme[indPremierLettre][indDeuxiemeLettre];
		//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilité on préfère appliquer directement le log
		//Donc dans bigramme on déja appliquer le log
		//il ne reste plus qu'à faire l'addition
	}

	return score;
}