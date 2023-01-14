#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// à suppprimer
#include <math.h>
#include <string>


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

float Score_Mots(const char texte[], string listeMots, const unsigned int taille_liste)
{
	//unsigned int occurence = 0;
	//char mot_actuel[50];
	int mots_corrects = 0; // == occurence
	int nb_mots = 0;
	int j = 0;
	string motRecherche;

	while (texte[j] != '\0')
	{
		for (int i = 0; texte[j] != ' '; i++)
		{
			motRecherche.push_back(tolower(texte[j]));
			j++;
		}
		nb_mots++;
		j++;
		if (listeMots.find(motRecherche) >= 0) {
			mots_corrects = mots_corrects + listeMots.find(motRecherche);
		}

		
	}
	return (float)mots_corrects / (float)nb_mots;
}