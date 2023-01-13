#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
using namespace std;

int main()
{
	//MAIN PRINCIPAL
	const string fichier_freq_alphabet_base = "Resource Files/FrequencesLettres.txt";
	const string fichier_texte_crypt = "Resource Files/mess_crypt.txt";
	const string fichier_bigrammes = "Resource Files/BigrammesTexte.txt";
	const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freq_alphabet_base[26];
	char texte_crypt[10000];
	char proposition_actuelle[27];
	float bigrammes[26][26];


	//On convertit le texte contenu dans un fichier en un tableau de caractères et on en récupère sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de réels à 2 entrées (étant les fréquences d'apparitions
	SetBigramme(fichier_bigrammes, bigrammes);

	//On ajoute les fréquences d'apparitions des lettres contenus dans un fichier dans un tableau de réels
	FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	
	//On génère une proposition de clé initiale
	Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, proposition_actuelle);

	//On applique la proposition de clé sur le texte (refair pour ne pas modifier le texte original)
	ApplicationProposition(proposition_actuelle, texte_crypt, taille_texte);

	//On calcule le score de cette application
	float score_actuelle = Score(texte_crypt, taille_texte, bigrammes);

	return 0;
}