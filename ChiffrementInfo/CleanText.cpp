#include "utils.h"
#include <iostream>
using namespace std;

char UpperCase(char lettre) {
	int asciiEncode = int(lettre);

	if (asciiEncode <= 122 && asciiEncode >= 97) {
		asciiEncode = asciiEncode - 32;
	}
	return char(asciiEncode);

}

char RemoveAccent(char lettre) {
	char sansAccent = lettre;
	int asciiEncode = int(lettre);
	if (asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'A';
	}
	else if (asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'E';
	}
	else if (asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'I';
	}
	else if (asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'O';
	}
	else if (asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'U';
	}
	else if (asciiEncode == int('�')) {
		sansAccent = 'Y';
	}
	else if (asciiEncode == int('�')) {
		sansAccent = 'C';
	}

	return sansAccent;

}
char RemoveWeirdCharactre(char lettre) {
	char standardiser = lettre;
	if (int(lettre) > 92 || int(lettre) < 64) {
		standardiser = ' ';// on remplace par un espce
	}
	return standardiser;
}

