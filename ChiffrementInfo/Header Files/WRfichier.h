#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
R�le : Ecrit le text crypter dans le tableau et renvoie la taille pratique (donc le nombre de charact�re dans le texte)
Entr�e : le nom du fichier dans lequelle se trouve le texte, un tableau dans lequelle chaque charct�re sera enregistr�
Sortie : la taille pratique du tableau texte (donc le nombre de charact�re)
*/
unsigned int TextInTab(const string nomfichier, char texte[]);
/*
R�le : Convertir les frequences d'apparitions des caract�res d'un fichier txt � un tableau de r�els
Entr�e : la localisation du fichier contenant les fr�quences d'apparitions de chaque lettres
Entr�e / Sortie : un tableau de r�els avec les fr�quences d'apparitions de chaque lettres dans l'ordre alphab�tique
Sortie : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
R�le : Permet de configurer le bigramme � partir d'un fichier texte
Entr�e : le nom du fichier, le tableau dans lequelle le bigramme va �tre enregistr�
Sortie : un bool�an , Vrai si l'enregistrement s'est effuctuer sans erreur, faux sinon
*/
bool SetBigramme(string nomfichier, float bigramme[26][26]);
bool SetBigrammeComplet(string nomfichier, float bigramme[42][42]);
bool SetQuadgramm(string nomfichier, float quadgramm[42][42][42][42]);

/*
R�le :
Entr�e :
Sortie :
*/
void InitialisationBigramme(float bigramme[26][26]);

/*
R�le : permet d'afficher la cl� et le texte d�crypter
Entr�e : la cl� et le texte d�crypter sous forme de tableau, le nom du fichier o� la cl� ser enrgistrer
Sortie : vide
*/

void affiche_cle(unsigned int taille, char cle[], char texteDecrypter[], string nomfichier);
/*
R�le : Lire le fichier contenant le mots et les mettres dans un tableau de tableau
Entr�e : le chemin du fichier en string
Entr�e / Sortie : le tableau de tableau de carat�res cotenant les mots
Sortie : un entier (la taille de liste de mots, c'est � dire le nombre de mots dans la liste)
*/
unsigned int RecuperationMots(const string fichier, char liste_mots[][50]);