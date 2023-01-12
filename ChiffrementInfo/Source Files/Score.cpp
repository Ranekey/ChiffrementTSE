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
		//Pour calculer le score il faut multiplier tout les probabilt� puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilit� on pr�f�re appliquer directement le log
		//Donc dans bigramme on d�ja appliquer le log
		//il ne reste plus qu'� faire l'addition
	}

	return score;
}