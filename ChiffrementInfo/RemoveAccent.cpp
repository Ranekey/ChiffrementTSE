#include "utils.h"


char RemoveAccent(char lettre) {
	char sansAccent = lettre;
	int asciiEncode = int(lettre);
	if (asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'A';
	}
	else if(asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�') || asciiEncode == int('�')) {
		sansAccent = 'E';
	}
	else if (asciiEncode == int('�') || asciiEncode == int('�')){
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