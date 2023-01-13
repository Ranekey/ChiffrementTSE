#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// à suppprimer
#include <math.h>

float Score(const char texte[], unsigned int tpTexte, float bigramme[26][26])
{
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	float score = 0;
	for (unsigned int indChar = 1; indChar < tpTexte; indChar++)
	{
		indDeuxiemeLettre = LettreToNumber(texte[indChar]);
		indPremierLettre = LettreToNumber(texte[indChar - 1]);
		if (indPremierLettre != -1 && indDeuxiemeLettre != -1) {
			//cout << "score : " << score << " bigramme : " << bigramme[indPremierLettre][indDeuxiemeLettre] <<endl;;
			score = score + bigramme[indPremierLettre][indDeuxiemeLettre];
		}
		
		//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilité on préfère appliquer directement le log
		//Donc dans bigramme on déja appliquer le log
		//il ne reste plus qu'à faire l'addition
	}


	return score/tpTexte; // on normalise par le nombre de charactères
}

float Score_Mots(const char texte[], const char liste_mots[][50], const unsigned int taille_liste)
{
	char mot_actuel[50];
	int mots_corrects = 0;
	int nb_mots = 0;
	int j = 0 ;

	while (texte[j] != '\0')
	{
		for (int i = 0; texte[j] != ' '; i++)
		{
			mot_actuel[i] = texte[j];
			j++;
		}
		nb_mots++;
		j++;
		for (int k = 0; k < taille_liste; k++)
		{
			if (strcmp(mot_actuel, liste_mots[k]))
			{
				mots_corrects++;
				break;
			}
		}
	}
	return (float)mots_corrects / (float)nb_mots;
}