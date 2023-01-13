#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;

bool SetQuadgramm(string nomfichier, float quadgramm[42][42][42][42])
{
	unsigned int indPremierLettre;
	unsigned int indDeuximeLettre;
	unsigned int indTroisimeLettre;
	unsigned int indQuatrimeLettre;
	float occurrence;
	bool sansErreur;
	unsigned int maxBigramme = 290000000;//290*10^6
	// renvoie Vrai si le fichier s'est ouvert, faux sinon
	// Chaque ligne du fichier est constituer de la manière suivante
	// 1erLettre2ièmeLettre nombreOccurence
	// Nous allons nous servir de cette particularité
	ifstream Fichier(nomfichier.c_str());
	if (Fichier) {
		sansErreur = true;
		string ligne;
		float valMin = 0.00000000000001;
		char ligneChar[11];
		// Initialisation 
		for (unsigned int i = 0; i < 42; i++) {
			for (unsigned int j = 0; j < 42; j++) {
				for (unsigned int k = 0; k < 42; k++) {
					for (unsigned int l = 0; l < 42; l++) {
						//bigramme[i][j] = log(1.0/occurenceTotal[i]);
						quadgramm[i][j][k][l] = log(0.01 / maxBigramme);
						//cout << "ligne : " << i << " col : " << j << " valeur : " << bigramme[i][j]<< endl;
					}
				}
				
			}
			//bigramme[i][26] = 0; //Charactères spéciaux , a voir si on conserve
		}
		//InitialisationTableau(bigramme[26], 27, 0);// Initalise la dernier colone à 0;
		// Calcule fréquence 
		while (getline(Fichier, ligne)) {
			indPremierLettre = LettreToNumberComplet(ligne[0]);
			indDeuximeLettre = LettreToNumberComplet(ligne[1]);
			indTroisimeLettre = LettreToNumberComplet(ligne[2]);
			indQuatrimeLettre = LettreToNumberComplet(ligne[3]);
			strcpy_s(ligneChar, ligne.c_str()); // convertie ligne en un tableau de charctère enregistrer dans ligneChar
			for (int i = 0; i < 5; i++) {
				ligneChar[i] = '0';
			}
			occurrence = atoi(ligneChar);
			//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
			//Or on sait que log(A*B) = log(A) + log(B)
			//Vu que l'on va avoir des petites probabilité je préfère appliquer directement le log
			//bigramme[indPremierLettre][indDeuximeLettre] = log(occurrence / occurenceTotal[indPremierLettre] + valMin);
			quadgramm[indPremierLettre][indDeuximeLettre][indTroisimeLettre][indQuatrimeLettre] = log(occurrence / maxBigramme);
			//cout << "bigramme : " << bigramme[indPremierLettre][indDeuximeLettre] << " occurence = " << occurrence << " rapport = " << occurrence / maxBigramme << endl;
		}
	}
	else {
		cout << " Pas ouver set";
		sansErreur = false; //Erreur dans la lecture du fichier
	}
	return sansErreur;
}