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
void FreqApparitions(const char texte[], float freq[]);

/*
R�le : Associer � chaque lettre de l'alphabet sa fr�quence en utilisant le type compos� dicoFreq
Entr�e : 1 tableau de caract�re �tant l'alphabet � associer, 1 tableau de r�els �tant les fr�quences d'apparitions des lettres dans l'ordre alphab�tique
Entr�e / Sortie : 1 tableau de type compos� dicoFreq o� les lettres et les fr�quences sont associ�s par pairs
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
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], char proposition[]);

/*
R: melanger les caractere d'une chaine de caracteres
E: 1 tableau de caracteres avec caracteres non melang�s
E/S: 1 tableau de caracteres avec lettres melangers
S: Vide
*/
void Proposition(int tailleProposition, char proposition[]);

/*
R�le : Assigne un score de plausibilit� � un tableau de charact�re
Entr�e : Un tableau de caract�res �tant le texte, un entier correspondant � la taille r�elle du texte
Sortie : un r�el repr�sentant le score du texte
*/
float Score(const char texte[], unsigned int tpTexte, float bigramme[26][26]);
float ScoreBigramm(const string texte, unsigned int tpTexte, float bigramme[42][42]);

float ScoreQuadgramm(const char texte[], unsigned int tpTexte, float quadgramm[42][42][42][42]);

/*
R�le: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entr�e : un charact�re (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
*/
int LettreToNumber(char lettre);
int LettreToNumberComplet(char lettre);
/*
R�le: Application d'une proposition � un texte donn�
Entr�e : un tableau de caract�res (le texte � traduire), la taille pratique du texte (un entier) une proposition (tableaux de 26 caract�res)
Entr�e / Sortie: Un tableau de caract�res �tant le nouveau texte sur lequel on a appliqu� la proposition
Sortie : vide
*/
void ApplicationProposition( unsigned int tpTexte, char proposition[], char texte_trad[]);

/*
R�le: renvoie si le message d�crypter doit �tre garder ou non gr�ce a une loi de probabilit�
Entr�e : un r�el (le score actuel entrain d'�tre analyser), un r�el (le score courant), un r�el (la temp�rature utilis�e pour le calcul)
Sortie : un bool�ean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(float score_actuel, float score_courant, float temperature);

/*
R�le : Evaluer la plausibilit� d'un texte avec une liste de mots
Sortie : un r�el (le meilleur score obtenu)
*/
//float Recuit_boucle(char proposition_actuelle[], char best_proposition[], char proposition_courante[], float bigramme[42][42], char texte_crypt_actuelle[], unsigned int taille_texte, const char liste_mots[][50], const unsigned int taille_liste, char texte_crypt_courant[], float best_score);
float Recuit_boucle(char proposition_actuelle[27], char best_proposition[27], char proposition_courante[27], float bigramme[42][42], char texte_crypt_actuelle[], unsigned int taille_texte, string listeMots, unsigned int taille_liste, char texte_crypt_courant[], float best_score);
/*
R�le : Evaluer le score d'un texte en fonction du nombre de mots pr�sents parmi une liste de mots (ici en Francais)
Entr�e: un tableau de caract�res (le texte � �valuer), un tableau de tableau de caract�res (la liste des mots), un entier (le nombre de mots dans la liste)
Sortie : un r�el (le score du texte)
*/
float Score_Mots(const char texte[], string listeMots, const unsigned int taille_liste);


/*
R�le : utiliser l'algorithme de m�tropolis pour savoir si une proposition est conserver ou non
Entr�e : le score de proposition actuelle et proposition courant, la taille du texte
Sortie: un bool , Vrai si la proposition est accepter, faux sinon
*/
bool Metropolis(float score_courant, float score_actuelle, unsigned int taille);

/*
R�le : Evaluer la plausibilit� d'un texte avec une comparaison par bigrammes
Sortie : un r�el (le meilleur score obtenu)
*/
float MetropolisBoucle(char texte_crypt_actuelle[], char texte_crypt_courant[], unsigned int taille_texte, char proposition_courante[], char proposition_actuelle[], char best_proposition[], float bigrammes[42][42]);

