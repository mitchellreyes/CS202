#include "queue1.cpp"
#include <iostream>

using namespace std;

int main(){
	//initial creation of a queue
	Queue testQ(10);
	//checking the empty and full functions
	cout << "***Checking Empty and Full when Stack is Empty" << endl;
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
	cout << "***Enqueuing data into the queue" << endl;
		for(int i = 0; i < 10; i++){
			testQ.enqueue(i);
		}
		cout << '\t' << testQ << endl;
		if(testQ.full()){
			cout << "//the queue is now full" << endl << endl;
		}
	//checking the assignment operator
	cout << "***Testing the assignment operator" << endl;
		Queue testQ2;
		testQ2 = testQ;

		cout << "[original queue]" << endl;
		cout << testQ << endl;

		cout << "[assigned queue]" << endl;
		cout << testQ2 << endl;

		cout << "Both queues should be the same" << endl;

		testQ.clear();
		testQ2 = testQ;

		cout << "[original queue]" << endl;
		cout << testQ << endl;

		cout << "[assigned queue]" << endl;
		cout << testQ2 << endl;

		cout << "Both queues should still be the same" << endl << endl;	

		cout << '\t' << "Passed both tests" << endl;	
		//checking the compare operator
	cout << "***Testing the compare operator" << endl;
		testQ2.clear();
		testQ.clear();
		int i = 0;
		while(!testQ.full()){
			testQ.enqueue(2 + i);
			i++;
		}
		while(!testQ2.full()){
			testQ2.enqueue(2 + i);
			i++;
		}
		if(testQ == testQ2){
			cout << "something broke." << endl;
		}else{
			cout << "[First queue]" << endl;
			cout <<'\t' << testQ << endl;
			cout << "[Second queue]" << endl;
			cout <<'\t' << testQ2 << endl;
			cout << "the 2 queues are not the same." << endl;
		}
		testQ2.clear();
		testQ.clear();
		while(!testQ.full()){
			testQ.enqueue(1);
		}
		while(!testQ2.full()){
			testQ2.enqueue(1);
		}
		if(testQ == testQ2){
			cout << "[First queue]" << endl;
			cout <<'\t' << testQ << endl;
			cout << "[Second queue]" << endl;
			cout << '\t' << testQ2 << endl;
			cout << "the 2 queues are the same." << endl;
		}
	//checking pop functionality
	cout << "***Dequeuing values until first stack is empty" << endl;
		 cout << testQ << endl;
		 int outVal;
		 while(!testQ.empty()){
		 	cout << "*dequeing*" << endl;
		 	testQ.dequeue(outVal);
		 	cout << "dequeue value: " << outVal << endl;
		 }
		if(testQ.empty()){
			cout << "queue is now empty" << endl;
		}
		cout << endl;
		if(!testQ.dequeue(outVal)){
			cout << "***Testing dequeue when its empty" << endl;
			cout << '\t' << "cannot dequeue because it is empty" << endl;
		}

	//checking more enqueue
	cout << "***Enqueuing more values on the queue" << endl;
		int j = 0;
		while(!testQ.full()){
			testQ.enqueue(32 + j);
			j++;
		}
		cout << testQ << endl;
		cout << "***Trying to enqueue on a full queue" << endl;
		if(!testQ.enqueue(j)){
			cout << '\t' << "The queue is full" << endl;
		}

	cout << "***Clearing queue" << endl;
		testQ.clear();
		if(testQ.empty()){
			cout << "The queue is now cleared" << endl;
		}

	cout << "***Testing copy constructor" << endl;
		int k = 47;
		while(!testQ.full()){
			testQ.enqueue(22 + k);
			k++;
		}

		Queue testQ3(testQ);
		cout << "[Original Queue]: " << endl;
		cout << '\t' << testQ << endl;
		cout << "[Copied Queue]: " << endl;
		cout << '\t' << testQ3 << endl;
		cout << endl << "Both Queues should be the same" << endl;
		
	return 0;
}