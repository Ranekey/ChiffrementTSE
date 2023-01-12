#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
#include <filesystem>
#include <iostream>
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
	

	unsigned int tpTexte = 0;
	char texte[100000];
	string nomFichier = "./Resource Files/TestText.txt";
	tpTexte = TextInTab(nomFichier, texte);
	cout << texte;

	/*
	
	char texte[100] = "BONJOUR CECI EST UN TEST DE LA FONCTION FREQAPPARITIONS. Merci !";
	float freq[26]; //Le tableau des fréquences d'apparations de chaque lettres
	char proposition[27];
	
	FreqApparitions(texte, freq);

	//Affichage des valeurs du tableau freq

	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	dicoFreq apparitions[26];
	AssociationFreq(alphabet, freq, apparitions);

	for (int i = 0; i < 26; i++)
	{
		cout << apparitions[i].caractere << " : " << apparitions[i].frequence << endl;
	}
	*/
	return 0;
}