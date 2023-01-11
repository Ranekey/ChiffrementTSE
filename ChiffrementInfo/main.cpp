#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
using namespace std;


int main()
{
	//Varible initialis�e, c'est un cursor utiliser pour ajouter les
	//mots dans la variable text au fur et � mesure
	/*
	char text[100000];// text de cent milles charct�res Initialisation
	unsigned taille;
	float tableau[50];
	float valeurInitial = 0.0;

	for (unsigned int ligne = 0; ligne < 26; ligne++)
	{
		InitialisationTableau(tableau, 26, valeurInitial);
	}
	*/

	char texte[100] = "BONJOUR CECI Z EST UN TEST DE LA FONCTION FREQAPPARITIONS. Merci !";
	float freq[26]; //Le tableau des fr�quences d'apparations de chaque lettres
	
	FreqApparitions(texte, freq);

	//Affichage des valeurs du tableau freq
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " : " << freq[i] << endl;
	}
	return 0;
}