#include <fstream>
#include <iostream>
#include <string>
#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
using namespace std;


int main(){
	//Varible initialisée, c'est un cursor utiliser pour ajouter les
	//mots dans la variable text au fur et à mesure
	char text[100000];// text de cent milles charctères Initialisation
	unsigned taille;
	long float bigramme[26][26];
	for (unsigned int ligne = 0; ligne < 26; ligne++) {

		InitialisationTableau(bigramme[ligne], 26, valeurInitial)
	}


	

	return 0;
}