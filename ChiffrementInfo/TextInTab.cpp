#include "WRfichier.h"

unsigned int TextInTab(string nomfichier, char texte[])
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
		//Erreur
	}
	return ind; //cela correspond à la taille pratique du tableau
}