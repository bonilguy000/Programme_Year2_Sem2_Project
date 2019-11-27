#ifndef ReadFile_h
#define ReadFile_h
//test
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string readFile() {
	string userInput;
	string tempString = "";
	cout << "Please input filename: ";
	cin >> userInput;
	ifstream inputFile(userInput);

	while (!inputFile.good()) {
		cout << "File name is wrong, please input again: ";
		cin >> userInput;
		inputFile.open(userInput);
	}

	while ((!inputFile.eof())) {
		string str;
		getline(inputFile, str);
		tempString += str;
	}

	return tempString;
}
int count() {
	readFile();
	int total=0;
	ifstream filename;
	filename.open("DS_10K.txt");

	while(!filename.eof()){
		getline(filename);
		total++;
	}
	return total;
	filename.close();
}






#endif
