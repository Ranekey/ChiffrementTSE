void Proposition();
/*
R�le : Assigne un score de plausibilit� � un tableau de charact�re
Entr� : Un tableau de caract�res �tant le texte, un entier correspondant � la taille r�elle du texte
Sortie : un r�el repr�sentant le score du texte
*/
float Score(char texte[], unsigned int tpTexte, float bigramme[26][26]);

/*R : Etablir une proposition initial � partir d'un texte donn� en fonction de la fr�quence d'appartion des lettres
E : Un tableau de la fr�quence d'apparition de chacune des 26 lettres (dans l'ordre A � Z)
E / S : Un tableau �tant la proposition de l'ordre des 26 lettres
S : vide*/
void Proposition_initiale(float freq[], float proposition[]);

/*R : Retourner la fr�quence d'apparation de chaque lettres dans un texte
E : Un tableau de caract�res �tant le texte, un entier correspondant � la taille r�elle du texte
E / S : Un tableau de la fr�quence d'apparation de chaque lettres en pourcentage (dans l'ordre A �Z)
S : vide*/
void FreqApparitions(char texte[], int taille_texte, char freq[]);


/*
R�le: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('a') = 0
Entr�e : un charct�re (entre simple cote)
Sortie : un entier entre 0 et 25
*/
unsigned int LettreToNumber(char lettre);