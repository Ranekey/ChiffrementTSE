#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
R�le : Ecrit le text crypter dans le tableau et renvoie la taille pratique (donc le nombre de charact�re dans le texte)
Entr�e : le nom du fichier dans lequelle se trouve le texte
Entr�e / Sortie : un tableau dans lequel chaque caract�re sera enregistr�
Sortie : la taille pratique du tableau texte (donc le nombre de charact�re)
*/
unsigned int TextInTab(const string nomfichier, char texte[]);

/*
R�le : Convertir les fr�quences d'apparitions des caract�res d'un fichier txt dans un tableau de r�els
Entr�e : la localisation du fichier contenant les fr�quences d'apparitions de chaque lettres
Entr�e / Sortie : un tableau de r�els avec les fr�quences d'apparitions de chaque lettres dans l'ordre alphab�tique
Sortie : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
R�le : Permet de configurer le bigramme � partir d'un fichier texte
Entr�e : un string �tant le nom du fichier
Entr�e / Sortie : le tableau de tableau de r�els dans lequel le bigramme va �tre enregistr�
Sortie : un bool�an , Vrai si l'enregistrement s'est effectuer sans erreur, faux sinon
*/
bool SetBigrammeComplet(const string nomfichier, float bigramme[42][42]);

/*
R�le : Permet d'afficher la cl� et le texte d�crypter dans un fichier texte mais aussi dans la console
Entr�e : un string (le nom du fichier o� la cl� et le texte seront enregistr�s), un tableau de caract�res (la cl�), un tableau (le texte d�crypter � mettre dans le fichier), un entier (la taille du texte)
Sortie : vide
*/
void Affiche_cle(const string nomfichier_mess, const string nomfichier_key, const char cle[], const char texteDecrypter[],  unsigned int taille);

/*
R�le : copy un tableau de caract�re dans un autre de taille identique
Entr�e : le tableau que l'on va copier, un entier : la taille du tableau
Entr�e / Sortie : le tableau de caract�re qui va �tre remplac�
*/
void Copy(const char tab2[], unsigned int taille, char tab1[]);

/*
R�le : produit un tableau de 27 charct�res avec le nombre de mots commencent avec une lettre
Entr�e: fichier avec la liste de mots
Sortie : un pointeur vers le tableau cr�er
*/
int* OccurenceMotLettre(const string Dico);

/*
R�le: indiquer o� le cursor doit commencer pour optimiser la recherche de mot;
Entr�: le rang dans l'alphabet de la 1er lettre du mot � cherhcer, 
un pointeur vers un tableau 
Sortie: un entier indiquant o� le curseur doit commencer
*/
unsigned int StartPosCursor(char lettre, const int* tabOccurenceMotLettre);

/*
R�le : indiquer l'intervalle dans lequelle le curseur peut se d�placer
Entr�e : le rang dans l'alphabet de la 1er lettre du mot � cherhcer, 
un pointeur vers un tableau
Sortie : un entier �tant l'intervalle dans lequelle le curseur peut se d�placer
*/
unsigned int Interval(char lettre, const int* tabOccurenceMotLettre);