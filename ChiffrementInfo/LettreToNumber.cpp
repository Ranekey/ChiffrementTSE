#include "decrypter.h"



unsigned int LettreToNumber(char lettre) {
	unsigned int indLettre;
	switch (lettre)
	{
	case 'A':
		indLettre = 0;
		break;

	case 'B':
		indLettre = 1;
		break;
	case 'C':
		indLettre = 2;
		break;
	case 'D':
		indLettre = 3;
		break;
	case 'E':
		indLettre = 4;
		break;

	case 'F':
		indLettre = 5;
		break;

	case 'G':
		indLettre = 6;
		break;

	case 'H':
		indLettre = 7;
		break;

	case 'I':
		indLettre = 8;
		break;

	case 'J':
		indLettre = 9;
		break;

	case 'K':
		indLettre = 10;
		break;

	case 'L':
		indLettre = 11;
		break;

	case 'M':
		indLettre = 12;
		break;

	case 'N':
		indLettre = 13;
		break;

	case 'O':
		indLettre = 14;
		break;

	case 'P':
		indLettre = 15;
		break;

	case 'Q':
		indLettre = 16;
		break;

	case 'R':
		indLettre = 17;
		break;

	case 'S':
		indLettre = 18;
		break;

	case 'T':
		indLettre = 19;
		break;

	case 'U':
		indLettre = 20;
		break;

	case 'V':
		indLettre = 21;
		break;

	case 'W':
		indLettre = 22;
		break;

	case 'X':
		indLettre = 23;
		break;

	case 'Y':
		indLettre = 24;
		break;

	case 'Z':
		indLettre = 25;
		break;

	//Tout les carctère spéciaux à ajouter éventuellement
	case ' ':
		indLettre = 26;
		break;
	default:
		//Erreur BG
		break;
	}
	return indLettre;
}