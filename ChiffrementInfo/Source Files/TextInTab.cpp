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
				
				//lettre = RemoveAccent(ligne[i]); // on peut supposer qu'il n'y aura pas d'accent
				//lettre = UpperCase(lettre);
				//lettre = RemoveWeirdCharactre(lettre);
				
				lettre = ligne[i];
				texte[ind] = lettre;
				ind = ind + 1;
			}
		
			//texte.append(ligne);
			
			
		}
	}
	else
	{
		cout << "Le fichier n'a pas été lu.";
	}

	return ind; //cela correspond à la taille pratique du tableau
}