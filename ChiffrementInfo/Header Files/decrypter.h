#include <string>
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
Rôle : Retourner la fréquence d'apparation des lettres dans un texte
Entrée : Un tableau de caractères étant le texte
Entrée / Sortie : Un tableau de la fréquence d'apparation de chaque lettres en pourcentage (de 0 à 1) (dans l'ordre A à Z)
Sortie : vide
*/
void FreqApparitions(const char texte[], unsigned int taille_texte, float freq[]);

/*
Rôle : Associer à chaque lettre de l'alphabet sa fréquence d'apparition en utilisant le type composé dicoFreq
Entrée : un tableau de caractères étant l'alphabet à associer, un tableau de réels étant les fréquences d'apparitions des lettres dans l'ordre alphabétique
Entrée / Sortie : un tableau de type composé dicoFreq où les lettres et les fréquences sont associées par pairs
Sortie : vide
*/
void AssociationFreq(const char alphabet[], const float freqApparitions[], dicoFreq associationLettresFreq[]);

/*
Rôle : Trier dans l'ordre des fréquences d'apparitions (de 0 à 1) un tableau de type composé dicoFreq
Entrée : vide
Entrée / Sortie : un tableau de type composé dicoFreq trier dans l'ordre décroissant des fréquences d'apparitions
Sortie : vide
*/
void Trier_frequence(dicoFreq tab[]);

/*
Rôle : Etablir une proposition de clé initial à partir de la fréquence d'appartion des lettres dans un texte
Entrée : un tableau de caractère étant l'alphabet qui va être utilisé, un tableau de réels étant la fréquence d'apparitions des lettres (entre 0 et 1)
dans l'ordre de cet alphabet, un tableau de caractère étant le texte à décrypter
Entrée / Sortie : Un tableau étant la proposition de clé de l'ordre des 26 lettres
Sortie : vide
*/
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], unsigned int taille_texte, char proposition[]);

/*
R: Inverser 2 caractères d'une chaine de caractères
E: la taille de la chaine de caractères
E/S: un tableau de caracteres avec dont la position de deux caractères va être inversée
S: Vide
*/
void Proposition(const int tailleProposition, char proposition[]);

/*
Rôle : Assigne un score de plausibilité à un tableau de charactère en utilisant la fréquence d'apparition de bigrammes
Entrée : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte, la liste des bigrammes utilisés avec leur score associés pour calculer le score total
Sortie : un réel représentant le score du texte (généralement négatif car on utilise la fonction logarithme) (un bon score est de -3, un mauvais score de -6)
*/
float ScoreBigramm(const char texte[], const unsigned int tpTexte, const float bigramme[42][42]);

/*
Rôle: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entrée : un caractère (entre simple cote)
Sortie : un entier entre 0 et 25 (ou plus avec les accents) ou -1 en cas d'erreur
*/
int LettreToNumberComplet(const char lettre);

/*
Rôle: Application d'une proposition à un texte donné
Entrée : un tableau de caractères (étant le texte initial), la taille pratique du texte (un entier) une proposition (tableaux de 26 caractères)
Entrée / Sortie: un tableau de caractères (le texte à traduire qui est traduit)
Sortie : vide
*/
void ApplicationProposition(const char texte_initial[], const unsigned int tpTexte, const char proposition[], char texte_traduit[]);

/*
Rôle: renvoie si le message décrypter doit être garder ou non grâce a une loi de probabilité
Entrée : un réel (le score actuelqui est meilleur que le score courant), un réel (le score courant), un réel (la température utilisée pour le calcul)
Sortie : un booléean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(const float score_actuel, const float score_courant, const float temperature);

/*
Rôle : Evaluer la plausibilité d'un texte avec une liste de mots en comptant le nombre de mots corrects
Entrée : un tableau de caractères (le texte à décrypter), un entier (la taille du texte), un string (le chemin menant vers le fichier de la liste de mots), un tableau de tableau de réels (étant les bigrammes utilisés pour calculer le score)
Entrée / Sortie : un tableau de caractères (le texte courant), un tableau de caractère (la clé de la meilleure proposition)
Sortie : un réel (le meilleur score obtenu)
*/
float Recuit_boucle(const char texte_crypt[], const int* tabOccurenceMotLettre, const unsigned int taille_texte, const string dico, const float bigrammes[42][42], char texte_crypt_courant[], char best_proposition[27]);

/*
Rôle : Evaluer le score d'un texte en fonction du nombre de mots présents parmi une liste de mots (ici en Francais)
Entrée: un tableau de caractères (le texte à évaluer), un string (le chemin vers le fichier contenant la liste de mots)
Sortie : un réel (le score du texte)
*/

float Score_Mots(const char texte[], unsigned int tailleTexte, const int* tabOccurenceLettre, const string dico);

/*
Rôle : utiliser l'algorithme de métropolis pour savoir si une proposition est conserver ou non
Entrée : deux réels (le score de proposition actuelle et proposition courante), un entier (la taille du texte)
Sortie: un booléen , Vrai si la proposition est accepter, faux sinon
*/
bool Metropolis(const float score_actuel, const float score_courant, const unsigned int taille);

/*
Rôle : évaluer la plausibilité d'un texte avec une comparaison par bigrammes
Entrée : un tableau de caractères (le texte initial), un entier (la taille du texte), un tableau de tableau de réels (la fréquence des bigrammes)
Entrée / Sortie : un tableau de caractère (le texte courant), 3 tableaux de caractères (les propositions de clé (actuelle, courante et best))
Sortie : un réel (le meilleur score obtenu)
*/
float MetropolisBoucle(const char texte_crypt[], const unsigned int taille_texte, const float bigrammes[42][42], char texte_crypt_courant[], char proposition_courante[], char proposition_actuelle[], char best_proposition[]);