#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
using namespace std;

int main()
{
	const string fichier_freq_alphabet_base = "Resource Files/FrequencesLettres.txt";
	const string fichier_texte_crypt = "Resource Files/mess_crypt.txt";
	const string fichier_bigrammes = "Resource Files/BigrammesTexte.txt";
	const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freq_alphabet_base[26];
	char texte_crypt[100000];
	char texte_trad[100000];
	float bigrammes[26][26];
	char liste_mots[350000][50];
	
	float best_score;
	char best_proposition[27];

	float score_actuel;
	char proposition_actuelle[27];

	float score_courant;
	char proposition_courante[27];


	//On convertit le texte contenu dans un fichier en un tableau de caractères et on en récupère sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de réels à 2 entrées (étant les fréquences d'apparitions
	SetBigramme(fichier_bigrammes, bigrammes);

	//On ajoute les fréquences d'apparitions des lettres contenus dans un fichier dans un tableau de réels
	FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	
	//On génère une proposition de clé initiale
	Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, best_proposition);

	//On applique la proposition de clé sur le texte
	ApplicationProposition(texte_crypt,taille_texte,best_proposition,texte_trad);

	//On calcule le score de cette application
	score_actuel = Score(texte_crypt, taille_texte, bigrammes);
	best_score = score_actuel;

	//On utilise ensuite l'algorithme de Metropolis
	best_score = MetropolisBoucle(proposition_courante, texte_crypt, proposition_courante,proposition_actuelle,best_proposition,taille_texte,bigrammes);

	//Initialiser la liste des mots dans
	unsigned int taille_liste_mots = RecuperationMots(fichier_liste_mots, liste_mots);

	//On utilise ensuite l'algorithme de Recuit Simulé
	best_score = Recuit_boucle(proposition_actuelle, bigrammes, texte_crypt, taille_texte, liste_mots, taille_liste_mots, texte_trad, best_score, best_proposition);

	return 0;
}