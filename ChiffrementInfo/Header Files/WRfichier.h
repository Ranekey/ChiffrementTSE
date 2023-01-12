#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Ecriture(string nomfichier, string texte);

//Ecrit le text crypter dans le tableau et renvoie la taille pratique( donc le nombre de charact�re dans le texte)
/*
R�le : Ecrit le text crypter dans le tableau et renvoie la taille pratique( donc le nombre de charact�re dans le texte)
Entr�e : le nom du fichier dans lequelle se trouve le texte, un tableau dans lequelle chaque charct�re sera enregistrer
Sortie : la taille pratique du tableau texte (donc le nombre de charct�re) 
*/
unsigned int TextInTab(const string nomfichier, char texte[]);

/*
R�le : Permet de configuer le bigramme � partir d'un fichier texte
Entr�e : le nom du fichier, le tableau dans lequelle le bigramme va �tre enregistrer
Sortie : un bool�an , Vrai si l'enregistrement s'est effuctuer sans erreur, faux sinon
*/
bool SetBigramme(string nomfichier, float bigramme[27][27]);

/*

*/
void InitialisationBigramme(float bigramme[27][27]);

unsigned int CompteMotsCorrect(char texte[]);





void LectureParMots(string nomfichier);
void LectureGlobal(string nomfichier);