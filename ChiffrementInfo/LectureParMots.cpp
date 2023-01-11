#include <iostream>
#include <fstream>
using namespace std;
#include "WRfichier.h"

void LectureParMots(string nomfichier)
{
	ifstream fichier(nomfichier.c_str());
	string ligne; //ligne actuel
	if (fichier)
	{
		getline(fichier, ligne);
		unsigned int ind = 0;
		unsigned int debutMot = ind;
		unsigned int finMot = 0;
		unsigned int tailleMot = 0;
		unsigned int indMot = 0;
		unsigned int indiceMotGlobal = 0;
		string texte[100];
		string Mot = "";
		while (ligne[ind] =! '\0') // On vérifie que c'est différent du charactère fin de chaine
		{
			if (ligne[ind] == ' ')
			{
				
				finMot = ind - 1;
				tailleMot = finMot - debutMot;
				
				while (indMot < tailleMot) {
					Mot.append(indMot, ligne[debutMot + ind]);

				}
				texte[indiceMotGlobal] = Mot;

				debutMot = ind + 1;
			}
		}
	}
	else 
	{
		cout << "Erreur lecture fichier";
	}
}
