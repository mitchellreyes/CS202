#include <iostream>
#include <fstream>
using namespace std;

//Function prototypes
void readFromFile(ifstream &fin, char array[10][3][10]);
void outputToFile(char array[10][3][10]);

int main(){
	//file input
	ifstream fin ("symbols");
	//creates an 3D array
	char array[10][3][10];
	//check if file is uncorrupted
	if(fin.good()){
		//puts the words into arrays
		readFromFile(fin, array);
		//outputs the array into a file
		outputToFile(array);
		//loop through array
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 3; j++){
				//outputs the array on the screen
				cout << array[i][j];
				//adds a space after each string
				cout << " ";
			}
		//adds a endline character after 3 strings
		cout << endl;
		}
	}
	else{
		//if corrupted then output error message
		cout << "Error: Unable to read file.";
	}
	//close the document
	fin.close();
return 0;
}

void readFromFile(ifstream &fin, char array[10][3][10]){
	//Loop through cols
	for(int i = 0; i < 10; i++){
		//Loop through rows 
		for(int j = 0; j < 3; j++){
			//read strings to array
			fin >> array[i][j];
		}
	}
}

void outputToFile(char array[10][3][10]){
	//create array for user input
	char userString[50];
	//Prompt for filename
	cout << "Enter a desired filename: ";
	//puts the string into the array
	cin >> userString;
	//open output file
	ofstream fout (userString);
	//Loops through cols
	for(int i = 0; i < 10; i++){
		//Loops through rows
		for(int j = 0; j < 3; j++){
			//outputs the array pos
			fout << array[i][j];
			//adds a space between each string
			fout << " ";
		}
		//adds a endline character after 3 strings 
		fout << endl;
	}
}



