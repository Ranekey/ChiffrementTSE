#include "decrypter.h"

void ApplicationProposition(const char proposition[], char texte[], unsigned int tpTexte)
{
	unsigned int indLettre;

	for (unsigned int indTexte = 0; indTexte < tpTexte ; indTexte++)
	{
		indLettre = LettreToNumber(texte[indTexte]);// convertie chaque lettre en son rang dans l'alphabet
		//Proposition est comme un dictionnaire, au rang 0 c'est la lettre A, au rang 1 la lettre B etc...
		// la clé est l'indice (donc indLettre), la valeur est  Proposition[indLettre]
		texte[indTexte] = proposition[indLettre];//
	}
}