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
	const string fichier_texte_crypt = "Resource Files/TextCrypter.txt";
	const string fichier_texte_decrypt = "Resource Files/TextDeCrypter.txt";
	const string fichier_bigrammes = "Resource Files/BigrammesTexte.txt";
	const string fichier_quadgramm = "Resource Files/french_quadgrams.txt";
	const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetComplet[43] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";
	float freq_alphabet_base[26];
	char texte_crypt[10000];

	//string texte_crypt_courant;
	char texte_crypt_courant[50000];
	//string texte_crypt_actuelle;
	char texte_crypt_actuelle[50000];
	
	string listeMots;
	
	
	char texte_trad[10000];
	float bigrammes[42][42];
	//float quadgramm[42][42][42][42];
	char liste_mots[35][50];
	
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

	bool bigrammesExiste;

	//listeMots = MotInTab(fichier_liste_mots);
	//cout << listeMots.length();
	
	//On convertit le texte contenu dans un fichier en un tableau de caractËres et on en rÈcupËre sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt_actuelle);
	TextInTab(fichier_texte_crypt, texte_crypt_courant);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de rÈels ‡ 2 entrÈes (Ètant les frÈquences d'apparitions
	
	bigrammesExiste = SetBigrammeComplet(fichier_bigrammes, bigrammes);

	if (bigrammesExiste) {
		
		best_score = MetropolisBoucle(texte_crypt_actuelle, texte_crypt_courant, taille_texte, proposition_courante, proposition_actuelle, best_proposition, bigrammes);
		//Recuit_boucle(proposition_actuelle, best_proposition, proposition_courante, bigrammes, texte_crypt_actuelle, taille_texte, listeMots, 10, texte_crypt_courant, best_score);
	}
	else {
		cout << "Erreur dans la crÈation du bigramme";
	}
	

	
	affiche_cle(taille_texte,best_proposition, texte_crypt_actuelle, fichier_texte_decrypt);

	

	return 0;
}