#include <iostream>
using namespace std;

class person{
	public:
		person();
		~person();
		void setFirstName(char*);
		void setLastName(char*);
		void setAge(int);
		void setSsn(int*);
		void printPerson();
		char* getFirstName();
		char* getLastName();
		int* getSSN();
		int getAge();
	protected:
		char* firstname;
		char* lastname;
		int age;
	private:
		int* ssn;

};

class employee:public person(){
	public:
		employee();
		~employee();
		void printEmployee();
		void setEmpNum(int);
		void setTitle(char*);
		void setSalary(int);
		int getEmpNum();
		char* getTitle();
		int getSalary();
	private:
		int empNum;
		char* title;
		int salary;
};

class student:public person(){
	public:
		student();
		~student();
		void printStudent();
		void setNSHE(int*);
		void setMajor(char*);
		void setGPA(double);
		int* getNSHE();
		char* getMajor();
		double getGPA();
	private:
		int* nshe;
		char* major;
		double gpa;
};

