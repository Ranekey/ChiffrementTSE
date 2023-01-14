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
	//const string fichier_liste_mots = "Resource Files/ListeMotFr.txt";

	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetComplet[43] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¬ƒ«…» ÀŒœ‘÷Ÿ€‹ü";
	float freq_alphabet_base[26];
	char texte_crypt[10000];

	//string texte_crypt_courant;
	char texte_crypt_courant[50000];
	//string texte_crypt_actuelle;
	char texte_crypt_actuelle[50000];
	
	
	char texte_trad[10000];
	float bigrammes[42][42];
	//float quadgramm[42][42][42][42];
	//char liste_mots[350000][50];
	
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

	//On convertit le texte contenu dans un fichier en un tableau de caractËres et on en rÈcupËre sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt_actuelle);
	TextInTab(fichier_texte_crypt, texte_crypt_courant);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de rÈels ‡ 2 entrÈes (Ètant les frÈquences d'apparitions
	
	bigrammesExiste = SetBigrammeComplet(fichier_bigrammes, bigrammes);

	//On ajoute les frÈquences d'apparitions des lettres contenus dans un fichier dans un tableau de rÈels
	//FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	
	//On gÈnËre une proposition de clÈ initiale
	//Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, best_proposition);

	Proposition(26,proposition_actuelle);
	Proposition(26,best_proposition);

	//On applique la proposition de clÈ sur le texte
	//ApplicationProposition(texte_crypt,taille_texte,best_proposition,texte_trad);

	//On calcule le score de cette application

	ApplicationProposition(taille_texte, proposition_actuelle, texte_crypt_actuelle);

	
	best_score = ScoreBigramm(texte_crypt_actuelle,taille_texte, bigrammes);

	//On utilise ensuite l'algorithme de Metropolis

	
	//ApplicationProposition(taille_texte, proposition_courante, texte_crypt_courant);
	//cout << " texte_crypt_courant : " << texte_crypt_courant << endl;
	
		//initialisation variable pour decrypter
		
		score_actuelle = best_score;

		//ca fait beaucoup de variable mais c++ me laisse pas faire de variable locale
		//proposition_courante;
		//proposition_actuelle;
		//best_proposition;
		//initialisation variable pour boucle
		const unsigned int MINITER = 2000;
		const unsigned int MAXITER = 10000;
		const float scoreExcellent = -2.10; // ‡ adapter et tester
		unsigned int i = 0;
		unsigned int hasard = 0;
		while (i < MAXITER) {
			//Nouvelle proposition
			//proposition_courante = Proposition(); A faire Proposition
			Proposition(26, proposition_courante);
			ApplicationProposition(taille_texte, proposition_courante, texte_crypt_courant);
			
			//cout << " proposition : " << proposition_courante << endl;
			//cout << " proposition_courante : " << proposition_courante << endl;

			score_courant = ScoreBigramm(texte_crypt, taille_texte, bigrammes); // score ‡ changer
			//cout <<" score_courant = " << score_courant << " score_actuelle = " << score_actuelle << endl;
			if (Metropolis(score_courant, score_actuelle, taille_texte)) {
				hasard = hasard + 1;
				Copy(taille_texte, texte_crypt_actuelle, texte_crypt_courant);
				Copy(26, proposition_actuelle, proposition_courante);
				//texte_crypt_actuelle = texte_crypt_courant;
				//proposition_actuelle = proposition_courante;
				score_actuelle = score_courant;
				//cout << "Dedans : "<< hasard << endl;

			}
			if (score_actuelle > best_score) {
				best_score = score_actuelle;
				Copy(26, best_proposition, proposition_actuelle);
				//best_proposition= proposition_actuelle;
			}


			
			i = i + 1;
			cout << " i : " << i;
			cout << " proposition : " << proposition_courante << endl;

			//if (i > MINITER && best_score >= scoreExcellent) {
			//	break; // faut casser la boucle alors
			//}
		}
		//cout <<"best_proposition : " << best_proposition;
		affiche_cle(taille_texte,best_proposition, texte_crypt_actuelle, fichier_texte_decrypt);
		/*
		
		ApplicationProposition(taille_texte, best_proposition, texte_crypt_actuelle);
		i = i + 1;
		cout << " i : " << i;
		cout << " texte_crypt_actuelle : " << texte_crypt_actuelle << endl;
		*/
		//cout << texte_crypt_courant;
		//affiche_cle(best_proposition, texte_crypt_courant, fichier_texte_decrypt);
	



	//affiche_cle(best_proposition, texte_trad, "Resource Files/DecrypterTestTest.txt");



	//Initialiser la liste des mots dans
	//unsigned int taille_liste_mots = RecuperationMots(fichier_liste_mots, liste_mots);

	//On utilise ensuite l'algorithme de Recuit SimulÈ
	//best_score = Recuit_boucle(proposition_actuelle, bigrammes, texte_crypt, taille_texte, liste_mots, taille_liste_mots, texte_trad, best_score, best_proposition);

	return 0;
}