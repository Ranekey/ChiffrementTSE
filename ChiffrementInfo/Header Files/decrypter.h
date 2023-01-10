void Proposition();

/*
Rôle : Assigne un score de plausibilité à un tableau de charactère
Entré : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte
Sortie : un réel représentant le score du texte
*/
float Score(char texte[], unsigned int tpTexte, float bigramme[26][26]);

/*R : Etablir une proposition initial à partir d'un texte donné en fonction de la fréquence d'appartion des lettres
E : Un tableau de la fréquence d'apparition de chacune des 26 lettres (dans l'ordre A à Z)
E / S : Un tableau étant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(float freq[], float proposition[]);

/*R : Retourner la fréquence d'apparation de chaque lettres dans un texte
E : Un tableau de caractères étant le texte
E / S : Un tableau de la fréquence d'apparation de chaque lettres en pourcentage (de 0 à 1) (dans l'ordre A à Z)
S : vide*/
void FreqApparitions(char texte[], float freq[]);

/*
Rôle: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entrée : un charactère (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
*/
int LettreToNumber(char lettre);