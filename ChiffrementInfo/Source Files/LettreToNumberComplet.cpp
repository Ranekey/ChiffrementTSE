#include "decrypter.h"
#include <string>
#include <iostream>// a sup
using namespace std;

int LettreToNumberComplet(const char lettre)
{
	int indLettre;
	string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ��������������ܟ";
	//string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	indLettre = ALPHABET.find(lettre);
	return indLettre;
}