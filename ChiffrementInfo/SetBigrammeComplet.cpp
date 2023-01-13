#include "WRfichier.h"
#include "decrypter.h"
#include "utils.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;
/*
SetBigramme permet d'enregistrer dans un tableau 2D le log des fr�quence d'apparation
de chaque bigramme de lettres,
Il faut au pr�alable initialiser le tableau bigramme or nous sommes faces � des contraintes
pour les charact�re sp�ciaux il ne faut pas qu'il influe sur le score
leur valeurs initiales devra donc �tre de 1 car log(1) = 0
pour les bigrammes qui ne sont pas dans le fichier texte cela signifie que leur fr�quente d'apparition
est tr�s proche de 0.
On va assumer qu'il apparaissant 1 fois au minimum
leur fr�quence d'apparition est donc 1/maxBigramme
le log de ce r�sultat est -7.02 (environ)
cela sera donc la valeur � laquelle sera initialis� le tableau (� l'exception des charact�re sp�ciaux)
*/

/*occurenceTotal = [858233,102743,331243,392195,1830803,117642,101900,89870,769610,47935,2511,598945,
302325,749605,555439,294371,127336,698456,856958,760068,671894,172783,2885,43647,29651,15632];

*/
bool SetBigrammeComplet(string nomfichier, float bigramme[42][42])
{
	unsigned int indPremierLettre;
	unsigned int indDeuximeLettre;
	float occurrence;
	bool sansErreur;
	unsigned int maxBigramme = 290000000; //290*10^6
	// renvoie Vrai si le fichier s'est ouvert, faux sinon
	// Chaque ligne du fichier est constituer de la mani�re suivante
	// 1erLettre2i�meLettre nombreOccurence
	// Nous allons nous servir de cette particularit�
	ifstream Fichier(nomfichier.c_str());
	if (Fichier) {
		sansErreur = true;
		string ligne;
		float valMin = 0.01;
		char ligneChar[11];
		// Initialisation 
		for (unsigned int i = 0; i < 42; i++) {
			for (unsigned int j = 0; j < 42; j++) {
						bigramme[i][j] = log(valMin / maxBigramme);
				//bigramme[i][j] = log(1.0/occurenceTotal[i]);
				
				//cout << "ligne : " << i << " col : " << j << " valeur : " << bigramme[i][j]<< endl;
			}
			//bigramme[i][26] = 0; //Charact�res sp�ciaux , a voir si on conserve
		}
		//InitialisationTableau(bigramme[26], 27, 0);// Initalise la dernier colone � 0;
		// Calcule fr�quence 
		while (getline(Fichier, ligne)) {
			
				indPremierLettre = LettreToNumberComplet(ligne[0]);
				indDeuximeLettre = LettreToNumberComplet(ligne[1]);
				
				strcpy_s(ligneChar, ligne.c_str()); // convertie ligne en un tableau de charct�re enregistrer dans ligneChar
				for (int i = 0; i < 3; i++) {
					ligneChar[i] = '0';
				}
				occurrence = atoi(ligneChar);
				//Pour calculer le score il faut multiplier tout les probabilt� puis appliquer le log
				//Or on sait que log(A*B) = log(A) + log(B)
				//Vu que l'on va avoir des petites probabilit� je pr�f�re appliquer directement le log
				//bigramme[indPremierLettre][indDeuximeLettre] = log(occurrence / occurenceTotal[indPremierLettre] + valMin);
				bigramme[indPremierLettre][indDeuximeLettre] = log(occurrence / maxBigramme);
				//cout << "bigramme : " << bigramme[indPremierLettre][indDeuximeLettre] << " occurence = " << occurrence << " rapport = " << occurrence / maxBigramme << endl;
			}
		
	}
	else {
		sansErreur = false; //Erreur dans la lecture du fichier
	}
	return sansErreur;
}



/*
C'est m�thode est � utiliser si l'on se base sur un texte  pour cr�er notre propre bigramme
Cependant le site https://www.apprendre-en-ligne.net/crypto/stat/francais.html propose d�j� un bigramme
Nous allons donc utiliser le leur

bool SetBigramme(string nomfichier, float bigramme[26][26]) {
	char texteBigramme[100000];// cent milles charct�re maximum
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
			// bien s'assurer d'initialiser les valeurs � 0

		}
	}



}
*/