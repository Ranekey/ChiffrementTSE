#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// � suppprimer
#include <math.h>
#include <string>
#include <vector>
using namespace std;

float ScoreBigramm(const char texte[], const unsigned int tpTexte, const float bigramme[42][42])
{
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	float score = 0;
	for (unsigned int indChar = 1; indChar < tpTexte; indChar++)
	{

		indDeuxiemeLettre = LettreToNumberComplet(texte[indChar]);
		indPremierLettre = LettreToNumberComplet(texte[indChar - 1]);
		if (indPremierLettre != -1 && indDeuxiemeLettre != -1) {
			//cout << "score : " << score << " bigramme : " << bigramme[indPremierLettre][indDeuxiemeLettre] <<endl;;
			score = score + bigramme[indPremierLettre][indDeuxiemeLettre];
		}

		//Pour calculer le score il faut multiplier tout les probabilt� puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilit� on pr�f�re appliquer directement le log
		//Donc dans bigramme on d�ja appliquer le log
		//il ne reste plus qu'� faire l'addition
	}


	return score / tpTexte; // on normalise par le nombre de charact�res
}



float Score_Mots(const char texte[], const string dico)
{
	
	int mots_corrects = 0; 
	int nb_mots = 0;
	string texteString = texte;

	string delimiter = " ";
	
	ifstream fichier(dico.c_str());
	if(fichier)
	{	
		//On s�pare le texte en mot indivuel
		string motRecherche = texteString.substr(0, texteString.find(delimiter));
		int pos;
		//on v�rifie qu'on est pas � la fin du string
		while ((pos = texteString.find(delimiter)) != std::string::npos) 
		{
			//Pour chaque nouveau on recommance la recherche du d�but dans le fichier dico
			fichier.seekg(0, ios::beg);
			motRecherche = texteString.substr(0, pos);
			string listeMots;
			while(getline(fichier,listeMots ))
			{		
				//On v�rifie si il y a une correspondance
				if (listeMots.find(motRecherche) != std::string::npos)
				{
					mots_corrects = mots_corrects + 1;
					break;
				}
			}
			fichier.clear(); 
			nb_mots++;
			//On efface les mots au fur et � mesure
			texteString.erase(0, pos + delimiter.length());
		}	
	}
	else {
		cout << "Erreur ";
	}
	cout << mots_corrects << endl;
	cout << nb_mots << endl;
	return (float)mots_corrects / (float)nb_mots;
}