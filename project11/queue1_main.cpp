#include "queue1.cpp"
#include <iostream>

using namespace std;

int main(){
	//initial creation of a queue
	Queue testQ(10);
	//checking the empty and full functions
	cout << "Checking Empty and Full when Stack is Empty" << endl;
		if(!testQ.empty()){
			cout << '\t' << "this Queue is not empty on creation." << endl;
			cout << '\t' << "empty is not working" << endl;
		}
		if(testQ.full()){
			cout << '\t' << "this Queue should not be full on creation" << endl;
			cout << '\t' << "Says the queue is full on creation?" << endl;
		}
		if(testQ.empty() && !testQ.full()){
			cout << '\t' << "This queue is empty and NOT full" << endl;
			cout << '\t' << "Passes 2 out of 2 tests" << endl;
		}
	//checking the push function
	cout << "Enqueuing data into the queue" << endl;
		for(int i = 0; i < 10; i++){
			testQ.enqueue(i);
		}
		cout << '\t' << testQ << endl;
		if(testQ.full()){
			cout << "the queue is now full" << endl;
		}
	//checking the assignment operator
	
	return 0;
}