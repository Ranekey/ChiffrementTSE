#include "WRfichier.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

unsigned int TextInTab(const string nomfichier, char texte[])
{	

	unsigned int ind = 0;
	ifstream Fichier(nomfichier.c_str());
	//Vérifier la lecture du fichier
	if (Fichier)
	{
		char lettre;
		string ligne;
		while (getline(Fichier, ligne))
		{
			//ajouter tous les caractères un par un dans le tableau
			for (unsigned int i = 0; i < ligne.length()-1; i++)//on n'enregistre pas le carctèr \n
			{

				lettre = ligne[i];
				texte[ind+i] = lettre;
				
			}
			texte[ind + ligne.length() - 1] = ' ';
			ind = ind + ligne.length();
			//i = ligne.length()-2
		}
	}
	else
	{
		cout << "Le fichier n'a pas été lu.";
	}
	return ind; 
}