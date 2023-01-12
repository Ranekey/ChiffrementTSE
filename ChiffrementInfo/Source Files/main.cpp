#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
using namespace std;

int main()
{
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

	/*
	

	/*
	for (unsigned int ligne = 0; ligne < 26; ligne++)
	{
		InitialisationTableau(tableau, 26, valeurInitial);
	}
	*/
	const string nomFichier("Ressource Files/FrequencesLettres.txt");
	float tabFreq[26];
	FreqToTab(nomFichier,tabFreq);
	for (int i = 0; i < 26; i++)
	{
		cout << tabFreq[i] << endl;
	}

	return 0;
}