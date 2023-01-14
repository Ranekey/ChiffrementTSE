#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
using namespace std;

int main()
{
	const string fichier_freq_alphabet_base = "Resource Files/FrequencesLettres.txt";
	const string fichier_texte_crypt = "Resource Files/TextCrypter.txt";
	const string fichier_texte_decrypt = "Resource Files/TextDeCrypter.txt";
	const string fichier_bigrammes = "Resource Files/BigrammesTexte.txt";
	const string fichier_quadgramm = "Resource Files/french_quadgrams.txt";
	const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//char alphabetComplet[43] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";
	float freq_alphabet_base[26];

	//string texte_crypt_courant;
	char texte_crypt[1000];
	//string texte_crypt_actuelle;
	char texte_crypt_courant[1000];


	float best_score;
	char best_proposition[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//char best_proposition[43];
	//string best_proposition = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";

	float score_actuelle;
	char proposition_actuelle[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//char proposition_actuelle[43];
	//string proposition_actuelle = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";

	float score_courant;
	char proposition_courante[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//char proposition_courante[43];
	//string proposition_courante = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";


	float bigrammes[42][42];
	//float quadgramm[42][42][42][42];
	bool bigrammesExiste;
	
	//On convertit le texte contenu dans un fichier en un tableau de caractËres et on en rÈcupËre sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt);
	TextInTab(fichier_texte_crypt, texte_crypt_courant);


	//On fait l'analyse frÈquentielle des occurences de chaques lettres avec la fonction Proposition_initiale, ceci nous donne une clÈ de dÈpart
	FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, best_proposition);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de rÈels ‡ 2 entrÈes (Ètant les frÈquences d'apparitions)
	bigrammesExiste = SetBigrammeComplet(fichier_bigrammes, bigrammes);


	if (bigrammesExiste) {
		
		best_score = MetropolisBoucle(texte_crypt, taille_texte, bigrammes, texte_crypt_courant,  proposition_courante, proposition_actuelle, best_proposition);
		cout << "DeuxiËme mÈthode : " << endl;
		best_score = Recuit_boucle(texte_crypt, taille_texte, fichier_liste_mots, bigrammes, texte_crypt_courant, best_proposition);
	}
	else {
		cout << "Erreur dans la crÈation du bigramme";
	}
	
	Affiche_cle(fichier_texte_decrypt, best_proposition, texte_crypt, taille_texte);


	return 0;
}