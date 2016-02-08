#include "listnode.cpp"
#include <iostream>

using namespace std;

int main(){
	List testL;
	cout << "[Testing empty and full]" << endl;
		cout << '\t' << "'cout << list'" << testL << endl;
		if(testL.empty()){
			cout<< '\t' << "The list is empty..." << endl;
		}
		if(!testL.full()){
			cout << '\t' << "The list is also NOT full..." << endl;
		}
		if(!testL.empty()){
			cout << '\t' << "Something went wrong with empty..." << endl;
		}
		if(testL.full()){
			cout << '\t' << "It's saying it's full on creation..." << endl;
		}
	cout << "[Testing insert operator]: " << endl;
		cout << '\t' << "->Before: " << testL << endl;
		for(int i = 0; i < 8; i++){
			testL.insert('c'+i);
		}
		cout << "->After: " << testL << endl;
	cout << "[Testing assignment operator]: " << endl;
		List testL2;
		testL2 = testL;

		cout << "[First List]: " << testL << endl;
		cout << "[Assigned List]: " << testL2 << endl;
		cout << '\t' << "Should be the same." << endl;

		testL.clear();
		testL2 = testL;

		cout << "[First List]: " << testL << endl;
		cout << "[Assigned List]: " << testL2 << endl;
		cout << '\t' << "Should still be the same." << endl;

	cout << "[testing my gotoBeginning and gotoEnd]: " << endl;
		for(int j = 0; j < 12; j++){
			testL.insert('e'+j);
		}
		cout << "*going to the end*" << endl;
		if(testL.gotoEnd()){
			cout << "the cursor is now at the end of the list" << endl;
		}
		cout << "--If my gotoEnd worked, I cant gotoNext" << endl;
		if(!testL.gotoNext()){
			cout << '\t' << "Yup, my gotoEnd function worked." << endl;
		}
		testL.gotoBeginning();
		cout << "***Put the cursor to the beginning of the list" << endl;
		cout << "--Now my gotoNext function should work" << endl;
		if(testL.gotoNext()){
			cout << '\t' << "Yup, gotoBeginning worked." << endl;
		}

	cout<< "[Testing more insertion operators]: " << endl;
		testL.clear();
		for(int j = 0; j < 12; j++){
			testL.insert('a'+j);
		}
		testL.insert('z');
		cout << testL << endl;
		cout << "***inserted 'z'" << endl;

	cout<< "[Testing remove until empty]: " << endl;
		char a;
		int i = 1;
		while(!testL.empty()){
			testL.remove(a);
			cout << "removed: " << i << " elements" << endl;
			i++;
		}
		if(testL.empty()){
			cout << "**removed until empty" << endl;
			cout << "see: " << testL << endl;
		}

	cout << "[Testing copy constructor and inserting more values]"
		<< endl;

		for(int y = 0; y < 15;y++){
			testL.insert('a'+y);
		}
		List testLcpy(testL);
		cout << "[original]" << testL << endl;
		cout << "[copied]" << testLcpy << endl;

		cout << "should be the same" << endl;

	cout << "[testing gotoPrior]: " << endl;
	if(testL.gotoPrior()){
		cout << "successfully moved to prior" << endl;
	}
	cout << '\t' << "clearing the list..." << endl;
	testL.clear();
	cout << "[testing gotoPrior now]: " << endl;
	if(!testL.gotoPrior()){
		cout<< "cannot go to prior because its empty" << endl;
	}
	cout << "[Testing one element print]: " << endl;
	testL.insert('a');
	cout << testL << endl;
	return 0;
}