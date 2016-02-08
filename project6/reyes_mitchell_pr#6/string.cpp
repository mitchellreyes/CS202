//this is where the string functions are put
#include <iostream>
using namespace std;

void stringCopy(char *dest, char* src){
	int i = 0;
	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

bool stringComp(char *string1, char *string2){
	int i = 0;
	while(*string1 != '\0' && *string2 != '\0'){
		if(string1[i] == string2[i]){
			i++;
		}
	}
	if(string1[i] == '\0' && string2[i] =='\0'){
		return true;
	}
	return false;
}

int stringLength(char *string1){
	int i = 0;
	while(string1[i] != '\0'){
		i++;
	}
	return i;
}