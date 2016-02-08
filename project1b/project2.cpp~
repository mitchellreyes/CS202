#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototypes
void outputToFile(char array[10][3][10], int bonus[6], char symbols[6][8]);
void readFromFile(ifstream &fin, char symbols[6][8], int bonus[6]);
void stringCopy(char dest[], char src[]);
void populateSlots(char array[10][3][10], char symbols[6][8]);
bool stringComp(char str1[], char str2[]);
void readFromOutput(char array[10][3][10]);
void outputToScreen(char array[10][3][10], char symbols[6][8], int bonus[6]);
void pickReel(char array[10][3][10], char symbols[6][8], int bonus[6]);


int main(){
	//seeds the random number
	srand(time(NULL));
	//makes an input variable and takes in a file
	ifstream fin ("symbols");
	char array[10][3][10];
	char symbols[6][8];
	int bonus[6];
	if(fin.good()){
		int x;
		do
		{
			//initialize the 3D array reel//
			readFromFile(fin, symbols, bonus);
			populateSlots(array, symbols);
			///////////////////////////////
			
			//outputs a menu display
			cout << "1. Reconfigure Slot Machine." << endl 
			<< "2. Read in an existing configuration" << endl
			<< "3. View Configuration" << endl
			<< "4. Pick reel number" << endl
			<< "5. Quit" << endl; 
			cout << "Please enter a number from the choices above: ";
			cin >> x;
			//with certain keystrokes, it will do the functions with the corresponding keystroke	
			switch(x){
				//1 is pressed
				case 1:
					populateSlots(array, symbols);
					outputToFile(array, bonus, symbols);
					break;
				//2 is pressed
				case 2:
					readFromOutput(array);
					break;
				//3 is pressed
				case 3:
					outputToScreen(array, symbols, bonus);
					break;
				//4 is pressed
				case 4:
					pickReel(array, symbols, bonus);
					break;
				//anything else is pressed, it will display the menu again with an error message
				default:
					cout << "Please try a different number." << endl;
					cout << "1. Reconfigure Slot Machine." << endl 
						<< "2. Read in an existing configuration" << endl
						<< "3. View Configuration" << endl
						<< "4. Pick reel number" << endl
						<< "5. Quit" << endl; 
						cout << "Please enter a number from the choices above: " << endl;
			}
		//keep doing the menu until 5 is pressed 
		} while (x != 5);

	}else{
		//error is the file isnt there
		cout << "Error: Unable to read file.";
	}
	//closes the document
	fin.close();
return 0;
}

//this function reads in the characters from the given file
void readFromFile(ifstream &fin, char symbols[6][8], int bonus[6]){

	for(int i = 0; i < 6; i++){
		fin >> symbols[i];
		fin >> bonus[i];	
	}
}

//this outputs the array to a output file
void outputToFile(char array[10][3][10], int bonus[6], char symbols[6][8]){
	char userString[50];
	cout << "Enter a desired output filename: ";
	cin >> userString;
	
	ofstream fout (userString);
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			fout << array[i][j] << " ";
			for(int k = 0; k < 6; k++){
				//checking if the index of the 3D array match with the 2D array, then prints out the corresponding address of the bonus number
				if(stringComp(array[i][j], symbols[k]) == true){
					fout << bonus[k] << " ";
				}
			}
		}
	fout << endl;
	} 
}
//randomly outputs the symbols to a 3D array
void populateSlots(char array[10][3][10], char symbols[6][8]){
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			int x = rand()%6;
			stringCopy(array[i][j], symbols[x]);
			//
		}
	}
}

//copies a string
void stringCopy(char dest[], char src[]){
	int i = 0;
	while (src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

//string compare. Compares 2 strings against each other to see if theyre the same or not
bool stringComp(char str1[], char str2[]){
	int i = 0;
	while(str1[i] != '\0'){
		if(str1[i] != str2[i]){
			return false;
		}
		i++;
	}
	if(str2[i] == '\0'){
		return true;
	}
	return false;
}

//reading in the output file given by the user
void readFromOutput(char array[10][3][10]){
	char userString[50];
	cout << "Enter File name: ";
	cin >> userString;
	int trashcan;
	ifstream fin (userString);
	if(fin.good()){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 3; j++){
				fin >> array[i][j] >> trashcan;
			}
		} 	
	}else{
		cout << "Error: Unknown File." << endl;
	}
}

//prints the outputted file values to the screen
void outputToScreen(char array[10][3][10], char symbols[6][8], int bonus[6]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			cout << array[i][j] << "(";
			for(int k = 0; k < 6; k++){
				if(stringComp(array[i][j], symbols[k]) == true){
					cout << bonus[k] << ")" << " ";
					}
				}
		}
	cout << endl;
	}
}
 
//lets the user choose a reel to stop on and display it.
void pickReel(char array[10][3][10], char symbols[6][8], int bonus[6]){
	int x;
	cout << "Choose a which row (1-10) to stop on: ";
	cin >> x;
	for(int i = 0; i < 3; i++){
		cout << array[x-1][i] << "(";
		for(int k = 0; k < 6; k++){
			if(stringComp(array[x-1][i], symbols[k]) == true){
				cout << bonus[k] << ")" << " ";
			}
		}
	}
	cout << endl;
}








