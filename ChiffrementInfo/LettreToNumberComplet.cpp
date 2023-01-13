#include "decrypter.h"
#include <string>

int LettreToNumberComplet(char lettre)
{
	int indLettre;
	string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÂÄÇÉÈÊËÎÏÔÖÙÛÜŸ";

	indLettre = ALPHABET.find(lettre);
	return indLettre;



}