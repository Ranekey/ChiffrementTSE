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
E : Un tableau de caract�res �tant le texte
E / S : Un tableau de la fr�quence d'apparation de chaque lettres en pourcentage (de 0 � 1) (dans l'ordre A � Z)
S : vide*/
void FreqApparitions(char texte[], float freq[]);

/*
R�le: Permet de donne l'indice d'une lettre dans l'alphabet (exemple : LettreToNumber('A') = 0)
Entr�e : un charact�re (entre simple cote)
Sortie : un entier entre 0 et 25 ou -1 en cas d'erreur
*/
<<<<<<< HEAD
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
de reconduit(qui lui m�me se base sur un algorithme de m�tropolis)
Entr�e : Une proposition donc une chaine de 26 charct�re, le score actuelle du texte, (le score initiale bas� de
l'analyse fr�quentielle, d�finir commme une variable global ou constante )
Sortie : un bool�ean, vrai si la nouvelle proposition est accepter, faux sinon
*/

bool Reconduit(float scoreActuelle, const char noouvelleProposition[]);
=======
int LettreToNumber(char lettre);
>>>>>>> 8d5858f1ebbd245122fb41ed3922484cc95a7962
