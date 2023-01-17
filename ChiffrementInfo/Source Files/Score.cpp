#include "decrypter.h"
#include "WRfichier.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;


int* OccurenceMotLettre(const string Dico) {
	int* tabOccurenceMotLettre = new int[26];
	ifstream Fichier(Dico.c_str());
	if (Fichier) {
		string ligne;
		int indLettre;
		//Initialisation du tableau
		for (int i = 0; i < 26; i++) {
			tabOccurenceMotLettre[i] = 0;
		}
		while (getline(Fichier, ligne)) {
			indLettre = LettreToNumberComplet(ligne[0]);
			tabOccurenceMotLettre[indLettre]++;
		}
	}
	else
	{
		cout << "Dico pas ouvert";
	}
	return tabOccurenceMotLettre;
}
unsigned int StartPosCursor(char lettre, const int* tabOccurenceMotLettre) {
	unsigned int indLettre = LettreToNumberComplet(lettre);
	unsigned int somme = 0;
	if (indLettre > 0) // Si c'est A on commence au début
	{
		for (int i = 0; i < indLettre - 1; i++) {
			somme = somme + tabOccurenceMotLettre[i];

		}
	}
	

	return somme;
}

unsigned int Interval(char lettre, const int* tabOccurenceMotLettre) 
{
	unsigned int debut = StartPosCursor(lettre, tabOccurenceMotLettre);
	unsigned int fin;
	if (lettre == 'Z') {
		fin = debut+tabOccurenceMotLettre[25];
	}
	else
	{
		fin = StartPosCursor(char(int(lettre)+1), tabOccurenceMotLettre);
	}

	
	return fin - debut; // intervalle dans lequelle le curseur peut se déplacer;
}

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
			score = score + bigramme[indPremierLettre][indDeuxiemeLettre];
		}

		//Pour calculer le score il faut multiplier tout les probabilté puis appliquer le log
		//Or on sait que log(A*B) = log(A) + log(B)
		//Vu que l'on va avoir des petites probabilité on préfère appliquer directement le log
		//Donc dans bigramme on déja appliquer le log
		//il ne reste plus qu'à faire l'addition
	}


	return score / tpTexte; // on normalise par le nombre de charactères
}



float Score_Mots(const char texte[], unsigned int tailleTexte,const int* tabOccurenceLettre,const string dico)
{
	
	int mots_corrects = 0; 
	int nb_mots = 0;
	string texteString;
	for (int i = 0; i < tailleTexte; i++) {
		texteString.push_back(texte[i]);
	}

	string delimiter = " ";
	//cout << texteString;
	
	ifstream fichier(dico.c_str());
	if(fichier)
	{	
		//On sépare le texte en mot indivuel
		string motRecherche = texteString.substr(0, texteString.find(delimiter));
		int pos;
		//on vérifie qu'on est pas à la fin du string
		while ((pos = texteString.find(delimiter)) != std::string::npos && motRecherche != "\0")
		{
			//Pour chaque nouveau on recommance la recherche du début dans le fichier dico
			fichier.clear();
			motRecherche = texteString.substr(0, pos);
			unsigned int posCursor = StartPosCursor(motRecherche[0], tabOccurenceLettre);
			unsigned int interval = Interval(motRecherche[0], tabOccurenceLettre);
			unsigned int posInterval = 0;
			string listeMots;
			int debut, fin, milieu;
			debut = posCursor;
			fin = posCursor + interval;
			while (debut <= fin) {
				milieu = (debut + fin) / 2;
				fichier.seekg(milieu, ios::beg);

				//cout << "posInterval: " << posInterval << " interval : " << interval<<" lettre : " << motRecherche[0] << endl;
				getline(fichier, listeMots);
				
				if (listeMots.compare(motRecherche) == 0) 
				{
					mots_corrects++;
					break;
				}
				else
				{
					
					bool estInclus = false;
					int taille_min = min(listeMots.length(), motRecherche.length());
					cout << "listeMots :" << listeMots << " motRecherche : " << motRecherche << endl;
					cout << "debut :" << debut << " fin : " << fin <<" milieu :" << milieu <<" taille_min : " << taille_min << endl;
					for (int i = 0; i<taille_min; i++)
					{
						if (int(motRecherche[i]) > int(listeMots[i]))
						{
							debut = milieu +1;
							break;
						}
						else
						{
							fin = milieu - 1;
							break;
						}
					}

				}
			}
			fichier.clear(); 
			fichier.seekg(0, ios::beg);
			nb_mots++;
			//On efface les mots au fur et à mesure
			texteString.erase(0, pos + delimiter.length());
		}	
	}
	else {
		cout << "Erreur ";
	}
	
	return (float)mots_corrects / (float)nb_mots;
}