#include "WRfichier.h"


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