#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void Ecriture(string nomfichier, string texte);

//Ecrit le text crypter dans le tableau et renvoie la taille pratique( donc le nombre de charactère dans le texte)
/*
Rôle : Ecrit le text crypter dans le tableau et renvoie la taille pratique( donc le nombre de charactère dans le texte)
Entrée : le nom du fichier dans lequelle se trouve le texte, un tableau dans lequelle chaque charctère sera enregistrer
Sortie : la taille pratique du tableau texte (donc le nombre de charctère) 
*/
unsigned int TextInTab(string nomfichier, char texte[]);

/*
Rôle : Permet de configuer le bigramme à partir d'un fichier texte:
Entrée : le nom du fichier, le tableau dans lequelle le bigramme va être enregistrer
Sortie : un booléan , Vrai si l'enregistrement s'est effuctuer sans erreur, faux sinon

Note: le fonctionne est semblable à celui de FreqApparitions dans Propposition.cpp
*/
bool SetBigramme(string nomfichier, float bigramme[26][26]);


void LectureParMots(string nomfichier);
void LectureGlobal(string nomfichier);