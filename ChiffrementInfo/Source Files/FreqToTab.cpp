#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void FreqToTab(const string nomFichier, float tabFreq[])
{
	ifstream fichier(nomFichier.c_str());

	if (fichier)
	{
		//La lecture est bonne
		string ligne;
		int i = 0;
		do
		{
			string mot;
			fichier >> mot;
			fichier >> tabFreq[i];
			i++;
		} while (getline(fichier, ligne));
	}
	else
	{
		//Erreur de lecture
		cout << "Impossible de lire le fichier" << endl;
	}
}