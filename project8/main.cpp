#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "playerclass.h"

using namespace std;

void shuffle(card* shufDeck);
void deal(card* shufDeck, int numPlayers, player* gameOfPlayers, int &topCard);

int main(){
	ifstream fin;
	srand(time(NULL));
	fin.open("cardfile");
	card* unshufDeck = new card[52];
	card* shufDeck = new card[52];
	for(int i = 0; i < 52; i++){
		fin >> unshufDeck[i];
		shufDeck[i] = unshufDeck[i];
		shufDeck[i].setLocation("shuffled");
	}
	fin.close();
	fin.open("playerfile");
	int numPlayers;
	cout << "How many players want to play?(2-8): ";
	cin >> numPlayers;
	player* gameOfPlayers = new player[numPlayers];
	for(int i = 0; i < numPlayers; i++){
		fin >> gameOfPlayers[i];
	}
	shuffle(shufDeck);
	fin.close();
	int topCard = 0;
	int randIndex = 0;
	int randIndex2 = 0;
	int x;
	do{
		do{
			cout << endl;
			cout << "1. Reshuffle and/or Deal Cards" << endl;
			cout << "2. Print UNSHUFFLED Deck" << endl;
			cout << "3. Print SHUFFLED Deck" << endl;
			cout << "4. Print Stock Deck and Discard Pile" << endl;
			cout << "5. Print Player Info" << endl;
			cout << "6. Test Other Functions" << endl;
			cout << "7. Quit" << endl;
			cout << "Choose a option from the menu above: ";
			cin >> x;
			cout << endl;
		}while(x < 0 && x > 7);
			switch(x){
				case 1:
					if(topCard != 0){
						topCard = 0;
						shuffle(shufDeck);
					}
					deal(shufDeck, numPlayers, gameOfPlayers, topCard);
					break;
				case 2:
					cout << "+++++++++++++++++++++++++++" << endl << "Unshuffled Deck" << endl 
						<< "+++++++++++++++++++++++++++" << endl;
					for(int i = 0; i < 52; i++){
						cout << unshufDeck[i] << endl;
					}
					break;
				case 3: 
					cout << "+++++++++++++++++++++++++++" << endl << "Shuffled Deck" << endl 
						<< "+++++++++++++++++++++++++++" << endl;
					for(int i = 0; i < 52; i++){
						cout << shufDeck[i] << endl;
					}
					cout << endl;
					break;
				case 4: 
					cout << "+++++++++++++++++++++++++++" << endl << "Stock Deck" << endl 
						<< "+++++++++++++++++++++++++++" << endl;
					cout << endl << "[discard]" << shufDeck[topCard] << endl << endl;
					for(int i = topCard+1; i < 52; i++){
						cout << "[stock]" << shufDeck[i] << endl;
					}
					cout << endl;
					break;
				case 5:
					for(int i = 0; i < numPlayers; i++){
						cout << gameOfPlayers[i];
					}
					break;
				case 6:
					if(randIndex == 0 && randIndex2 == 0){
						randIndex = rand()%52;
						randIndex2 = rand()%52;
					}
					cout<< "[Testing '<' overloaded operator]" << endl;
					if(unshufDeck[randIndex] < unshufDeck[randIndex2] == true){
						cout << "It's true that: " << unshufDeck[randIndex] << " < " 
						<< unshufDeck[randIndex2] << endl;
					}else{
						cout << "It's false that: " << unshufDeck[randIndex] << " < " 
						<< unshufDeck[randIndex2] << endl;
					}
					cout << endl;
					cout<< "[Testing '>' overloaded operator]" << endl;
					if(unshufDeck[randIndex] > unshufDeck[randIndex2] == true){
						cout << "It's true that: " << unshufDeck[randIndex] << " > " 
						<< unshufDeck[randIndex2] << endl;
					}else{
						cout << "It's false that: " << unshufDeck[randIndex] << " > " 
						<< unshufDeck[randIndex2] << endl;
					}
					randIndex = 0;
					randIndex2 = 0;
					break;
				default:
					cout << "Thanks." << endl << endl;
					break;
			}
		}while(x != 7);
		delete[]unshufDeck;
		delete[]shufDeck;
		delete[]gameOfPlayers;
return 0;	
}

void shuffle(card* shufDeck){
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 52; j++){
			int k = rand()%52;
			card temp(shufDeck[j]); //testing copy constructor
			shufDeck[j] = shufDeck[k]; //overload assignment operator
			shufDeck[k] = temp;
		}
	}
 
}

void deal(card* shufDeck, int numPlayers, player* gameOfPlayers, int &topCard){
	card* temp;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < numPlayers; j++){
			temp = gameOfPlayers[j].getHand();
			temp[i] = shufDeck[topCard];
			topCard++;
			temp[i].setLocation(gameOfPlayers[j].getName());
		}
	}
}

