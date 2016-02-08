#include "class.h"

int main()
{
	Student tempStudent;
	Employee tempEmployee;
	ifstream fin;
	fin.open("persons");
	char tempChar;
	char* tempWord = new char[50];
	int tempInt = -1;
	int* tempArrInt = new int[10];
	double tempDbl = -1.0;
	for(int i = 0; i < 13; i++)
	{
		fin >> tempChar;
		switch (tempChar)
		{
			case 's':
				fin.get();
				fin.getline(tempWord, 51, ':');
				tempStudent.setFirstName(tempWord);
				fin.getline(tempWord, 51, ':');
				tempStudent.setLastName(tempWord);
				fin >> tempInt;
				tempStudent.setAge(tempInt);
				fin.get();
				for(int j = 0; j < 9; j++)
				{
					fin >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempStudent.setSSN(tempArrInt);
				fin.get();
				for(int j = 0; j < 10; j++)
				{
					fin >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempStudent.setNsheNumber(tempArrInt);
				fin.get();
				fin.get(tempWord, 51, ':');
				tempStudent.setMajor(tempWord);
				fin.get();
				fin >> tempDbl;
				tempStudent.setGpa(tempDbl);
				tempStudent.print();
				break;
			case 'e':
				fin.get();
				fin.getline(tempWord, 51, ':');
				tempEmployee.setFirstName(tempWord);
				fin.getline(tempWord, 51, ':');
				tempEmployee.setLastName(tempWord);
				fin >> tempInt;
				tempEmployee.setAge(tempInt);
				fin.get();
				for(int j = 0; j < 9; j++)
				{
					fin >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempEmployee.setSSN(tempArrInt);
				fin.get();
				for(int j = 0; j < 5; j++)
				{
					fin >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempEmployee.setEmployeeNumber(tempArrInt);
				fin.get();
				fin.get(tempWord, 51, ':');
				tempEmployee.setTitle(tempWord);
				fin.get();
				fin >> tempInt;
				tempEmployee.setSalary(tempInt);
				tempEmployee.print();
				break;
		}
		cout << endl;
	}
	return 0;
}