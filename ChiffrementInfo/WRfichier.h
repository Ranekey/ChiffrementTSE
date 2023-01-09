#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void Ecriture(string nomfichier, string texte);

//Ecrit le text crypter dans le tableau et renvoie la taille pratique( donc le nombre de charactère dans le texte)
unsigned int TextInTab(string nomfichier, char texte[]);

void LectureParMots(string nomfichier);
void LectureGlobal(string nomfichier);