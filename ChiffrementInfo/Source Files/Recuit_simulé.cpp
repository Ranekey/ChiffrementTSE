#include<random>
#include<math.h>
#include "decrypter.h"
#include "utils.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

unsigned int RecuperationMots(const string nomFichier, char liste_mots[][50])
{
	/*
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
	*/
	return 0;
}

string MotInTab(const string nomFichier) {
	ifstream fichier(nomFichier.c_str());
	string mots = "";
	if (fichier) {
		string ligne;
		string mots;
		while (getline(fichier, ligne) ){
			mots.append(ligne);
			mots.append(" ");
			cout << mots;
		}

	}
	else
	{
		cout << "Pas ouvert motintab";
	}
	
	return mots;
}

bool Recuit(float score_actuel, float score_courant, float temperature)
{
	bool b;
	float prob;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, 1);


	float x = dist(gen); // génére un nombre aléatoire entre 0 et 1 // génére un nombre aléatoire entre 0 et 1

	//Calcul de la probabilité selon la loi d'algorithme de Recuit Simulé
	prob = exp(-(score_courant - score_actuel) / temperature);

	return (x < prob);

}

float Recuit_boucle(char proposition_actuelle[27], char best_proposition[27], char proposition_courante[27], float bigramme[42][42], char texte_crypt_actuelle[], unsigned int taille_texte, string listeMots, unsigned int taille_liste, char texte_crypt_courant[], float best_score)
{
	const int NB_ITTERATIONS = 1000;
	unsigned int k = 0;
	const int FACTEUR_SCORE_MOTS = 4;
	//const int FACTEUR_SCORE_MOTS = 1;
	float temperature = 0.05;
	float rho_modif_temperature = 0.99;
	float score_mots;
	float score_total_courant;
	float score_courant = 0;
	


	score_mots = Score_Mots(texte_crypt_actuelle, listeMots, taille_liste);
	//float best_score_total = FACTEUR_SCORE_MOTS * score_mots + best_score;
	float best_score_total = FACTEUR_SCORE_MOTS * score_mots + best_score;
	float score_actuel = best_score_total;

	while (k < NB_ITTERATIONS)
	{
		Proposition(26, proposition_courante);
		ApplicationProposition(taille_texte, proposition_courante, texte_crypt_courant);
		score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigramme);
		score_mots = Score_Mots(texte_crypt_courant, listeMots, taille_liste);
		score_total_courant = FACTEUR_SCORE_MOTS * score_mots + score_courant;

		if (Recuit(score_actuel, score_total_courant, temperature))
		{
			score_actuel = score_total_courant;
			Copy(taille_texte, texte_crypt_actuelle, texte_crypt_courant);
			Copy(26, proposition_actuelle, proposition_courante);
		}
		if (score_actuel > best_score_total)
		{
			best_score_total = score_actuel;
			Copy(26, best_proposition, proposition_actuelle);
		}
		k = k + 1;
		cout << " k (r) : " << k;
		cout << " score_mots : " << score_mots << endl;
		
	}
	return best_score;
}