#include"WRfichier.h"
#include <iostream>
#include <fstream>
using namespace std;

void affiche_cle(unsigned int taille,char cle[], char texteDecrypter[], string nomfichier)
{


	ofstream fichier(nomfichier.c_str());  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a réussi
	{
		fichier << "la cle est la suivante : " << cle ;
		fichier << "le texte decrypter est le suivant : ";
		for (unsigned int i = 0; i < taille; i++) {
			fichier << texteDecrypter[i];
		}

		cout << "la cle est la suivante : " << cle<< endl;
		cout << "le texte decrypter est le suivant : ";
		//cout << "la cle est la suivante : " << cle << ' \n'; // retour console
		//cout << "le texte decrypter est le suivant : \n" << texteDecrypter;
		fichier.close();  // on ferme le fichier
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier ou il faut mettre la cle, veuillez verifier que le fichier cle.txt est bien créé !" << endl;
	}

}