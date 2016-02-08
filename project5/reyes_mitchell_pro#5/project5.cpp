#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "string.h"
#include "class.h"

using namespace std;

void printReel(symbol *reel);
void readIn(ifstream &fin, symbol *readInArray);
void populateReel(symbol *readInArray, symbol *reel);
void selectReel(symbol *reel);

int main(){
	srand(time(NULL));
	char *filename = new char[20];
	cout << "What file needs to be inputted?: ";
	cin >> filename;
	ifstream fin(filename);
	symbol *readInArray = new symbol[6];
	symbol *reel = new symbol[10];
	if(fin.good()){
		int x;
		readIn(fin, readInArray);
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
						populateReel(readInArray, reel);
						break;
					case 2: 
						cout << endl;
						printReel(reel);
						cout << endl;
						break;
					case 3:
						selectReel(reel);
						break;
					default:
						cout << "Thanks." << endl << endl;
						break;
				}
			}while(x != 4);
	}else{
		cout << "Error: No file to be found." << endl;
	}

}

void readIn(ifstream &fin, symbol *readInArray){
	symbol *readInArrayHome = readInArray;
	for(int i = 0; i < 6; i++){
		char *temp=new char[20];
		fin >> temp;
		int length = stringLen(temp);
		(*readInArray).setName(temp, length);
		int x;
		fin >> x;
		(*readInArray).setBonus(x);
		readInArray++;
		delete[]temp;
	}
	readInArray = readInArrayHome;
}

void populateReel(symbol *readInArray, symbol *reel){
	symbol *readInArrayHome = readInArray;
	symbol *reelHome = reel;
	for(int i = 0; i < 10; i++){
		for(int k = 0; k < rand()%6; k++){
			readInArray++;
		}
		int length = stringLen((*readInArray).getName());
		(*reel).setName((*readInArray).getName(), length);
		(*reel).setBonus((*readInArray).getBonus());
		readInArray = readInArrayHome;
		reel++;
	}
	readInArray = readInArrayHome;
	reel = reelHome;
}

void printReel(symbol *reel){
	symbol* reelHome = reel;
	for(int i = 0; i < 10; i++){
		(*reel).print();
		reel++;
	}
	reel = reelHome;
}

void selectReel(symbol *reel){
	symbol *reelHome = reel;
	int x;
	cout << "Which reel do you want? (1-10): ";
	cin >> x;
	for(int i = 1; i < x; i++){
		reel++;
	}
	(*reel).print();
	reel = reelHome;
}