#ifndef ReadFile_h
#define ReadFile_h

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

#endif
