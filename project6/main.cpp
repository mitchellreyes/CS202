#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include "string.h"
#include "class.h"

using namespace std;

void readin(ifstream &fin, symbol *readArray);
void populateReels(reel *slotRows, symbol *readArray);
void printSlot(reel *slotRows);
void spinReel(reel *slotRows);
void selectReel(reel *slotRows);

int main(){
	srand(time(NULL));
	symbol *readArray = new symbol[6];
	reel *slotRows = new reel [3];
	char fileName[20];
	cout << "What file needs to be read?: ";
	cin >> fileName;
	ifstream fin(fileName);
	readin(fin, readArray);
	int x;
	if(fin.good()){
		do{
			do{
				cout << endl;
				cout << "1. Reconfigure/Configure slots" << endl;
				cout << "2. Print configuration" << endl;
				cout << "3. Choose a reel and stop" << endl;
				cout << "4. Get a payline" << endl;
				cout << "5. Quit" << endl;
				cout << "Choose a option from the menu above: ";
				cin >> x;
				cout << endl;
			}while(x < 0 && x > 5);
				switch(x){
					case 1:
						populateReels(slotRows, readArray);
						break;
					case 2: 
						cout << endl;
						printSlot(slotRows);
						cout << endl;
						break;
					case 3:
						selectReel(slotRows);
						break;
					case 4:
						cout << endl;
						spinReel(slotRows);
						cout << endl;
						break;
					default:
						cout << "Thanks." << endl << endl;
						break;
				}
			}while(x != 5);	
	}else{
		cout << "Error: Unable to locate desired file." << endl;
	}
	
	return 0;
}

void readin(ifstream &fin, symbol *readArray){
	for(int i = 0; i < 6; i++){
		char *temp = new char[20];
		fin >> temp;
		readArray[i].setName(temp);
		int x;
		fin >> x;
		readArray[i].setValue(x);
		readArray[i].setBonus(x);
		delete[]temp;
		temp = NULL;
	}
}

void populateReels(reel *slotRows, symbol *readArray){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 10; j++){
		int k = 0;
		while(k < rand()%6){
			k++;	
		}
		slotRows[i].setValues(readArray, k, j);
		}
	}	
}

void printSlot(reel *slotRows){
	for(int i = 0; i < 10; i++){
		for(int k = 0; k < 3; k++){
			slotRows[k].printReel(i);	
		}
		cout << endl;
	}
}

void spinReel(reel *slotRows){
	for(int i = 0; i < 3; i++){
		slotRows[i].spin(rand()%10);
		slotRows[i].printReel(rand()%10);
	}
	cout << endl;
}

void selectReel(reel *slotRows){
	int x;
	cout << "Which row (1-3): ";
	cin >> x;
	int y;
	cout << "Which reel slot (1-10): ";
	cin >> y;
	cout << endl;
	slotRows[x-1].printReel(y-1);
	cout << endl;
}