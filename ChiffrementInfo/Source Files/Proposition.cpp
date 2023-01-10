void Proposition_initiale(float freq[], float proposition[])
{
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	float freqDecroissant[25];
	char temp;
	int min;

	for (int i; i == 24; i++)
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