#include "decrypter.h"
#include <random>
#include <iostream>
#include <math.h>
#include "WRfichier.h"
using namespace std;



bool Metropolis(const float score_actuel, const float score_courant, const unsigned int taille)
{
	//Générateur de nombre aléatoire
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, 1);
	
	
	float x = dist(gen); // génére un nombre aléatoire entre 0 et 1
	float p = exp((score_courant - score_actuel) * taille);
	
	return x < p; // Si vrai on accepte la proposition
}

float MetropolisBoucle(const char texte_crypt[], const unsigned int taille_texte, const float bigrammes[42][42], char texte_crypt_courant[], char proposition_courante[], char proposition_actuelle[], char best_proposition[])
{
	
	// Initialisation de proposition actuelle et courante avec la meilleure proposition
	Copy(best_proposition, 27, proposition_actuelle);
	Copy(best_proposition, 27, proposition_courante);

	// Application de proposition actuelle sur le texte
	ApplicationProposition(texte_crypt, taille_texte, proposition_actuelle, texte_crypt_courant);

	// Initialisation variable boucle
	float best_score = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);
	float score_actuel = best_score;
	float score_courant;
	const unsigned int MAXITTER = 100000;
	unsigned int i = 0;
	
	while (i < MAXITTER)
	{
		//Nouvelle proposition et Application
		Proposition(26, proposition_courante);
		ApplicationProposition(texte_crypt, taille_texte, proposition_courante, texte_crypt_courant);

		score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);

		// Choix de garder la proposition ou non
		if (Metropolis(score_actuel, score_courant, taille_texte))
		{
			//On met a jour la proposition actuelle  et le score
			Copy(proposition_courante, 26, proposition_actuelle);
			score_actuel = score_courant;

		}
		// on retient la meilleur proposition, donc celle qui à produit le score le plus élèver
		if (score_actuel > best_score) 
		{
			best_score = score_actuel;
			Copy(proposition_actuelle, 26, best_proposition);
		}


		//Pour voir les proposition en temps réel
		i = i + 1;
		cout << " i (m) : " << i;
		cout << " proposition : " << proposition_courante << " et le best_score : " << best_score << endl;

	}

	return best_score;
}

