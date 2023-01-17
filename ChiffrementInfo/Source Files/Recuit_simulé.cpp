#include<random>
#include<math.h>
#include "decrypter.h"
#include "WRfichier.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

bool Recuit(const float score_actuel, const float score_courant, const float temperature)
{	
	bool b;
	float prob;
	//crée un nombre aléatoire 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, 1);


	float x = dist(gen); // génére un nombre aléatoire entre 0 et 1

	//Calcul de la probabilité selon la loi d'algorithme de Recuit Simulé
	prob = exp( - (score_courant - score_actuel) / temperature);

	return (x < prob);

}

float Recuit_boucle(const char texte_crypt[],const int* tabOccurenceMotLettre,const unsigned int taille_texte, const string dico, const float bigrammes[42][42], char texte_crypt_courant[], char best_proposition[27])
{
	//Initialisation des valeurs pour le calcul
	const int MAXITTER = 2000;
	const int FACTEUR_SCORE_MOTS = 4;
	float temperature = 0.05;
	float rho_modif_temperature = 0.999;

	//Initialisation des variables
	float score_courant = 0;
	float score_mots_courant = 0;
	float score_total_courant = 0;
	char proposition_courante[27];
	Copy(best_proposition, 27, proposition_courante);

	float score_total_actuel = 0;
	char proposition_actuelle[27];
	Copy(best_proposition, 27, proposition_actuelle);

	float score_total_best = 0;

	//Calcul du score de la meilleure proposition précédemment trouvée pour avoir un score initial
	ApplicationProposition(texte_crypt, taille_texte, best_proposition, texte_crypt_courant);
	score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);
	score_mots_courant = Score_Mots(texte_crypt_courant, taille_texte,tabOccurenceMotLettre,dico);
	score_total_courant = FACTEUR_SCORE_MOTS * score_mots_courant + score_courant;
	score_total_actuel = score_total_courant;
	score_total_best = score_total_courant;

	//Boucle de calcul pour chercher la meilleure proposition
	unsigned int k = 0;


	while (k < MAXITTER)
	{
		//Modifier la proposition courante puis calculer son score
		Proposition(26, proposition_courante);
		ApplicationProposition(texte_crypt, taille_texte, proposition_courante, texte_crypt_courant);
		score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);
		score_mots_courant = Score_Mots(texte_crypt_courant, taille_texte,tabOccurenceMotLettre ,dico);
		score_total_courant = FACTEUR_SCORE_MOTS * score_mots_courant + score_courant;

		//Evaluer si l'on garde ou non la propostion
		if (Recuit(score_total_actuel, score_total_courant, temperature))
		{
			score_total_actuel = score_total_courant;
			Copy(proposition_courante, 27, proposition_actuelle);
		}
		if (score_total_actuel > score_total_best)
		{
			score_total_best = score_total_actuel;
			Copy(proposition_actuelle, 27, best_proposition);
		}
		//Faire baisser la température dans la recherche
		temperature = temperature * rho_modif_temperature;

		//Pour voir les propositions en temps réel
		k = k + 1;
		cout << " k (r) : " << k;
		cout << " proposition : " << proposition_courante << " et le best_score : " << score_total_best << endl;
		
	}
	return score_total_best;
}