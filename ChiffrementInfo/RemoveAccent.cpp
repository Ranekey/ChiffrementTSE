#include "utils.h"


char RemoveAccent(char lettre) {
	char sansAccent = lettre;
	int asciiEncode = int(lettre);
	if (asciiEncode == int('à') || asciiEncode == int('ä') || asciiEncode == int('â')) {
		sansAccent = 'A';
	}
	else if(asciiEncode == int('é') || asciiEncode == int('è') || asciiEncode == int('ê') || asciiEncode == int('ë')) {
		sansAccent = 'E';
	}
	else if (asciiEncode == int('î') || asciiEncode == int('ï')){
		sansAccent = 'I';
	}
	else if (asciiEncode == int('ô') || asciiEncode == int('ö')) {
		sansAccent = 'O';
	}
	else if (asciiEncode == int('ù') || asciiEncode == int('û') || asciiEncode == int('ü')) {
		sansAccent = 'U';
	}
	else if (asciiEncode == int('ÿ')) {
		sansAccent = 'Y';
	}
	else if (asciiEncode == int('ç')) {
		sansAccent = 'C';
	}
	
	return sansAccent;

}