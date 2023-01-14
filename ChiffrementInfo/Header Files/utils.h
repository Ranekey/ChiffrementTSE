/*
R�le : initialiser un tableau de r�el avec la m�me valeur
Entr�e : le tableau de r�els � initialiser, l'indice jusqu'au quel on veut que les valeurs soient initialis�es, la valeur initial
Sortie : Vide
*/
void InitialisationTableau(float tab[], const unsigned int tpTab, float valeurInitial);


/*
R�le : Convertir en majuscule une lettre miniscule
Entr�e : la lettre � convertire 
Sortie : la lettre convertit en majuscule
*/
char UpperCase(char lettre);
/*
R�le : copy deux tableau de taille identique
*/
void Copy(unsigned int taille, char tab1[], const char tab2[]);

/*


*/
char RemoveAccent(char lettre);

char RemoveWeirdCharactre(char lettre);


/*
R�le : initialiser un tableau de tableau de r�el 
Entr�e : l'addresse du tableau, l'indice jusqu'au qu'elle l'on veut que les valeurs soit initialiser, la valeur initial
Sortie : Videau
*/
//void InitialisationTableau2D(float tab[][], unsigned int ligne ,unsigned int tpTab, float valeurInitial);