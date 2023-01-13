#include<random>
#include<math.h>
#include <decrypter.h>

bool Recuit(float scoreActuelle, const char noouvelleProposition[], char liste_mots[])
{
	bool b;
	float temperature = 0.05;
	float rho = 0.99;
	float score_mot;
	char texte_trad[1000];
	float x;
	float acceptProp;

	ApplicationProposition(noouvelleProposition, texte_trad, sizeof(texte_trad));
	score_mot = Score_Mots(texte_trad, liste_mots);
	x = rand();
	acceptProp = exp(1);
}