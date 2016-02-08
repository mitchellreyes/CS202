#include "class.h"

Person::Person(const char* firstName, const char* lastName, int age, int* ssn){
	//gets a deep copy of name
	this->firstName = new char[strlen(firstName)];
	strcpy(this->firstName, firstName);
	this->lastName = new char[strlen(lastName)];
	strcpy(this->lastName, lastName);
	this->age = age;
	this->ssn = new int[9];
	if(ssn != NULL){
		for(int i = 0; i < 9; i++){
			this->ssn[i] = ssn[i];
		}
	}
}

Person::~Person(){
	if(firstName != NULL){
		delete[] firstName;
	}
	firstName = NULL;
	if(lastName != NULL){
		delete[] lastName;
	}
	lastName = NULL;
	age = -1;
	if(ssn != NULL){
		delete[] ssn;
	}
	ssn = NULL;
}

bool Person::setFirstName(char* firstName){
	if(this->firstName != NULL){
		delete[] this->firstName;
	}
	this->firstName = new char[strlen(firstName)];
	strcpy(this->firstName, firstName);
	return true;
}

bool Person::setLastName(char* lastName){
	if(this->lastName != NULL){
		delete[] this->lastName;
	}
	this->lastName = new char[strlen(lastName)];
	strcpy(this->lastName, lastName);
	return true;
}

bool Person::setAge(int age){
	if(age < 0){
		return false;
	}
	this->age = age;
	return true;
}

bool Person::setSSN(int* ssn){
	for(int i = 0; i < 9; i++){
		this->ssn[i] = ssn[i];
	}
	return true;
}

char* Person::getFirstName(){
	return firstName;
}

char* Person::getLastName(){
	return lastName;
}

int Person::getAge(){
	return age;
}

int* Person::getSSN(){
	return ssn;
}

void Person::print(){
	cout << firstName << " " << lastName << " (" << age << ") [";
	for(int i = 0; i < 9; i++){
		cout << ssn[i];
	}
	cout << "]" << endl;
}

Employee::Employee(const char* firstName, const char* lastName, int age, int* ssn, int* employeeNumber, 
	const char* title, int salary):Person(firstName, lastName, age, ssn){
	this->employeeNumber = new int[5];
	if(employeeNumber != NULL){
		for(int i = 0; i < 5; i++){
			this->employeeNumber[i] = employeeNumber[i];
		}
	}
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	this->salary = salary;
}

Employee::~Employee(){
	if(employeeNumber != NULL){
		delete[] employeeNumber;
	}
	employeeNumber = NULL;
	if(title != NULL){
		delete[] title;
	}
	title = NULL;
	salary = -1;
}

bool Employee::setEmployeeNumber(int* employeeNumber){
	for(int i = 0; i < 5; i++){
		this->employeeNumber[i] = employeeNumber[i];
	}
	return true;
}

bool Employee::setTitle(char* title){
	if(this->title != NULL){
		delete[] this->title;
	}
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	return true;
}

int* Employee::getEmployeeNumber(){
	return employeeNumber;
}

bool Employee::setSalary(int salary){
	this->salary = salary;
	return true;
}


char* Employee::getTitle(){
	return title;
}

int Employee::getSalary(){
	return salary;
}

void Employee::print(){
	Person::print();
	cout << "\t" << title << " #";
	for(int i = 0; i < 5; i++){
		cout << employeeNumber[i];
	}
	cout << " $" << salary << endl;
}

Student::Student(const char* firstName, const char* lastName, int age, int* ssn, int* nsheNumber,
 const char* major, double gpa):Person(firstName, lastName, age, ssn){
	this->nsheNumber = new int[10];
	if(nsheNumber != NULL){
		for(int i = 0; i < 10; i++){
			this->nsheNumber[i] = nsheNumber[i];
		}
	}
	this->major = new char[strlen(major)];
	strcpy(this->major, major);
	this->gpa = gpa;
}

Student::~Student(){
	if(nsheNumber != NULL){
		delete[] nsheNumber;
	}
	nsheNumber = NULL;
	if(major != NULL){
		delete[] major;
	}
	major = NULL;
	gpa = -1.0;
}

bool Student::setNsheNumber(int* nsheNumber){
	for(int i = 0; i < 10; i++){
		this->nsheNumber[i] = nsheNumber[i];
	}
	return true;
}

bool Student::setMajor(char* major){
	if(this->major != NULL){
		delete[] this->major;
	}
	this->major = new char[strlen(major)];
	strcpy(this->major, major);
	return true;
}

bool Student::setGpa(double gpa){
	this->gpa = gpa;
	return true;
}

int* Student::getNsheNumber(){
	return nsheNumber;
}

char* Student::getMajor(){
	return major;
}

double Student::getGpa(){
	return gpa;
}

void Student::print(){
	Person::print();
	cout << "\t" << major << " #";
	for(int i = 0; i < 10; i++){
		cout << nsheNumber[i];
	}
	cout << ", " << gpa << endl;
}