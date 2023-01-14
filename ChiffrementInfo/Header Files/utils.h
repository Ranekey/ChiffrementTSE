/*
Rôle : initialiser un tableau de réel avec la même valeur
Entrée : le tableau de réels à initialiser, l'indice jusqu'au quel on veut que les valeurs soient initialisées, la valeur initial
Sortie : Vide
*/
void InitialisationTableau(float tab[], const unsigned int tpTab, float valeurInitial);


/*
Rôle : Convertir en majuscule une lettre miniscule
Entrée : la lettre à convertire 
Sortie : la lettre convertit en majuscule
*/
char UpperCase(char lettre);
/*
Rôle : copy deux tableau de taille identique
*/
void Copy(unsigned int taille, char tab1[], const char tab2[]);

/*


*/
char RemoveAccent(char lettre);

char RemoveWeirdCharactre(char lettre);


/*
Rôle : initialiser un tableau de tableau de réel 
Entrée : l'addresse du tableau, l'indice jusqu'au qu'elle l'on veut que les valeurs soit initialiser, la valeur initial
Sortie : Videau
*/
//void InitialisationTableau2D(float tab[][], unsigned int ligne ,unsigned int tpTab, float valeurInitial);