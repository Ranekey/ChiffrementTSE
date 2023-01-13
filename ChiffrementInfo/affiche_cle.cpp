#include"WRfichier.h"
#include <iostream>
#include <fstream>
using namespace std;

void affiche_cle(const char cle[], const char texteDecrypter[], string nomfichier)
{


	ofstream fichier(nomfichier.c_str(), ios::in);  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a réussi
	{
		fichier << "la cle est la suivante : " << cle << ' \n';
		fichier << "le texte decrypter est le suivant : \n" << texteDecrypter;

		cout << "la cle est la suivante : " << cle << ' \n'; // retour console
		cout << "le texte decrypter est le suivant : \n" << texteDecrypter;
		fichier.close();  // on ferme le fichier
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier ou il faut mettre la cle, veuillez verifier que le fichier cle.txt est bien créé !" << endl;
	}

}