#include"WRfichier.h"
#include <iostream>
#include <fstream>
using namespace std;

void Affiche_cle(const string nomfichier_mess,const string nomfichier_key, const char cle[], const char texteDecrypter[], const unsigned int taille)
{
	//Ecriture dans le fichier txt pour le message
	ofstream fichier(nomfichier_mess.c_str());  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a réussi
	{
		fichier << "Le texte decrypté est le suivant : " << endl;
		for (unsigned int i = 0; i < taille; i++) {
			fichier << texteDecrypter[i];
		}
		fichier.close();  // on ferme le fichier
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier du message !" << endl;
	}
	ofstream fichier2(nomfichier_key.c_str());  // on ouvre le fichier en lecture


	//Ecriture dans le fichier txt pour la clé
	if (fichier2)  // si l'ouverture a réussi
	{
		fichier2 << "La clé est la suivante : " << cle << endl;
		//Afficher dans la console
		cout << "la clé est la suivante : " << cle << endl;
		fichier2.close();  // on ferme le fichier
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier de la clé !" << endl;
	}

}