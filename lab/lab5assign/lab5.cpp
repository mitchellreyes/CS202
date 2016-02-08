#include <iostream>
#include "stringLib.h"

using namespace std;

int main(){
	char string1[20];
	char string2[20];
	char *s1 = string1;
	char *s2 = string2;
	cout << "Enter word 1: ";
	cin >> string1;
	cout << "Enter word 2: ";
	cin >> string2;
	stringCopy(s1, s2);
	stringCat(s1, s2);
	stringLen(s1, s2);
	stringComp(s1, s2);


return 0;
}
