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

	unsigned int tpTexte = 0;
	char texte[1000];
	const string nomFichier = "Ressource Files/TestText.txt";
	tpTexte = TextInTab(nomFichier, texte);
	cout << texte;

	/*
	

	/*
	for (unsigned int ligne = 0; ligne < 26; ligne++)
	{
		InitialisationTableau(tableau, 26, valeurInitial);
	}
	*/
	return 0;
}