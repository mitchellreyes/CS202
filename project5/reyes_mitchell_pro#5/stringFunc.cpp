#include <iostream>
using namespace std;

void stringCopy(char *dest, char *src){
	char *destHome = dest;
	char *srcHome = src;
	while(*src != '\0'){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	dest = destHome;
	src = srcHome;
}

int stringLen(char *word){
	char *wordHome = word;
	int i = 0;
	while(*word != '\0'){
		word++;
		i++;
	}
	word = wordHome;
	return i;
}