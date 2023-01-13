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
	
	char alphabetBase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freq_alphabet_base[26];
	char texte_crypt[10000];
	char proposition_actuelle[27];
	float bigrammes[26][26];


	//On convertit le texte contenu dans un fichier en un tableau de caractères et on en récupère sa taille
	const unsigned int taille_texte = TextInTab(fichier_texte_crypt, texte_crypt);

	//On convertit les bigrammes contenus dans un fichier dans un tableau de réels à 2 entrées
	SetBigramme(fichier_bigrammes, bigrammes);

	//On ajoute les fréquences d'apparitions des lettres contenus dans un fichier dans un tableau de réels
	FreqToTab(fichier_freq_alphabet_base, freq_alphabet_base);
	
	//On génère une proposition de clé initiale
	Proposition_initiale(alphabetBase, freq_alphabet_base, texte_crypt, proposition_actuelle);

	//On applique la proposition de clé sur le texte (refair pour ne pas modifier le texte original)
	ApplicationProposition(proposition_actuelle, texte_crypt, taille_texte);

	//On calcule le score de cette application
	float score_actuelle = Score(texte_crypt, taille_texte, bigrammes);
	//Varible initialisée, c'est un cursor utiliser pour ajouter les
	//mots dans la variable text au fur et à mesure
	/*
	char text[100000];// text de cent milles charctères Initialisation
	unsigned taille;
	float tableau[26];
	float valeurInitial = 0.0;
	InitialisationTableau(tableau, 26, valeurInitial);
	for (unsigned int i = 0; i < 26; i++) {
		cout << tableau[i];
	}
	*/

	/*
	
	*/
	//setlocale(LC_ALL, "fr-FR");
	/*
	
	unsigned int tpTexte = 0;
	bool Erreur;
	const unsigned int occurenceTotal[26] = { 858233, 102743, 331243, 392195, 1830803, 117642, 101900, 89870, 769610, 47935, 2511, 598945,
		302325, 749605, 555439, 294371, 127336, 698456, 856958, 760068, 671894, 172783, 2885, 43647, 29651, 15632 };
	float scorre = 0;
	char texte[1000000];
	const string nomFichier = "Ressource Files/TestText.txt";
	const string nomFichierBigramme = "Ressource Files/BigrammeTexte.txt";
	tpTexte = TextInTab(nomFichier, texte);
	cout << tpTexte << endl;
	float bigramme[26][26];
	Erreur = SetBigramme(nomFichierBigramme, bigramme, occurenceTotal);
	scorre = Score(texte, tpTexte, bigramme);
	cout << scorre;
	//cout <<"Nouvel jhu " << bigramme[6 ][7] << endl;
	*/
	/*
	

	/*
	for (unsigned int ligne = 0; ligne < 26; ligne++)
	{
		InitialisationTableau(tableau, 26, valeurInitial);
	}
	*/
	/*
	const string nomFichier("Ressource Files/FrequencesLettres.txt");
	float tabFreq[26];
	FreqToTab(nomFichier,tabFreq);
	for (int i = 0; i < 26; i++)
	{
		cout << tabFreq[i] << endl;
	}*/

	return 0;
}