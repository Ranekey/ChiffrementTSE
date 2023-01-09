void Proposition();
float Score();

/*R : Etablir une proposition initial à partir d'un texte donné en fonction de la fréquence d'appartion des lettres
E : Un tableau de la fréquence d'apparition de chacune des 26 lettres (dans l'ordre A à Z)
E / S : Un tableau étant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(float freq[], float proposition[]);

/*R : Retourner la fréquence d'apparation de chaque lettres dans un texte
E : Un tableau de caractères étant le texte, un entier correspondant à la taille réelle du texte
E / S : Un tableau de la fréquence d'apparation de chaque lettres en pourcentage (dans l'ordre A àZ)
S : vide*/
void FreqApparitions(char texte[], int taille_texte, char freq[]);


/*
Permet de donne l'indice d'une lettre dans l'alphabet
*/
unsigned int LettreToNumber(char lettre);