#include "WRfichier.h";
#include <iostream>;
#include <fstream>

void Ecriture(string nomfichier, string text)
{
	/// <summary>
	/// Permet d'écrire dans un fichier donné, si le fichier ,n'existe pas on le créer,
	/// sinon on rajoute le text à la fin du fichier
	/// </summary>
	/// <param name="nomfichier"></param>
	/// <param name="text"></param>
	ofstream Fichier(nomfichier.c_str(), ios::app);
	if (Fichier)
	{
		Fichier << text << endl;
	}
}