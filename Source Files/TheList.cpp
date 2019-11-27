#include <iostream>
#include "RecordHash.h"
#include "TheList.h"
void TheList::printTheList() {

}
void TheList::insertList() {
	HashMap List;
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
	string ID, Job_Title, Email, Last_Name, First_Name, Phone_Num, Skills, Country;
	while (inputFile >> ID >> Job_Title >> Email >> Last_Name >> First_Name >> Phone_Num >> Skills >> Country) {
		stringstream x(Phone_Num);
		int key = 0;
		x >> key;
	}
}