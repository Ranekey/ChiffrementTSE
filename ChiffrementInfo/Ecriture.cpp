#include "WRfichier.h";
#include <iostream>;
#include <fstream>

void Ecriture(string nomfichier, string text)
{
	/// <summary>
	/// Permet d'�crire dans un fichier donn�, si le fichier ,n'existe pas on le cr�er,
	/// sinon on rajoute le text � la fin du fichier
	/// </summary>
	/// <param name="nomfichier"></param>
	/// <param name="text"></param>
	ofstream Fichier(nomfichier.c_str(), ios::app);
	if (Fichier)
	{
		Fichier << text << endl;
	}
}