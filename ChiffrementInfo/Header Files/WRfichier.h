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
void Affiche_cle(const string nomfichier_mess, const string nomfichier_key, const char cle[], const char texteDecrypter[], const unsigned int taille);

/*
R�le : copy un tableau de caract�re dans un autre de taille identique
Entr�e : le tableau que l'on va copier, un entier : la taille du tableau
Entr�e / Sortie : le tableau de caract�re qui va �tre remplac�
*/
void Copy(const char tab2[], const unsigned int taille, char tab1[]);