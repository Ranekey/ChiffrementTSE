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
void FreqApparitions(const char texte[], float freq[]);

/*
Rôle : Associer à chaque lettre de l'alphabet sa fréquence en utilisant le type composé dicoFreq
Entrée : 1 tableau de caractère étant l'alphabet à associer, 1 tableau de réels étant les fréquences d'apparitions des lettres dans l'ordre alphabétique
Entrée / Sortie : 1 tableau de type composé dicoFreq où les lettres et les fréquences sont associés par pairs
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
void Proposition_initiale(const char alphabet[], const float freqAlphabet[], const char texte[], char proposition[]);

/*
R: melanger les caractere d'une chaine de caracteres
E: 1 tableau de caracteres avec caracteres non melangés
E/S: 1 tableau de caracteres avec lettres melangers
S: Vide
*/
void Proposition(int tailleProposition, char proposition[]);

/*
Rôle : Assigne un score de plausibilité à un tableau de charactère
Entrée : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte
Sortie : un réel représentant le score du texte
*/
float ScoreBigramm(const string texte, unsigned int tpTexte, const float bigramme[42][42]);

float ScoreQuadgramm(const char texte[], unsigned int tpTexte, float quadgramm[42][42][42][42]);

/*
Rôle: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entrée : un charactère (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
A NE PLUS UTTILISER,
*/
int LettreToNumber(char lettre);
/*
même rôle que lettre to number mais prends en compte un alphabet plus grand
*/
int LettreToNumberComplet(char lettre);
/*
Rôle: Application d'une proposition à un texte donné
Entrée : la taille pratique du texte (un entier) une proposition (tableaux de 26 caractères)
Entrée / Sortie: un tableau de caractères (le texte à traduire qui est traduit)
Sortie : vide
*/
void ApplicationProposition(const char texte_initial[], char texte_traduit[], const unsigned int tpTexte, const char proposition[]);

/*
Rôle: renvoie si le message décrypter doit être garder ou non grâce a une loi de probabilité
Entrée : un réel (le score actuel entrain d'être analyser), un réel (le score courant), un réel (la température utilisée pour le calcul)
Sortie : un booléean, vrai si la nouvelle proposition est accepter, faux sinon
*/
bool Recuit(const float score_actuel, const float score_courant, const float temperature);

/*
Rôle : Evaluer la plausibilité d'un texte avec une liste de mots
Sortie : un réel (le meilleur score obtenu)
*/
float Recuit_boucle(const char texte_crypt[], char texte_crypt_courant[], const unsigned int taille_texte, char best_proposition[27], string listeMots, const unsigned int taille_liste, const float bigrammes[42][42]);

/*
Rôle : Evaluer le score d'un texte en fonction du nombre de mots présents parmi une liste de mots (ici en Francais)
Entrée: un tableau de caractères (le texte à évaluer), un tableau de tableau de caractères (la liste des mots), un entier (le nombre de mots dans la liste)
Sortie : un réel (le score du texte)
*/
float Score_Mots(const char texte[], string dico);


/*
Rôle : utiliser l'algorithme de métropolis pour savoir si une proposition est conserver ou non
Entrée : le score de proposition actuelle et proposition courant, la taille du texte
Sortie: un bool , Vrai si la proposition est accepter, faux sinon
*/
bool Metropolis(float score_courant, float score_actuelle, unsigned int taille);

/*
Rôle : Evaluer la plausibilité d'un texte avec une comparaison par bigrammes
Sortie : un réel (le meilleur score obtenu)
*/
float MetropolisBoucle(const char texte_crypt[], char texte_crypt_courant[], unsigned int taille_texte, char proposition_courante[], char proposition_actuelle[], char best_proposition[], float bigrammes[42][42]);