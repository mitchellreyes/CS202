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

struct reel{
	symbols emblems[10];
	int bonus;
};

//function prototypes
void readFromFile(ifstream &fin, symbols *slotPtr);
void populateSlots(symbols *slotPtr, reel *config);
void outputStructToFile(reel *config, ofstream &fout);
void outputToFile(reel *config);
void readFromOutput(reel *config);
void printReels(reel *config);
void outputToScreen(reel *config);
void printStruct(reel *config, symbols *sPtr);
void pickReel(reel *config);
void payline(reel *config);
void stringCopy(char *dest, char *src);

int main(){
	srand(time(NULL));
	char nameFile[20];
	cout << "Please input a file name: ";
	cin >> nameFile;
	ifstream fin (nameFile);
	//initial declaration
	reel slots[3];
	reel *config = slots;
	symbols slotArray[6];
	symbols *slotPtr = slotArray;

	if(fin.good()){
		int x;
		do
		{
			readFromFile(fin, slotPtr);
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
					populateSlots(slotPtr, config);
					outputToFile(config);
					cout << endl;
					break;
				case 2:
					readFromOutput(config);
					break;
				case 3:
					cout << endl;
					printReels(config);
					cout << endl;
					break;
				case 4:
					pickReel(config);
					cout << endl;
					break;
				case 5:
					cout << endl;
					payline(config);
					cout << endl;
					break;
				default:
					cout << "Thanks for playing!" << endl << endl;
					break;
			}
		//change this to be consistent with the above values 
		} while (x != 6);
	}else{
		//error if the file isnt there
		cout << "Error: Unable to read file." << endl;
	}
	//closes the document
	fin.close();
return 0;
}



//this function reads in the characters and integers from the given file and put it into the struct
void readFromFile(ifstream &fin, symbols *slotPtr){
	symbols *temp = slotPtr;
	int i = 0;
	while(i != 6){
		fin >> (*slotPtr).icons;
		fin >> (*slotPtr).bonusValue;
		if((*slotPtr).bonusValue == 0){
			(*slotPtr).bonVal = false;
		}else{
			(*slotPtr).bonVal = true;
		}
		slotPtr++;
		i++;
	}
	slotPtr = temp;
}
//copies a string a src to a dest
void stringCopy(char *dest, char *src){
	int i = 0;
	char *temp = dest;
	char *tmp = src;
	while (*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	dest = temp;
	src = tmp;
}

//reads the symbols slotArray[6], randomly points to one, then copies the values into the emblems
void populateSlots(symbols *slotPtr, reel *config){
	symbols *temp = slotPtr;
	reel *garb = config;
	symbols *sPtr = (*config).emblems;
	for(int k = 0; k < 3; k++){
		for(int j = 0; j < 10; j++){
			for(int i = 0; i < rand()%6; i++){
				slotPtr++;
			}
		(*config).emblems[j] = (*slotPtr); //putting a struct into an array of structs?
		(*config).bonus = (*slotPtr).bonusValue;
		slotPtr = temp;
		}
	config++;
	}
	config = garb;
}

//outputs a single struct to a file 
void outputStructToFile(reel *config, ofstream &fout){
	symbols *sPtr = (*config).emblems;
	for(int i = 0; i < 10; i++){
		fout << (*sPtr).icons << " ";
		fout << "(" << (*sPtr).bonusValue << ")";
		fout << "(" << (*sPtr).bonVal << ")" << " " << endl;
		sPtr++;	
	}
}
//outputs all the values generated to a specified file
void outputToFile(reel *config){
	char userString[50];
	cout << "Enter a desired output filename: ";
	cin >> userString;
	reel *garb = config;
	ofstream fout (userString);
	for(int i = 0; i < 3; i++){
		outputStructToFile(config, fout);
		config++;
	}
	config = garb;
	fout << endl;
}
//reads a configuration made by the user
void readFromOutput(reel *config){
	char userString[50];
	reel *trash = config;
	cout << "Enter File name: ";
	cin >> userString;
	ifstream fin (userString);
	if(fin.good()){
		symbols *sPtr = (*config).emblems;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 10; j++){
				fin >> (*sPtr).icons;
				fin >> (*sPtr).bonusValue;
				fin >> (*sPtr).bonVal;
			}
			config++;
		} 	
	config = trash;
	}else{
		cout << "Error: Unknown File." << endl;
	}
}
//prints out the reels to the screen
void printReels(reel *config){
	symbols *sPtr = (*config).emblems;
	reel *temp = config;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			sPtr = (*config).emblems;
			for(int k = 0; k < i; k++){
				sPtr++;
			}
			cout << (*sPtr).icons << " ";
			cout << "(" << (*sPtr).bonusValue << ")";
			cout << "(" << (*sPtr).bonVal << ")" << " ";				
			config++;
		}
		config = temp;
		cout << endl;
	}
	config = temp;
	sPtr = (*config).emblems;
}

//prints out a single struct
void printStruct(reel *config, symbols *sPtr){
	cout << (*sPtr).icons << " ";
	cout << "(" << (*sPtr).bonusValue << ")";
	cout << "(" << (*sPtr).bonVal << ")" << " ";
}
//lets the user choose a reel
void pickReel(reel *config){
	int x;
	int y;
	reel* temp = config;
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
	for(int i = 1; i < y; i++){
		config++;
	}
	symbols *sPtr = (*config).emblems;
	for(int i = 1; i < x; i++){
		sPtr++;
	}
	cout << endl;
	printStruct(config, sPtr);
	cout << endl;
	config = temp;
	sPtr = (*config).emblems;
}
//gives the user a random payline
void payline(reel *config){
	symbols *sPtr = (*config).emblems;
	reel *temp = config;
	for(int i = 0; i < 3; i++){
		int x = rand()%10;
		for(int j = 0; j < x; j++){
			sPtr++;
		}
		printStruct(config, sPtr);
		config++;
		sPtr = (*config).emblems;
	}
	cout << endl;
}

