#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
Rôle : Ecrit le text crypter dans le tableau et renvoie la taille pratique (donc le nombre de charactère dans le texte)
Entrée : le nom du fichier dans lequelle se trouve le texte
Entrée / Sortie : un tableau dans lequel chaque caractère sera enregistré
Sortie : la taille pratique du tableau texte (donc le nombre de charactère)
*/
unsigned int TextInTab(const string nomfichier, char texte[]);

/*
Rôle : Convertir les fréquences d'apparitions des caractères d'un fichier txt dans un tableau de réels
Entrée : la localisation du fichier contenant les fréquences d'apparitions de chaque lettres
Entrée / Sortie : un tableau de réels avec les fréquences d'apparitions de chaque lettres dans l'ordre alphabétique
Sortie : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
Rôle : Permet de configurer le bigramme à partir d'un fichier texte
Entrée : un string étant le nom du fichier
Entrée / Sortie : le tableau de tableau de réels dans lequel le bigramme va être enregistré
Sortie : un booléan , Vrai si l'enregistrement s'est effectuer sans erreur, faux sinon
*/
bool SetBigrammeComplet(const string nomfichier, float bigramme[42][42]);

/*
Rôle : Permet d'afficher la clé et le texte décrypter dans un fichier texte mais aussi dans la console
Entrée : un string (le nom du fichier où la clé et le texte seront enregistrés), un tableau de caractères (la clé), un tableau (le texte décrypter à mettre dans le fichier), un entier (la taille du texte)
Sortie : vide
*/
void Affiche_cle(const string nomfichier_mess, const string nomfichier_key, const char cle[], const char texteDecrypter[],  unsigned int taille);

/*
Rôle : copy un tableau de caractère dans un autre de taille identique
Entrée : le tableau que l'on va copier, un entier : la taille du tableau
Entrée / Sortie : le tableau de caractère qui va être remplacé
*/
void Copy(const char tab2[], unsigned int taille, char tab1[]);

/*
Rôle : produit un tableau de 27 charctères avec le nombre de mots commencent avec une lettre
Entrée: fichier avec la liste de mots
Sortie : un pointeur vers le tableau créer
*/
int* OccurenceMotLettre(const string Dico);

/*
Rôle: indiquer où le cursor doit commencer pour optimiser la recherche de mot;
Entré: le rang dans l'alphabet de la 1er lettre du mot à cherhcer, 
un pointeur vers un tableau 
Sortie: un entier indiquant où le curseur doit commencer
*/
unsigned int StartPosCursor(char lettre, const int* tabOccurenceMotLettre);

/*
Rôle : indiquer l'intervalle dans lequelle le curseur peut se déplacer
Entrée : le rang dans l'alphabet de la 1er lettre du mot à cherhcer, 
un pointeur vers un tableau
Sortie : un entier étant l'intervalle dans lequelle le curseur peut se déplacer
*/
unsigned int Interval(char lettre, const int* tabOccurenceMotLettre);