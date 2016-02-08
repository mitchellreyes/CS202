#include "playerclass.h"

int stringToInt(string cardRank);

card::card(string su, string ra, string lo){
	suit = su;
	rank = ra;
	location = lo;
}

card::card(const card&c){
	if(this != &c){
		*this = c;
	}
}

void card::setLocation(string input){
	location = input;
}

card::~card(){
	suit = "suit";
	rank = "rank";
	location = "location";
}

card& card::operator=(const card&c){
	suit = c.suit;
	rank = c.rank;
	location = c.location;
}

bool card::operator<(const card&c){
	if(stringToInt(this->rank) == stringToInt(c.rank)){
		cout << "The two cards are equal in rank" << endl;
	}
	if(stringToInt(this->rank) < stringToInt(c.rank)){
		return true;
	}else{
		return false;
	}
}

bool operator>(const card&c1,const card&c2){
	if(stringToInt(c1.rank) == stringToInt(c2.rank)){
		cout << "The two cards are equal in rank" << endl;
	}
	if(stringToInt(c1.rank) > stringToInt(c2.rank)){
		return true;
	}else{
		return false;
	}
}

ifstream& operator>>(ifstream& fin, card&c){
	fin >> c.suit;
	fin >> c.rank;
	c.location = "unshuffled";
}

ostream& operator<<(ostream& out, card&c){
	out << c.suit << " " << c.rank << " " << c.location;
}

player::player(string identity,float money){
	name = identity;
	bet = money;
	hand = new card[5];
}

player::~player(){
	name = "first last";
	bet = 0.0;
	if(hand != NULL){
		delete[]hand;
	}
}

card* player::getHand(){
	return hand;
}

string player::getName(){
	return name;
}

ostream& operator<<(ostream&out, player&p1){
	out << "[" << p1.name << "]" << endl;
	for(int i = 0; i < 5; i++){
		out << '\t' << p1.hand[i] << endl;
	}
	out << "Bet: " << p1.bet << endl;
}

ifstream& operator>>(ifstream&in, player&p1){
		string temp;
		string actualName;
		in >> actualName;
		in >> temp;
		p1.name = actualName + " " + temp;
}

int stringToInt(string cardRank){
	if(cardRank == "two"){
		return 2;
	}
	if(cardRank == "three"){
		return 3;
	}
	if(cardRank == "four"){
		return 4;
	}
	if(cardRank == "five"){
		return 5;
	}
	if(cardRank == "six"){
		return 6;
	}
	if(cardRank == "seven"){
		return 7;
	}
	if(cardRank == "eight"){
		return 8;
	}
	if(cardRank == "nine"){
		return 9;
	}
	if(cardRank == "ten"){
		return 10;
	}
	if(cardRank == "jack"){
		return 11;
	}
	if(cardRank == "queen"){
		return 12;
	}
	if(cardRank == "king"){
		return 13;
	}
	if(cardRank == "ace"){
		return 1;
	}
}