#include "utils.h"

char UpperCase(char lettre) {
	int asciiEncode = int(lettre);

	if (asciiEncode <= 122 && asciiEncode >= 97) {
		asciiEncode = asciiEncode - 32;
	}
	return char(asciiEncode);

}