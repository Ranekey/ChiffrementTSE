#include<random>
#include<math.h>
#include "decrypter.h"
#include "utils.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

/*
Mets tout les mots dans la liste mot francais dans une variable string 
*/
unsigned int MotInTab(const string nomFichier, string liste_mots)
{
	ifstream fichier(nomFichier.c_str());
	liste_mots = "";
	unsigned int i = 0;
	if (fichier) {
		string ligne;
		
		while (getline(fichier, ligne) ){
			liste_mots.append(ligne);
			liste_mots.append(" ");
			
			i++;
		}
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier";
	}
	
	return i;
}

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

float Recuit_boucle(const char texte_crypt[], char texte_crypt_courant[], const unsigned int taille_texte, char best_proposition[27], string listeMots, const unsigned int taille_liste, const float bigrammes[42][42])
{
	const int MAXITTER = 10000;
	const int FACTEUR_SCORE_MOTS = 4;
	float temperature = 0.05;
	float rho_modif_temperature = 0.999;

	float score_courant = 0;
	float score_mots_courant = 0;
	float score_total_courant = 0;
	char proposition_courante[27];
	Copy(27, proposition_courante, best_proposition);

	float score_total_actuel = 0;
	char proposition_actuelle[27];
	Copy(27, proposition_actuelle, best_proposition);

	float score_total_best = 0;


	ApplicationProposition(texte_crypt, texte_crypt_courant, taille_texte, best_proposition);
	score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);
	score_mots_courant = Score_Mots(texte_crypt_courant, listeMots, taille_liste);
	score_total_courant = FACTEUR_SCORE_MOTS * score_mots_courant + score_courant;
	score_total_actuel = score_total_courant;
	score_total_best = score_total_courant;

	unsigned int k = 0;

	while (k < MAXITTER)
	{
		Proposition(26, proposition_courante);
		ApplicationProposition(texte_crypt, texte_crypt_courant, taille_texte, proposition_courante);
		score_courant = ScoreBigramm(texte_crypt_courant, taille_texte, bigrammes);
		score_mots_courant = Score_Mots(texte_crypt_courant, listeMots, taille_liste);
		score_total_courant = FACTEUR_SCORE_MOTS * score_mots_courant + score_courant;

		cout << "Le score actuel : " << score_total_actuel << "Le score courant : " << score_total_courant << endl;
		if (Recuit(score_total_actuel, score_total_courant, temperature))
		{
			score_total_actuel = score_total_courant;
			Copy(27, proposition_actuelle, proposition_courante);
		}
		if (score_total_actuel > score_total_best)
		{
			score_total_best = score_total_actuel;
			Copy(27, best_proposition, proposition_actuelle);
		}
		//Faire baisser la température dans la recherche
		temperature = temperature * rho_modif_temperature;

		//Pour voir les propositions en temps réel
		k = k + 1;
		//cout << " k (r) : " << k;
		//cout << " proposition : " << proposition_courante << " et le best_score : " << score_total_best << endl;
		
	}
	return score_total_best;
}