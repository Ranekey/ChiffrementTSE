#include "decrypter.h"

void Proposition_initiale(float freq[], float proposition[])
{
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freqDecroissant[25];
	char temp;
	int min;

	for (int i; i = 24; i++)
	{
		min = i;
		if (freq[i] < freq[i + 1])
		{
			temp = alphabet[i];
			alphabet[i] = alphabet[i + 1];
			alphabet[i + 1] = temp;
		};
	};
};

void FreqApparitions(char texte[],int taille_texte, char freq[])
{
	int occurences[26];
	for (int i; i < taille_texte;i++)
	{
		occurences[LettreToNumber(texte[i])]++;
	};
};