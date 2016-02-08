#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//creates a struct holding the symbols
struct symbols{
	char icons[10];
	int bonusValue;
	bool bonVal;
};

//function prototypes
void readFromFile(ifstream &fin, symbols reels[6]);
void outputToFile(symbols array[10][3]);
void populateSlots(symbols array[10][3], symbols reels[6]);
void readFromOutput(symbols array[10][3]);
void outputToScreen(symbols array[10][3]);
void pickReel(symbols array[10][3]);
void rngStop(symbols array[10][3]);

void outputStructToFile(symbols pos, ofstream &fout);
void printStruct(symbols pos);

void stringCopy(char dest[], char src[]);
bool stringComp(char str1[], char str2[]);

int main(){
	srand(time(NULL));
	ifstream fin ("symbols");
	//makes an array of structs
	symbols reels[6];
	//makes a 2D array of structs
	symbols array[10][3];
	if(fin.good()){
		int x;
		do
		{
			readFromFile(fin, reels);
			do
			{
				cout << "================================================" << endl
				<< "//  1. Configure or Reconfigure Slot Machine  //" << endl 
				<< "//  2. Read in an existing configuration      //" << endl
				<< "//  3. View Configuration                     //" << endl
				<< "//  4. Pick reel number                       //" << endl
				<< "//  5. Get a Payline                          //" << endl
				<< "//  6. Quit                                   //" << endl
				<< "================================================" << endl;
				cout << "Please enter a number from the choices above: ";
				cin >> x;
				//change the '6' if more menu options become available
					if(x > 6 || x < 1){
						cout << "**Error: There is no option for that." << endl << endl;
					}
			//make this '6' the same as the one in the 'if' statement above.
			}while(x > 6 || x < 1);
			//with certain keystrokes, it will do the functions with the corresponding keystroke	
			switch(x){
				case 1:
					cout << endl;
					populateSlots(array, reels);
					outputToFile(array);
					cout << endl;
					break;
				case 2:
					readFromOutput(array);
					break;
				case 3:
					cout << endl;
					outputToScreen(array);
					cout << endl;
					break;
				case 4:
					pickReel(array);
					cout << endl;
					break;
				case 5:
					cout << endl;
					rngStop(array);
					cout << endl;
					break;
				default:
					cout << "Thanks for playing!" << endl << endl;
					break;
			}
		//change this to be consistent with the above values 
		} while (x != 6);

	}else{
		//error is the file isnt there
		cout << "Error: Unable to read file.";
	}
	//closes the document
	fin.close();
return 0;
}

//this function reads in the characters from the given file
void readFromFile(ifstream &fin, symbols reels[6]){
	for(int i = 0; i < 6; i++){
		fin >> reels[i].icons;
		fin >> reels[i].bonusValue;
		if(reels[i].bonusValue == 0){
			reels[i].bonVal = false;
		}else{
			reels[i].bonVal = true;
		}
	}
}

//this outputs the array to a output file
void outputToFile(symbols array[10][3]){
	char userString[50];
	cout << "Enter a desired output filename: ";
	cin >> userString;
	
	ofstream fout (userString);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			outputStructToFile(array[i][j], fout);
			}
	}
	fout << endl;
} 
//randomly outputs the symbols to a 3D array
//changed part of this function
void populateSlots(symbols array[10][3], symbols reels[6]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			int x = rand()%6;
			stringCopy(array[i][j].icons, reels[x].icons);
			array[i][j].bonusValue = reels[x].bonusValue;
			array[i][j].bonVal = reels[x].bonVal; 	
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
void readFromOutput(symbols array[10][3]){
	char userString[50];
	cout << "Enter File name: ";
	cin >> userString;
	ifstream fin (userString);
	if(fin.good()){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 3; j++){
				fin >> array[i][j].icons;
				fin >> array[i][j].bonusValue;
				fin >> array[i][j].bonVal;
			}
		} 	
	}else{
		cout << "Error: Unknown File." << endl;
	}
}

//prints the outputted file values to the screen
void outputToScreen(symbols array[10][3]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			printStruct(array[i][j]);
		}
		cout << endl;
	}
} 

 
//lets the user choose a reel to stop on and display it.
void pickReel(symbols array[10][3]){
	int x;
	int y;
	do{
		cout << "Choose a which row (1-10) to stop on: ";
		cin >> x;
		cout << "Choose a stop (1-3) to stop on: ";
		cin >> y;
		if(x > 10 || x < 1){
			cout << "**Error: First number has to be (1-10)" << endl;
		}
		if(y > 3 || y < 1){
			cout << "**Error: Second number has to be (1-3)" << endl;
			cout << endl;
		}

	}while((x > 10 || x < 1) || (y > 3 || y < 1));
	cout << endl;
	printStruct(array[x-1][y-1]);
	cout << endl;
}

void rngStop(symbols array[10][3]){
	int x = rand()%10;
	int y = rand()%10;
	int z = rand()%10;
	printStruct(array[x][0]);
	printStruct(array[y][1]);
	printStruct(array[z][2]);
	cout << endl;
}

void printStruct(symbols pos){
	cout << pos.icons << " ";
	cout << "(" << pos.bonusValue << ")";
	cout << "(" << pos.bonVal << ")" << " ";
}

void outputStructToFile(symbols pos, ofstream &fout){
	fout << pos.icons << " ";
	fout << "(" << pos.bonusValue << ")";
	fout << "(" << pos.bonVal << ")" << " ";
}





