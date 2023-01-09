#include "WRfichier.h";
#include <iostream>;
#include <fstream>
using namespace std;



void LectureParMots(string nomfichier) {
	ifstream fichier(nomfichier.c_str());
	string ligne; //ligne actuel
	if (fichier) {
		getline(fichier, ligne);
		unsigned int ind = 0;
		unsigned int debutMot = ind;
		unsigned int finMot = 0;
		unsigned int tailleMot = 0;
		unsigned int indMot = 0;
		string Mot = "";
		while (ligne[ind] =! '\0') // On vérifie que c'est différent du charactère fin de chaine
		{
			
			if (ligne[ind] == ' ') {
				
				finMot = ind - 1;
				tailleMot = finMot - debutMot;
				
				while (indMot < tailleMot) {
					Mot.append(indMot, ligne[debutMot + ind]);

				}
				text[indiceMotGlobal] = Mot;

				debutMot = ind + 1;

				
			}
			

		}
	}
	else {
		cout << "Erreur lecture fichier";
	}



}
