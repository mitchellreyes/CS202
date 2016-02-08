#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	char array[] = { 'a', 'b', 'c', 'd'};
	char* arrPtr = array;
	for(int i = 0; i < 4; i++){
		cout << *arrPtr << endl;
		arrPtr++;
	}
	arrPtr = array; //make sure to reset the pointer back to the original pos


	/** student s1;
		s1.boringlevel = 9000;
		s1.gender = 'm';
		student* strPtr;
		strPtr = &s1;
		cout << (*strPtr).boringLevel << endl;

			//(*strPtr).boring will dereference to s1 then it will do the .boringlevel operator

	**/
return 0;
}