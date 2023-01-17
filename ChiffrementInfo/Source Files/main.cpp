#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
using namespace std;

int main()
{
	//Initialiser le chemin d'accès aux différents fichiers
	const string fichier_texte_crypt = "message_cry.txt";
	const string fichier_texte_decrypt = "message_cry_decry.txt";
	const string fichier_key = "key.txt";

	//Fichiers ressources
	const string fichier_freq_alphabet_base = "Resource Files/FrequencesLettres.txt";
	const string fichier_bigrammes = "Resource Files/BigrammesTexte.txt";
	const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freq_alphabet_base[26];

	char texte_crypt[1000];
	char texte_crypt_courant[1000];


	float best_score;
	char best_proposition[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	float score_actuelle;
	char proposition_actuelle[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	float score_courant;
	char proposition_courante[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


	float bigrammes[42][42];
	bool bigrammesExiste;
	
	//On convertit le texte contenu dans un fichier en un tableau de caractères et on en récupère sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt);
	TextInTab(fichier_texte_crypt, texte_crypt_courant);


	//On fait l'analyse fréquentielle des occurences de chaques lettres avec la fonction Proposition_initiale, ceci nous donne une clé de départ
	FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, taille_texte, best_proposition);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de réels à 2 entrées (étant les fréquences d'apparitions)
	bigrammesExiste = SetBigrammeComplet(fichier_bigrammes, bigrammes);

	if (bigrammesExiste)
	{
		
		//best_score = MetropolisBoucle(texte_crypt, taille_texte, bigrammes, texte_crypt_courant,  proposition_courante, proposition_actuelle, best_proposition);

		//Ici, une deuxième méthode avec un calcul sur le nombre de mots francais présents (qui n'est pas assez efficace de part le parcours de la liste de mots)
		best_score = Recuit_boucle(texte_crypt, taille_texte, fichier_liste_mots, bigrammes, texte_crypt_courant, best_proposition);
	}
	else
	{
		cout << "Erreur dans la création du bigramme";
	}
	
	//Génère le fichier avec la clé et le message décrypter
	Affiche_cle(fichier_texte_decrypt, fichier_key, best_proposition, texte_crypt, taille_texte);

	return 0;
}