#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"


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
	for (unsigned int ligne = 0; ligne < 26; ligne++)
	{
		InitialisationTableau(tableau, 26, valeurInitial);
	}
	*/
	
	
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char texte[100] = "BONJOUR CECI EST UN TEST DE LA FONCTION FREQAPPARITIONS. Merci !";
	float freq[26]; //Le tableau des fréquences d'apparations de chaque lettres

	return 0;
}