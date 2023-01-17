#include <string>
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
R�le : Retourner la fr�quence d'apparation des lettres dans un texte
Entr�e : Un tableau de caract�res �tant le texte
Entr�e / Sortie : Un tableau de la fr�quence d'apparation de chaque lettres en pourcentage (de 0 � 1) (dans l'ordre A � Z)
Sortie : vide
*/
void FreqApparitions(const char texte[], unsigned int taille_texte, float freq[]);

/*
R�le : Associer � chaque lettre de l'alphabet sa fr�quence d'apparition en utilisant le type compos� dicoFreq
Entr�e : un tableau de caract�res �tant l'alphabet � associer, un tableau de r�els �tant les fr�quences d'apparitions des lettres dans l'ordre alphab�tique
Entr�e / Sortie : un tableau de type compos� dicoFreq o� les lettres et les fr�quences sont associ�es par pairs
Sortie : vide
*/
void AssociationFreq(const char alphabet[], const float freqApparitions[], dicoFreq associationLettresFreq[]);

/*
R�le : Trier dans l'ordre des fr�quences d'apparitions (de 0 � 1) un tableau de type compos� dicoFreq
Entr�e : vide
Entr�e / Sortie : un tableau de type compos� dicoFreq trier dans l'ordre d�croissant des fr�quences d'apparitions
Sortie : vide
*/
void Trier_frequence(dicoFreq tab[]);

/*
R�le : Etablir une proposition de cl� initial � partir de la fr�quence d'appartion des lettres dans un texte
Entr�e : un tableau de caract�re �tant l'alphabet qui va �tre utilis�, un tableau de r�els �tant la fr�quence d'apparitions des lettres (entre 0 et 1)
dans l'ordre de cet alphabet, un tableau de caract�re �tant le texte � d�crypter
Entr�e / Sortie : Un tableau �tant la proposition de cl� de l'ordre des 26 lettres
Sortie : vide
*/
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], unsigned int taille_texte, char proposition[]);

/*
R: Inverser 2 caract�res d'une chaine de caract�res
E: la taille de la chaine de caract�res
E/S: un tableau de caracteres avec dont la position de deux caract�res va �tre invers�e
S: Vide
*/
void Proposition(const int tailleProposition, char proposition[]);

/*
R�le : Assigne un score de plausibilit� � un tableau de charact�re en utilisant la fr�quence d'apparition de bigrammes
Entr�e : Un tableau de caract�res �tant le texte, un entier correspondant � la taille r�elle du texte, la liste des bigrammes utilis�s avec leur score associ�s pour calculer le score total
Sortie : un r�el repr�sentant le score du texte (g�n�ralement n�gatif car on utilise la fonction logarithme) (un bon score est de -3, un mauvais score de -6)
*/
float ScoreBigramm(const char texte[], const unsigned int tpTexte, const float bigramme[42][42]);

/*
R�le: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entr�e : un caract�re (entre simple cote)
Sortie : un entier entre 0 et 25 (ou plus avec les accents) ou -1 en cas d'erreur
*/
int LettreToNumberComplet(const char lettre);

/*
R�le: Application d'une proposition � un texte donn�
Entr�e : un tableau de caract�res (�tant le texte initial), la taille pratique du texte (un entier) une proposition (tableaux de 26 caract�res)
Entr�e / Sortie: un tableau de caract�res (le texte � traduire qui est traduit)
Sortie : vide
*/
void ApplicationProposition(const char texte_initial[], const unsigned int tpTexte, const char proposition[], char texte_traduit[]);

/*
R�le: renvoie si le message d�crypter doit �tre garder ou non gr�ce a une loi de probabilit�
Entr�e : un r�el (le score actuelqui est meilleur que le score courant), un r�el (le score courant), un r�el (la temp�rature utilis�e pour le calcul)
Sortie : un bool�ean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(const float score_actuel, const float score_courant, const float temperature);

/*
R�le : Evaluer la plausibilit� d'un texte avec une liste de mots en comptant le nombre de mots corrects
Entr�e : un tableau de caract�res (le texte � d�crypter), un entier (la taille du texte), un string (le chemin menant vers le fichier de la liste de mots), un tableau de tableau de r�els (�tant les bigrammes utilis�s pour calculer le score)
Entr�e / Sortie : un tableau de caract�res (le texte courant), un tableau de caract�re (la cl� de la meilleure proposition)
Sortie : un r�el (le meilleur score obtenu)
*/
float Recuit_boucle(const char texte_crypt[], const int* tabOccurenceMotLettre, const unsigned int taille_texte, const string dico, const float bigrammes[42][42], char texte_crypt_courant[], char best_proposition[27]);

/*
R�le : Evaluer le score d'un texte en fonction du nombre de mots pr�sents parmi une liste de mots (ici en Francais)
Entr�e: un tableau de caract�res (le texte � �valuer), un string (le chemin vers le fichier contenant la liste de mots)
Sortie : un r�el (le score du texte)
*/

float Score_Mots(const char texte[], unsigned int tailleTexte, const int* tabOccurenceLettre, const string dico);

/*
R�le : utiliser l'algorithme de m�tropolis pour savoir si une proposition est conserver ou non
Entr�e : deux r�els (le score de proposition actuelle et proposition courante), un entier (la taille du texte)
Sortie: un bool�en , Vrai si la proposition est accepter, faux sinon
*/
bool Metropolis(const float score_actuel, const float score_courant, const unsigned int taille);

/*
R�le : �valuer la plausibilit� d'un texte avec une comparaison par bigrammes
Entr�e : un tableau de caract�res (le texte initial), un entier (la taille du texte), un tableau de tableau de r�els (la fr�quence des bigrammes)
Entr�e / Sortie : un tableau de caract�re (le texte courant), 3 tableaux de caract�res (les propositions de cl� (actuelle, courante et best))
Sortie : un r�el (le meilleur score obtenu)
*/
float MetropolisBoucle(const char texte_crypt[], const unsigned int taille_texte, const float bigrammes[42][42], char texte_crypt_courant[], char proposition_courante[], char proposition_actuelle[], char best_proposition[]);