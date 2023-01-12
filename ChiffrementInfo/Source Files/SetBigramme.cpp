#include "WRfichier.h"
#include "decrypter.h"
#include <math.h>
using namespace std;

bool SetBigramme(string nomfichier, long float bigramme[26][26]) {
	const unsigned int maxBigramme = 10525096; // nombre totale de lettre
	unsigned int indPremierLettre;
	unsigned int indDeuximeLettre;
	unsigned int occurrence;
	bool sansErreur; // renvoie Vrai si le fichier s'est ouvert, faux sinon
	// Chaque ligne du fichier est constituer de la manière suivante
	// 1erLettre2ièmeLettre nombreD'occurence
	// Nous allons nous servir de cette particularité
	ifstream Fichier(nomfichier.c_str());
	if (Fichier) {
		sansErreur = true;
		string ligne;
		while (getline(Fichier, ligne)) {
			indPremierLettre = LettreToNumber(ligne[0]);
			indDeuximeLettre = LettreToNumber(ligne[1]);
			occurrence = 0;
			// i commence à 3 car on sait qu'a ligne[2] c'est un espace
			for (unsigned int i = ligne.length(); i > 2; i--) {
				occurrence = occurrence + atoi(&ligne[i]) * pow(10, ligne.length()-i);
				//la fonction atoi est inclue dans lalibraire standard
				//elle permet de convertir un charctère qui est un numéro entre 0 et 9 en un entier
				//la plus petite unité est le dernier charactère
				//Chaque charctère avant lui est dizaine supérieur à lui
				//Exemple 6541 = 6*10^3 + 5*10^2+ 4*10^1 + 1*10^0
			}
			//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
			//Or on sait que log(A*B) = log(A) + log(B)
			//Vu que l'on va avoir des petites probabilité je préfère appliquer directement le log
			bigramme[indPremierLettre][indDeuximeLettre] = log(occurrence / maxBigramme);
		}
	}
	else {
		sansErreur = false; //Erreur dans la lecture du fichier
	}
	return sansErreur;
}



/*
C'est méthode est à utiliser si l'on se base sur un texte  pour créer notre propre bigramme
Cependant le site https://www.apprendre-en-ligne.net/crypto/stat/francais.html propose déjà un bigramme
Nous allons donc utiliser le leur

bool SetBigramme(string nomfichier, float bigramme[26][26]) {
	char texteBigramme[100000];// cent milles charctère maximum
	int tpTexteBigramme;
	int occurences[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	unsigned int indPremierLettre;
	unsigned int indDeuximeLettre;
	char lettre;
	int nbLettres = 0;
	// acquisistion du texte
	tpTexteBigramme = TextInTab(nomfichier, texteBigramme);
	// contenu du fichier enregistrer dans texteBigramme
	if (tpTexteBigramme >= 0) {
		for (unsigned ind i = 1, i < tpTexteBigramme, i++) {
			indPremierLettre = LettreToNumber(texteBigramme[i - 1]);
			indDeuximeLettre = LettreToNumber(texteBigramme[i]);
			bigramme[indPremierLettre][indDeuximeLettre] = bigramme[indPremierLettre][indDeuximeLettre] + 1;
			// bien s'assurer d'initialiser les valeurs à 0

		}
	}

	

}
*/