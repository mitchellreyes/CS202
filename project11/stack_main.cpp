/**************************** Header Files *****************************/
#include "Stack1.cpp"
#include <iostream>

using namespace std;

/******************** Global Variables and Constants ********************/
const int STACK_SIZE = 6;


/***************************** Main Program *****************************/
int main() 
{
	// declare variables
	int selection;
	char data;
	int numTestsPassed = 0;

	// create stacks
	cout << endl << endl << "Intialize character stack of size " << STACK_SIZE << endl << endl;
	Stack intStack(STACK_SIZE), copy;


	// Loop menu until quit
	do{
		// print out the menu
		cout << endl;
		cout << "1. Check Empty and Full when Stack is Empty" << endl;
		cout << "2. Push Multiple Data Items onto Stack" << endl;
		cout << "3. Check Assignment Operator" << endl;
		cout << "4. Check Compare Operator" << endl;
		cout << "5. Pop Values Until Stack is Empty" << endl;
		cout << "6. Push more values onto Stack" << endl;
		cout << "7. Clear Stack" << endl;
		cout << "8. Test Copy Constructor" << endl;
		cout << "9. Quit Program" << endl << endl;

		// prompt user for menu option
		cout << "Please select an option: ";
		cin >> selection;

		cout << endl << endl << "****************************************" << endl << endl;

		// process menu option
		switch(selection)
			{
				// Check Empty and Full when Stack is Empty
				case 1:
					// set number of tests passed to zero
					numTestsPassed = 0;

					// print out test 
					cout << "Checking Empty and Full when Stack is Empty" << endl;
					cout << "===========================================" << endl << endl;

					// check if empty (should be empty)
					if(!intStack.empty()) 
					{
						cout << "ERROR: in empty() (says not empty when it is empty)" << endl;
					}
					else
					{
						cout << "Stack is EMPTY" << endl;
						numTestsPassed ++;
					}

					// check if full (should not be full)
					if(intStack.full()) 
					{
						cout << "ERROR: in full() (says full when it is not full)" << endl;
					}
					else
					{
						cout << "Stack is NOT FULL" << endl;
						numTestsPassed ++;
					}

					cout << endl << "Passed " << numTestsPassed << " out of 2 tests" << endl;


				break;

				case 2:
					// set number of tests passed to zero
					numTestsPassed = 0;

					// print out test 
					cout << "Push Multiple Data Items onto Stack" << endl;
					cout << "===================================" << endl << endl;
					cout << "Pushing Data: " << endl;

					// push multiple data items on the stack		
					for(int i = 0; i < STACK_SIZE; i++) 
						{			
							cout << "Push " << i << " - ";

							// check push
							if(!intStack.push(i + '0')) 
							{
								cout << "Failed" << endl;
							}
							else
							{
								cout << "Success" << endl;
								numTestsPassed ++;
							}
						}

					cout << endl << "Checking Empty and Full: " << endl;

					// check if stack is full
					if(!intStack.full()) 
					{
						cout << "ERROR: in full (says not full when it is full)" << endl;
					}
					else
					{
						cout << "Stack is FULL" << endl;
						numTestsPassed ++;
					} 

					// check empty
					if(intStack.empty()) 
					{
						cout << "ERROR: in empty (says empty when it is not empty)" << endl;
					}
					else
					{
						cout << "Stack is NOT EMPTY" << endl;
						numTestsPassed ++;
					} 

					cout << endl << "Pushing on Full: " << endl;

					// check overflow
					cout << "Push -1 (overflow)" << endl;
					if(intStack.push(-1)) 
					{
						cout << "ERROR: pushed when stack is full" << endl;
					}
					else
					{
						cout << "Push failed - Stack is full" << endl << endl;
						numTestsPassed ++;
					}

					// check print
					cout << "Start print function:" << endl << endl;
					cout << intStack << endl;
					cout << endl << "End print function" << endl;

					cout << endl << "Passed " << numTestsPassed << " out of 9 tests" << endl;


				break;

				case 3:
	
					// print out test 
					cout << "Checking Assignment Operator" << endl;
					cout << "============================" << endl << endl;

					// assignment operator
					copy = intStack;

					// print stacks
					cout << "Copied Stack: " << endl;
					cout << copy << endl << endl;

					cout << "Original Stack: " << endl;
					cout << intStack << endl << endl;

					cout << endl << "The two stacks should match" << endl;


				break;


				case 4:
					numTestsPassed = 0;

					// print out test 
					cout << "Check Comparison Operator" << endl;
					cout << "=========================" << endl << endl;

					// check if the same
					if(!(intStack == copy)) 
					{
						cout << "Error in == operator (says not equal when they are)" << endl;
					}
					else
					{
						cout << "Stacks are EQUAL" << endl;
						numTestsPassed ++;
					}

					cout << endl << "Removing one data item from copy stack" << endl;
					copy.pop(data);
					if(intStack == copy) 
					{
						cout << "Error in == operator (says equal when they are not)" << endl;
					}
					else
					{
						cout << "Stacks are NOT EQUAL" << endl;
						numTestsPassed ++;
					}

					cout << endl << "Passed " << numTestsPassed << " out of 2 tests" << endl;

				break;


				case 5:

					numTestsPassed = 0;

					// print out test 
					cout << "Pop Values Until Stack is Empty" << endl;
					cout << "===============================" << endl << endl;
					cout << "Popping Data: " << endl;

					// pop multiple data items on the stack		
					for(int i = STACK_SIZE - 1; i >= 0; i--) 
						{			
							cout << "Pop " << i << " - ";

							if(intStack.pop(data)) 
							{
								cout<< "Success" << endl << "Popped " << data << endl;
								numTestsPassed ++;
							} 
							else 
							{
								cout << "Failed" << endl;
							}
						}

					cout << endl << "Checking Empty and Full: " << endl;

					// check if stack is full
					if(intStack.full()) 
					{
						cout << "ERROR: in full (says full when it is not full)" << endl;
					}
					else
					{
						cout << "Stack is NOT FULL" << endl;
						numTestsPassed ++;
					} 

					// check empty
					if(!intStack.empty()) 
					{
						cout << "ERROR: in empty (says not empty when it is empty)" << endl;
					}
					else
					{
						cout << "Stack is EMPTY" << endl;
						numTestsPassed ++;
					} 

					cout << endl << "Popping on Empty: " << endl;

					// check overflow
					cout << "Pop (underflow)" << endl;
					if(intStack.pop(data)) 
					{
						cout << "ERROR: popped when stack is empty" << endl;
					}
					else
					{
						cout << "Pop failed - Stack is Empty" << endl << endl;
						numTestsPassed ++;
					}

					// check print
					cout << "Start print function:" << endl << endl;
					cout << intStack << endl;
					cout << endl << "End print function" << endl;

					cout << endl << "Passed " << numTestsPassed << " out of 9 tests" << endl;

				break;


				case 6:
					// set number of tests passed to zero
					numTestsPassed = 0;

					// print out test 
					cout << "Push More Data Items onto Stack" << endl;
					cout << "===============================" << endl << endl;
					cout << "Pushing Data: " << endl;

					// push multiple data items on the stack		
					for(int i = 0; i < STACK_SIZE/2; i++) 
						{			
							cout << "Push " << i << " - ";

							// check push
							if(!intStack.push(i + '0')) 
							{
								cout << "Failed" << endl;
							}
							else
							{
								cout << "Success" << endl;
								numTestsPassed ++;
							}
						}

					cout << endl << "Checking Empty and Full: " << endl;

					// check if stack is full
					if(intStack.full()) 
					{
						cout << "ERROR: in full (says full when it is not full)" << endl;
					}
					else
					{
						cout << "Stack is NOT FULL" << endl;
						numTestsPassed ++;
					} 

					// check empty
					if(intStack.empty()) 
					{
						cout << "ERROR: in empty (says empty when it is not empty)" << endl;
					}
					else
					{
						cout << "Stack is NOT EMPTY" << endl;
						numTestsPassed ++;
					}

					cout << endl << "Passed " << numTestsPassed << " out of 5 tests" << endl;

				break;


				case 7:
					// set number of tests passed to zero
					numTestsPassed = 0;

					// print out test 
					cout << "Clear the Stack" << endl;
					cout << "===============" << endl << endl;

					// clear the stack
					if(!intStack.clear()) 
					{
						cout << "ERROR while clearing stack" << endl;
					}

					if(!intStack.empty()) 
					{
						cout << "ERROR, stack is not empty after clear" << endl;
					}
					else
					{
						numTestsPassed++;
					}

					cout << "Start print function:" << endl << endl;
					cout << intStack << endl;
					cout << endl << "End print function" << endl;	

					cout << endl << "Passed " << numTestsPassed << " out of 1 tests" << endl;

				break;

				case 8:
				{
					// print out test 
					cout << "Checking Copy Constructor" << endl;
					cout << "=========================" << endl << endl;

					// assignment operator
					Stack copy2 = copy;

					// print stacks
					cout << "Copied Stack: " << endl;
					cout << copy2 << endl << endl;

					cout << "Original Stack: " << endl;
					cout << copy << endl << endl;

					cout << endl << "The two stacks should match" << endl;
				}



				break;
			}
				cout  << endl << "****************************************" << endl;

	}
	while(selection != 9);

	return 0;
}