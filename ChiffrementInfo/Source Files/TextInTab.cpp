#include "WRfichier.h"
#include <iostream>
using namespace std;

unsigned int TextInTab(const string nomfichier, char texte[])
{
	unsigned int ind = 0;
	ifstream Fichier(nomfichier.c_str());
	if (Fichier)
	{
		string ligne;
		while (getline(Fichier, ligne))
		{
			for (unsigned int i = 0; i < ligne.length(); i++)
			{
				texte[ind] = ligne[i];
				ind = ind + 1;
			}
			texte[ind] = '\n';
			ind = ind + 1;
		}
	}
	else
	{
		cout << "Le fichier n'a pas été lu.";
	}
	return ind; //cela correspond à la taille pratique du tableau
}