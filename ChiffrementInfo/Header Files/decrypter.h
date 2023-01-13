#include<string>
using namespace std;

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
void FreqApparitions(const char texte[], float freq[]);

/*
R : Associer à chaque lettre de l'alphabet sa fréquence en utilisant le type composé dicoFreq
E : 1 tableau de caractère étant l'alphabet à associer, 1 tableau de réels étant les fréquences d'apparitions des lettres dans l'ordre alphabétique
E / S : 1 tableau de type composé dicoFreq où les lettres et les fréquences sont associés par pairs
S : vide
*/
void AssociationFreq(const char alphabet[], const float freqApparitions[], dicoFreq associationLettresFreq[]);

/*
R : Trier dans l'ordre des fréquences d'apparitions (de 0 à 1) un tableau de type composé dicoFreq
E : vide
E / S : un tableau de type composé dicoFreq trier dans l'ordre décroissant des fréquences d'apparitions
S : vide
*/
void Trier_frequence(dicoFreq tab[]);

/*R : Etablir une proposition de clé initial à partir de la fréquence d'appartion des lettres dans un texte
E : un tableau de caractère étant l'alphabet qui va être utilisé, un tableau de réels étant la fréquence d'apparitions des lettres (entre 0 et 1)
dans l'ordre de cet alphabet, un tableau de caractère étant le texte à décrypter
E / S : Un tableau étant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], char proposition[]);

/*
R : Convertir les frequences d'apparitions de caractères d'un fichier txt à un tableau de réels
E : la localisation relative du fichier contenant les fréquences d'apparitions de chaque lettres
E / S : un tableau de réels avec les fréquences d'apparitions de chaque lettres dans l'ordre alphabétique
S : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
Rôle : Assigne un score de plausibilité à un tableau de charactère
Entré : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte
Sortie : un réel représentant le score du texte
*/
float Score(const char texte[], unsigned int tpTexte, float bigramme[26][26]);

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
de recuit simulé (qui lui même se base sur un algorithme de métropolis)
Entrée : Une proposition donc une chaine de 26 charctère, le score actuelle du texte, (le score initiale basé de
l'analyse fréquentielle, définir commme une variable global ou constante )
Sortie : un booléean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(float scoreActuelle, const char noouvelleProposition[], char liste_mots[]);

float Score_Mots(const char texte[], char liste_mots[]);

bool Metropolis(float score_courant, float score_actuelle, unsigned int taille);

/*

*/
float MetropolisBoucle(char best_proposition[26], char proposition_actuelle[26], char proposition_courante[26], char texte[]);

