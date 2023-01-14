#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// � suppprimer
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
			//cout << "score : " << score << " bigramme : " << bigramme[indPremierLettre][indDeuxiemeLettre] <<endl;;
			score = score + quadgramm[indPremierLettre][indDeuxiemeLettre][indTroisiemeLettre][indQuatriemeLettre];
		}

		//Pour calculer le score il faut multiplier tout les probabilt� puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilit� on pr�f�re appliquer directement le log
		//Donc dans bigramme on d�ja appliquer le log
		//il ne reste plus qu'� faire l'addition
	}


	return score / tpTexte; // on normalise par le nombre de charact�res
}