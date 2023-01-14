#include "decrypter.h"
#include <string>
#include <iostream>
using namespace std;

void ApplicationProposition( unsigned int tpTexte, char proposition[], char texte_trad[])
{
	unsigned int indLettre;

	for (unsigned int indTexte = 0; indTexte < tpTexte ; indTexte++)
	{
		indLettre = LettreToNumberComplet(texte_trad[indTexte]);// convertie chaque lettre en son rang dans l'alphabet
		//Proposition est comme un dictionnaire, au rang 0 c'est la lettre A, au rang 1 la lettre B etc...
		// la clé est l'indice (donc indLettre), la valeur est  Proposition[indLettre]
		if (indLettre == -1) {
			texte_trad[indTexte] = ' ';
		}
		else {
			texte_trad[indTexte] = proposition[indLettre];
		}
		
	}
}