#include<random>
#include<math.h>
#include <decrypter.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

unsigned int RecuperationMots(const string nomFichier, char liste_mots[][50])
{
	ifstream fichier(nomFichier.c_str());
	unsigned int ind = 0;

	if (fichier)
	{
		string ligne;

		do
		{
			fichier >> liste_mots[ind];
			ind++;
		} while (getline(fichier, ligne));
	}
	else
	{
		//Erreur de lecture
		cout << "Impossible de lire le fichier" << endl;
	}
	return ind;
}

bool Recuit(float score_actuel, float score_courant, float temperature)
{
	bool b;
	float prob;
	float x = (float)rand() / (float)RAND_MAX; // génére un nombre aléatoire entre 0 et 1

	//Calcul de la probabilité selon la loi d'algorithme de Recuit Simulé
	prob = exp(-(score_courant - score_actuel) / temperature);

	return (x < prob);

}

float Recuit_boucle(char proposition_actuelle[27], float bigramme[26][26], const char texte_initial[], const unsigned int tpTexte_initial, const char liste_mots[][50], const unsigned int taille_liste, char texte_trad[], float best_score, char best_proposition[27])
{
	const int NB_ITTERATIONS = 2000;
	const unsigned int k = 0;
	const int FACTEUR_SCORE_MOTS = 4;
	float temperature = 0.05;
	float rho_modif_temperature = 0.99;
	float score_mots;
	float score_total;
	char proposition_courante[27];
	float score_courant = 0;
	float score_actuel = 0;


	score_mots = Score_Mots(texte_trad, liste_mots, taille_liste);
	float best_score_total = FACTEUR_SCORE_MOTS * score_mots + best_score;

	while (k < NB_ITTERATIONS)
	{
		Proposition(27, proposition_courante);
		//ApplicationProposition(texte_initial, tpTexte_initial,proposition_courante,texte_trad);
		score_mots = Score_Mots(texte_trad, liste_mots, taille_liste);
		score_courant = Score(texte_trad, tpTexte_initial, bigramme);
		score_total = FACTEUR_SCORE_MOTS * score_mots + score_courant;

		if (Recuit(score_actuel, score_courant, temperature))
		{
			score_actuel = score_total;
			proposition_actuelle = proposition_courante;
		}
		if (score_actuel > best_score_total)
		{
			best_score_total = score_actuel;
			best_proposition = proposition_actuelle;
		}
		
	}
	return best_score;
}