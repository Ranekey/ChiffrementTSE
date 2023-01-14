#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
Rôle : Ecrit le text crypter dans le tableau et renvoie la taille pratique (donc le nombre de charactère dans le texte)
Entrée : le nom du fichier dans lequelle se trouve le texte, un tableau dans lequelle chaque charctère sera enregistré
Sortie : la taille pratique du tableau texte (donc le nombre de charactère)
*/
unsigned int TextInTab(const string nomfichier, char texte[]);
/*
Rôle : Convertir les frequences d'apparitions des caractères d'un fichier txt à un tableau de réels
Entrée : la localisation du fichier contenant les fréquences d'apparitions de chaque lettres
Entrée / Sortie : un tableau de réels avec les fréquences d'apparitions de chaque lettres dans l'ordre alphabétique
Sortie : vide
*/
void FreqToTab(const string nomFichier, float tabFreq[]);

/*
Rôle : Permet de configurer le bigramme à partir d'un fichier texte
Entrée : le nom du fichier, le tableau dans lequelle le bigramme va être enregistré
Sortie : un booléan , Vrai si l'enregistrement s'est effuctuer sans erreur, faux sinon
*/
bool SetBigramme(string nomfichier, float bigramme[26][26]);
bool SetBigrammeComplet(string nomfichier, float bigramme[42][42]);
bool SetQuadgramm(string nomfichier, float quadgramm[42][42][42][42]);

/*
Rôle :
Entrée :
Sortie :
*/
void InitialisationBigramme(float bigramme[26][26]);

/*
Rôle : permet d'afficher la clé et le texte décrypter
Entrée : la clé et le texte décrypter sous forme de tableau, le nom du fichier où la clé ser enrgistrer
Sortie : vide
*/

void affiche_cle(unsigned int taille, char cle[], char texteDecrypter[], string nomfichier);
/*
Rôle : Lire le fichier contenant le mots et les mettres dans un tableau de tableau
Entrée : le chemin du fichier en string
Entrée / Sortie : le tableau de tableau de caratères cotenant les mots
Sortie : un entier (la taille de liste de mots, c'est à dire le nombre de mots dans la liste)
*/
unsigned int RecuperationMots(const string fichier, char liste_mots[][50]);