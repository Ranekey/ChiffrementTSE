#include<string>
using namespace std;

/*
Type compos� utilis� pour associer � chaque caract�re une fr�quence d'apparation (en pourcentage de 0 � 1)
*/
struct dicoFreq
{
	char caractere;
	float frequence;
};

/*
R : Retourner la fr�quence d'apparation des lettres en majuscules uniquement dans un texte
E : Un tableau de caract�res �tant le texte
E / S : Un tableau de la fr�quence d'apparation de chaque lettres en pourcentage (de 0 � 1) (dans l'ordre A � Z)
S : vide
*/
void FreqApparitions(const char texte[], float freq[]);

/*
R : Associer � chaque lettre de l'alphabet sa fr�quence en utilisant le type compos� dicoFreq
E : 1 tableau de caract�re �tant l'alphabet � associer, 1 tableau de r�els �tant les fr�quences d'apparitions des lettres dans l'ordre alphab�tique
E / S : 1 tableau de type compos� dicoFreq o� les lettres et les fr�quences sont associ�s par pairs
S : vide
*/
void AssociationFreq(const char alphabet[], const float freqApparitions[], dicoFreq associationLettresFreq[]);

/*
R : Trier dans l'ordre des fr�quences d'apparitions (de 0 � 1) un tableau de type compos� dicoFreq
E : vide
E / S : un tableau de type compos� dicoFreq trier dans l'ordre d�croissant des fr�quences d'apparitions
S : vide
*/
void Trier_frequence(dicoFreq tab[]);

/*R : Etablir une proposition de cl� initial � partir de la fr�quence d'appartion des lettres dans un texte
E : un tableau de caract�re �tant l'alphabet qui va �tre utilis�, un tableau de r�els �tant la fr�quence d'apparitions des lettres (entre 0 et 1)
dans l'ordre de cet alphabet, un tableau de caract�re �tant le texte � d�crypter
E / S : Un tableau �tant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], char proposition[]);

/*
R : Convertir les frequences d'apparitions de caract�res d'un fichier txt � un tableau de r�els
E : la localisation relative du fichier contenant les fr�quences d'apparitions de chaque lettres
E / S : un tableau de r�els avec les fr�quences d'apparitions de chaque lettres dans l'ordre alphab�tique
S : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
R�le : Assigne un score de plausibilit� � un tableau de charact�re
Entr� : Un tableau de caract�res �tant le texte, un entier correspondant � la taille r�elle du texte
Sortie : un r�el repr�sentant le score du texte
*/
float Score(const char texte[], unsigned int tpTexte, float bigramme[26][26]);

/*
R�le: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entr�e : un charact�re (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
*/
int LettreToNumber(char lettre);

/*
R�le: Application d'une proposition � un texte donn�s
Entr�e : une proposition( tableaux de 26 charct�re ) , un texte ( tableau de charact�re composer de lettre seulement
utiliser dans la proposition), taille pratique du texte (un entier)
Sortie: Un nouveau texte dont on a appliquer la proposition
*/
void ApplicationProposition(const char proposition[], char texte[], unsigned int tpTexte);

/*
R�le: c'est la fonction qui permet de d�crypter le message, cela se base sur un algorithme
de recuit simul� (qui lui m�me se base sur un algorithme de m�tropolis)
Entr�e : Une proposition donc une chaine de 26 charct�re, le score actuelle du texte, (le score initiale bas� de
l'analyse fr�quentielle, d�finir commme une variable global ou constante )
Sortie : un bool�ean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(float scoreActuelle, const char noouvelleProposition[], char liste_mots[]);

float Score_Mots(const char texte[], char liste_mots[]);

bool Metropolis(float score_courant, float score_actuelle, unsigned int taille);

/*

*/
float MetropolisBoucle(char best_proposition[26], char proposition_actuelle[26], char proposition_courante[26], char texte[]);

