#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "stringLib.h"

using namespace std;

struct symbols{
	char* iconNames = NULL;
	int readBonus;
	bool TFBonus;
};

struct reel{
	symbols *columns = NULL;
	//int bonus;
};
//function prototypes
void readFile(ifstream &fin, symbols *iconList);
void populateSlots(reel *rows, symbols *iconList);
void printSlot(reel *rows);
void printReel(reel *rows);

int main(){
	///start of the program///
	srand(time(NULL)); //seeds the rng
	char *nameFile = new char[20];
	cout << "Please enter a file to be read: ";
	cin >> nameFile;
	ifstream fin (nameFile);
	/////////////////////////

	//initial declaration//
	symbols *iconList = new symbols[6];//makes a list of 6 symbol structs
	symbols *iconListHome = iconList;
	reel *rows = new reel[3];//makes 3 rows of reel structs
	reel *rowHome = rows;
	for(int i = 0; i < 3; i++){
		(*rows).columns = new symbols[10];
		rows++;	
	}
	rows = rowHome;
	int x;

	if(fin.good()){
		readFile(fin, iconList);
		do{
			do{
				cout << endl;
				cout << "1. Reconfigure/Configure slots" << endl;
				cout << "2. Print configuration" << endl;
				cout << "3. Choose a reel and stop" << endl;
				cout << "4. Quit" << endl;
				cout << "Choose a option from the menu above: ";
				cin >> x;
				cout << endl;
			}while(x < 0 && x > 4);
				switch(x){
					case 1:
						populateSlots(rows, iconList);
						break;
					case 2: 
						cout << endl;
						printSlot(rows);
						cout << endl;
						break;
					case 3:
						printReel(rows);
						break;
					default:
						cout << "Thanks." << endl << endl;
						break;
				}
			}while(x != 4);	
	}else{
		cout << "Error: Unable to locate desired file." << endl;
	}

	//deletes the allocated memory at the end of the program
	for(int i = 0; i < 6; i++){
		delete [] (*iconList).iconNames;
		iconList++;
	}
	iconList = iconListHome;
	delete [] iconList;
	iconList = NULL;

	for(int i = 0; i < 3; i++){
		symbols *temp = (*rows).columns;
		for(int j = 0; j < 10; j++){
			delete [](*temp).iconNames;
			temp++;
		}
		delete[] (*rows).columns;
		rows++;
	}
	rows = rowHome;
	delete[]rows;

return 0;	
}

void readFile(ifstream &fin, symbols *iconList){
	symbols *iconListHome = iconList;
	//char *iconNamesHome = (*iconList).iconNames;
	for(int i = 0; i < 6; i++){
		//for the names of the symbols so I have an exact array size copy//
		char *tmp = new char[20];
		char *tmpHome = tmp;
		fin >> tmp;
		int length = stringLen(tmp);
		(*iconList).iconNames = new char[length+1];//compensate for null char
		tmp = tmpHome;
		stringCopy((*iconList).iconNames, tmp);

		//delete [] (*iconList).iconNames;
		delete [] tmp;
		tmp = NULL;
		////////////////////////////////////////////////////////////
		//fin >> (*iconList).iconNames;
		//cout << (*iconList).iconNames << endl;
		fin >> (*iconList).readBonus;
		if((*iconList).readBonus == 0){
			(*iconList).TFBonus = false;
		}else{
			(*iconList).TFBonus = true;
		}
		iconList++;

	}
	iconList = iconListHome;
}

void populateSlots(reel *rows, symbols *iconList){
	reel *rowHome = rows; //home pointer for reel *rows = new reel[3];
	symbols *symbolsList = (*rows).columns; //points to a struct pointer
	char *nameOnSlot = (*symbolsList).iconNames; //accesses the name comp. of struct pointer
	char *nameHome = nameOnSlot; //makes a homepointer for the name array
	symbols *iconListHome = iconList;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < rand()%6; k++){
					iconList++; //iconList will go through the read in array and point to it
				}
				//cout << iconList << endl;
			int length = stringLen((*iconList).iconNames);
			nameOnSlot = new char[length+1];//compensate for null char
			stringCopy(nameOnSlot, (*iconList).iconNames); 
			(*symbolsList).iconNames = nameOnSlot;
			(*symbolsList).readBonus = (*iconList).readBonus;
			iconList = iconListHome;
			symbolsList++;
			nameOnSlot = (*symbolsList).iconNames;
			}

		//symbolsList = (*rows).columns;
		rows++;	
		symbolsList = (*rows).columns;	
		}
	rows = rowHome;
	symbolsList = (*rows).columns;
}

void printSlot(reel *rows){

	reel *rowHome = rows;
	symbols *symbolsList = (*rows).columns;
	char *nameOnSlot = (*symbolsList).iconNames;
	char *nameHome = nameOnSlot; //home pointer
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			symbolsList = (*rows).columns;
			for(int k = 0; k < i; k++){
				symbolsList++;
			}
			cout << (*symbolsList).iconNames << " ";
			cout << (*symbolsList).readBonus << " ";
			rows++;
		}
		cout << endl;
		rows = rowHome;
		symbolsList = (*rows).columns;
	}
	rows = rowHome;
	symbolsList = (*rows).columns;
}

void printReel(reel *rows){
	reel *rowHome = rows;
	symbols *structInRows = (*rows).columns;
	int x;
	int y;
	cout << endl;
	cout << "Pick a row to stop on (1-3): ";
	cin >> x;
	cout << "Pick a reel to stop on (1-10): ";
	cin >> y;
	for(int i = 1; i < x; i++){
		rows++;
		structInRows = (*rows).columns;
		for(int j = 1; j < y; j++){
			structInRows++;
		}
	}
	cout << endl;
	cout << (*structInRows).iconNames << " ";
	cout << "(" << (*structInRows).readBonus << ")" << " ";
	if((*structInRows).readBonus == 0){
		cout << "("<< "0" << ")" << endl;
	}else{
		cout << "(" << "1" << ")" << endl;
	}
	cout << endl;
	rows = rowHome;
	structInRows = (*rows).columns;
}