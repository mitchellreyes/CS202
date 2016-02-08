#include <iostream>
using namespace std;

void stringCopy(char *s1, char *s2){
	int i = 0;
	char string1[20];
	char string2[20];
	char *strPtr1 = string1;
	char *strPtr2 = string2;
	char *temp = s1;
	char *tmp = s2;
	while(*s1 != '\0'){
		*strPtr1 = *s1;
		strPtr1++;
		s1++;
	}
	*strPtr1 = '\0';
	s1 = temp;
	strPtr1 = string1;
	while(*s2 != '\0'){
		*strPtr2 = *s2;
		strPtr2++;
		s2++;
	}
	*strPtr2 = '\0';
	s2 = tmp;
	cout << "Copy string 1 into new array: " << string1 << endl;
	cout << "Copy string 2 into new array: " << string2 << endl;
}

void stringCat(char *s1, char *s2){
	char *temp = s1;
	char *garb = s2;
	char useless[50];
	char *output = useless;
	char *outHome = output;
	while(*s1 != '\0'){
		*output = *s1;
		s1++;
		output++;
	}
	while(*s2 != '\0'){
		*output = *s2;
		s2++;
		output++;
	}
	*output = '\0';
	cout << "String concat: " << useless << endl;
	s1 = temp;
	s2 = garb;
	output = outHome;
}

int stringLen(char *s1){//, char *s2){
	char *temp = s1;
	//char *garb = s2;
	int x = 0;
	//int y = 0;
	while(*s1 != '\0'){
		s1++;
		x++;
	}
	return x;
	s1 = temp;
	/**while(*s2 != '\0'){
		s2++;
		y++;
	}
	s2 = garb;**/
	//cout << "String length of string 1: " << x << endl;
	//cout << "String length of string 2: " << y << endl;
}

bool stringComp(char *s1, char *s2){
	char *temp = s1;
	char *garb = s2;
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1 == *s2){
			s1++;
			s2++;
		}else{
			return false;
			//break;
		}
	}
	if(*s1 == '\0' && *s2 == '\0'){
		return true;
	}else{
		return false;
	}
	s1 = temp;
	s2 = garb;

}