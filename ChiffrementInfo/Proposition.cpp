#include "decrypter.h"
#include <iostream>
using namespace std;

void Trier_frequence(dicoFreq tab[])
{
	//Trier les deux tableaux dans l'ordre croissant en fonction de la fréquence
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

void Proposition_initiale(const float freq[], char proposition[])
{
	dicoFreq freqBase[26];
	dicoFreq freqMess[26];
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	dicoFreq x_temp;
	int j;

	//Associer à chaque lettre de l'alphabet sa fréquence en utiliser le type composé dicoFreq (en faire une fonction)
	for (int i = 0; i < 26; i++)
	{
		freqBase[i].caractere = alphabet[i];
		freqBase[i].frequence = freq[i];
		freqMess[i].caractere = alphabet[i];
		freqMess[i].frequence = proposition[i];
	}
	Trier_frequence(freqBase);
	Trier_frequence(freqMess);
}

void FreqApparitions(char texte[], float freq[])
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