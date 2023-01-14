#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>// à suppprimer
#include <math.h>
#include <string>
#include <vector>
using namespace std;


float Score(const char texte[], unsigned int tpTexte, float bigramme[26][26])
{
	unsigned int indPremierLettre;
	unsigned int indDeuxiemeLettre;
	float score = 0;
	for (unsigned int indChar = 1; indChar < tpTexte; indChar++)
	{
		indDeuxiemeLettre = LettreToNumber(texte[indChar]);
		indPremierLettre = LettreToNumber(texte[indChar - 1]);
		if (indPremierLettre != -1 && indDeuxiemeLettre != -1) {
			//cout << "score : " << score << " bigramme : " << bigramme[indPremierLettre][indDeuxiemeLettre] <<endl;;
			score = score + bigramme[indPremierLettre][indDeuxiemeLettre];
		}
		
		//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilité on préfère appliquer directement le log
		//Donc dans bigramme on déja appliquer le log
		//il ne reste plus qu'à faire l'addition
	}


	return score/tpTexte; // on normalise par le nombre de charactères
}



float Score_Mots(const char texte[], string nom_fichier, const unsigned int taille_texte)
{
	
	int mots_corrects = 0; 
	int nb_mots = 0;
	string texteString = texte;

	string delimiter = " ";
	
	ifstream fichier(nom_fichier.c_str());
	if(fichier)
	{	
		//On sépare le texte en mot indivuel
		string motRecherche = texteString.substr(0, texteString.find(delimiter));
		int pos;
		//on vérifie qu'on est pas à la fin du string
		while ((pos = texteString.find(delimiter)) != std::string::npos) 
		{
			//Pour chaque nouveau on recommance la recherche du début dans le fichier dico
			fichier.seekg(0, ios::beg);
			motRecherche = texteString.substr(0, pos);
			string listeMots;
			while(getline(fichier,listeMots ))
			{		
				//On vérifie si il y a une correspondance
				if (listeMots.find(motRecherche) != std::string::npos)
				{
					cout << " les mots : " << motRecherche<<endl;
					mots_corrects = mots_corrects + 1;
					break;
				}
			}
			nb_mots++;
			//On efface les mots au fur et à mesure
			texteString.erase(0, pos + delimiter.length());
		}	
	}
	else {
		cout << "Erreur ";
	}

	cout <<" mots_corrects : " << mots_corrects << endl;
	cout << " nb_mots : " << nb_mots << endl;
	return (float)mots_corrects / (float)nb_mots;
}