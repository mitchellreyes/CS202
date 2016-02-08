#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class card{
	public:
		card(string = "suit", string = "rank", string = "location");
		card(const card&);
		void setLocation(string input);
		~card();
		card& operator=(const card&);
		bool operator<(const card&);

		friend bool operator>(const card&, const card&);
		friend ifstream& operator>>(ifstream&, card&);
		friend ostream& operator<<(ostream&, card&);

	private:
		string suit;
		string rank;
		string location;
};

class player{
	public:
		player(string = "first last",float = 0.0);
		~player();
		card* getHand();
		string getName();

		friend ifstream& operator>>(ifstream&, player&);
		friend ostream& operator<<(ostream&, player&);
	private:
		string name;
		card* hand = NULL;
		float bet;
};