void Proposition();
float Score();

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
Permet de donne l'indice d'une lettre dans l'alphabet
*/
unsigned int LettreToNumber(char lettre);