#include "WRfichier.h"
#include "utils.h"
#include <iostream>
using namespace std;

unsigned int TextInTab(const string nomfichier, char texte[])
{	

	unsigned int ind = 0;
	ifstream Fichier(nomfichier.c_str());
	if (Fichier)
	{
		
		char lettre;
		string ligne;
		while (getline(Fichier, ligne))
		{

			
			for (unsigned int i = 0; i < ligne.length(); i++)
			{
				
				
				
				lettre = ligne[i];
				texte[ind] = lettre;
				ind = ind + 1;
			}
		

			
		}
	}
	else
	{
		cout << "Le fichier n'a pas été lu.";
	}

	return ind; 
}