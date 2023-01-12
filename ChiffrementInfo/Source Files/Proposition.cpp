#include "decrypter.h"
#include <iostream>
using namespace std;

void Trier_frequence(dicoFreq tab[])
{
	//Trier le tableau dans l'ordre croissant en fonction de la fr�quence
	for (int i = 0; i < 26; i++)
	{
		dicoFreq x_temp = tab[i];
		int j = i;

		while (j > 0 && tab[j - 1].frequence > x_temp.frequence)
		{
			tab[j] = tab[j - 1];
			j = j - 1;
		}

		tab[j] = x_temp;
	}
}

void AssociationFreq(const char alphabet[], const float freqApparitions[], dicoFreq associationLettresFreq[])
{
	for (int i = 0; alphabet[i] != '\0'; i++)
	{
		associationLettresFreq[i].caractere = alphabet[i];
		associationLettresFreq[i].frequence = freqApparitions[i];
	}
}

void FreqApparitions(const char texte[], float freq[])
{
	int occurences[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int indLettre;
	char lettre;
	int nbLettres = 0;

	for (int i = 0; texte[i] != '\0'; i++)
	{
		lettre = texte[i];
		indLettre = LettreToNumber(lettre);
		if (indLettre != -1)
		{
			occurences[indLettre] = occurences[indLettre] + 1;
			nbLettres = nbLettres + 1;
		}
	}
	if (nbLettres != 0)
	{
		for (int i = 0; i < 26; i++)
		{
			freq[i] = (float)occurences[i] / (float)nbLettres;
		}
	}
}

void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], char proposition[])
{
	float freqMess[26];
	dicoFreq associationMess[26];
	dicoFreq associationAlphabet[26];
	int indiceProp;

	FreqApparitions(texte, freqMess);

	AssociationFreq(alphabet, freqMess, associationMess);
	AssociationFreq(alphabet, freqAlphabet, associationAlphabet);

	Trier_frequence(associationMess);
	Trier_frequence(associationAlphabet);

	for (int i = 0; i < 26; i++)
	{
		indiceProp = LettreToNumber(associationAlphabet[i].caractere);
		proposition[indiceProp] = associationMess[i].caractere;
	}
}