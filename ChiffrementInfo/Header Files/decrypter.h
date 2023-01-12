/*
Type composé utilisé pour associer à chaque caractère une fréquence d'apparation (en pourcentage de 0 à 1)
*/
struct dicoFreq
{
	char caractere;
	float frequence;
};

/*
R : Retourner la fréquence d'apparation des lettres en majuscules uniquement dans un texte
E : Un tableau de caractères étant le texte
E / S : Un tableau de la fréquence d'apparation de chaque lettres en pourcentage (de 0 à 1) (dans l'ordre A à Z)
S : vide
*/
void FreqApparitions(char texte[], float freq[]);

/*
R : Trier dans l'ordre des fréquences d'apparitions (de 0 à 1) un tableau de type composé dicoFreq
E : vide
E / S : un tableau de type composé dicoFreq trier dans l'ordre décroissant des fréquences d'apparitions
S : vide
*/
void Trier_frequence(dicoFreq tab[]);

/*R : Etablir une proposition initial à partir d'un texte donné en fonction de la fréquence d'appartion des lettres
E : Un tableau de la fréquence d'apparition de chacune des 26 lettres (dans l'ordre A à Z)
E / S : Un tableau étant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(const float freq[], char proposition[]);

/*
Rôle : Assigne un score de plausibilité à un tableau de charactère
Entré : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte
Sortie : un réel représentant le score du texte
*/
float Score(char texte[], unsigned int tpTexte, float bigramme[26][26]);

/*
Rôle: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entrée : un charactère (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
*/
int LettreToNumber(char lettre);

/*
Rôle: Application d'une proposition à un texte donnés
Entrée : une proposition( tableaux de 26 charctère ) , un texte ( tableau de charactère composer de lettre seulement
utiliser dans la proposition), taille pratique du texte (un entier)
Sortie: Un nouveau texte dont on a appliquer la proposition
*/
void ApplicationProposition(const char proposition[], char texte[], unsigned int tpTexte);

/*
Rôle: c'est la fonction qui permet de décrypter le message, cela se base sur un algorithme
de reconduit(qui lui même se base sur un algorithme de métropolis)
Entrée : Une proposition donc une chaine de 26 charctère, le score actuelle du texte, (le score initiale basé de
l'analyse fréquentielle, définir commme une variable global ou constante )
Sortie : un booléean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Reconduit(float scoreActuelle, const char noouvelleProposition[]);

bool Metropolis(float scoreActuelle, const char noouvelleProposition[]);