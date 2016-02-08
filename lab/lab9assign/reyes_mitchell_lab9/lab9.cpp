#include <iostream>
#include <stdexcept>
#include <exception>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	try{
		if(argc > 2){
			throw runtime_error("Invalid number of arguments");
		}
		ifstream fin(argv[1]);
		if(fin.good()){
			for(int i = 0; i < 13; i++){
				char garbage[20];
				fin >> garbage;
				cout << garbage << " ";
			}
			cout << endl;
		}else{
			throw runtime_error("Could not open file");
		}

	}
	catch(runtime_error error){
		cout << error.what() << endl;
	}
	return 0;
}

