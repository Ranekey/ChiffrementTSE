#include "decrypter.h"
#include <string>
using namespace std;

int LettreToNumberComplet(char lettre)
{
	int indLettre;
	string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ��������������ܟ";

	indLettre = ALPHABET.find(lettre);
	return indLettre;



}