//test array based and node based lists
#include <iostream>
#include <cstdlib>
#include "listA.h"

using namespace std;

int main()
{

	char c = '\0';

	cout << "Create empty list - default***********"  << endl;
		List L10;
		cout << L10;

	 cout << "Check empty **********"  << endl;
	 	if( L10.empty() == true )
	 		cout << "empty" << endl;
	 	else
			cout << "not empty" << endl;

	cout << "Check full **********"  << endl;
		if( L10.full() == true )
			cout << "full" << endl;
		else
			cout << "not full" << endl;

	cout << "Try clear **********"  << endl;
		if( L10.clear() == true )
			cout << "cleared" << endl;
		else
			cout << "can't clear" << endl;

	cout << "Try remove **********"  << endl;
		if( L10.remove(c) == true )
			cout << "removed " << c << endl;
		else
			cout << "can't remove" << endl;

	cout << "gotoBeg **********"  << endl;
		if( L10.gotoBeginning() == true )
			cout << "at beginning" << c << endl;
		else
			cout << "can't move" << endl;

	cout << "gotoEnd **********"  << endl;
		if( L10.gotoEnd() == true )
			cout << "at end" << c << endl;
		else
			cout << "can't move" << endl;

	cout << "gotoNext **********"  << endl;
		if( L10.gotoNext() == true )
			cout << "moved to next" << c << endl;
		else
			cout << "can't move" << endl;

	cout << "gotoPrior **********"  << endl;
		if( L10.gotoPrior() == true )
			cout << "moved to prior" << c << endl;
		else
			cout << "can't move" << endl;

	cout << "***********************"  << endl;

	cout << "insert 10 times**********"  << endl;
		for (int i = 0; i < 10; ++i)
		{
			c = 'A'+i;

			L10.insert( c );
		}

		cout << L10;

	cout << "Check full **********"  << endl;
		if( L10.full() == true )
			cout << "full" << endl;
		else
			cout << "not full" << endl;

	cout << "Try remove **********"  << endl;
		if( L10.remove(c) == true )
			cout << "removed " << c << endl;
		else
			cout << "can't remove" << endl;

		cout << L10;

	cout << "gotoBeg **********"  << endl;
		if( L10.gotoBeginning() == true )
			cout << "at beginning"<< endl;
		else
			cout << "can't move" << endl;

		cout << L10;

	cout << "gotoEnd **********"  << endl;
		if( L10.gotoEnd() == true )
			cout << "at end" << endl;
		else
			cout << "can't move" << endl;

		cout << L10;

	cout << "gotoPrior 5 times**********"  << endl;
		for (int i = 0; i < 5; ++i)
		{
			if( L10.gotoPrior() == true )
				cout << "moved to prior"<< endl;
			else
				cout << "can't move" << endl;
		}

		cout << L10;

	cout << "gotoNext once**********"  << endl;
		if( L10.gotoNext() == true )
			cout << "moved to Next" << endl;
		else
			cout << "can't move" << endl;

		cout << L10;

	cout << "List L5( L10 ), cout L5**********"  << endl;
		List L5( L10 );

		cout << L5;

	cout << "L11 = L5, cout L11**********"  << endl;
		List L11( 11 );
		L11 = L5;

		cout << L11;

	cout << "Try clear **********"  << endl;
		if( L10.clear() == true )
			cout << "cleared"<< endl;
		else
			cout << "can't clear" << endl;

		cout << L10;

	cout << "check empty **********"  << endl;
		if( L10.empty() == true )
			cout << "empty"<< endl;
		else
			cout << "not empty" << endl;

	return 0;
}