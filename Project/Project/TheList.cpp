#include <iostream>
#include <fstream>
#include <sstream>
#include "RecordHash.h"
#include "TheList.h"
long TABLE_SIZE;
HashMap::HashMap() { //Create a new hash table
	cout << "Please input the number of records you will insert:";
	cin >> TABLE_SIZE;
	table = new RecordHashEntry*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		table[i] = NULL;
}
string HashMap::get(int key) { //Get a record from the hash based on what key is given
	int hash = (key % TABLE_SIZE);
	while (table[hash] != NULL && table[hash]->getKey() != key)
		hash = (hash + 1) % TABLE_SIZE;
	if (table[hash] == NULL)
		return NULL;
	else
		return table[hash]->getRecord();
}
// Insert a new record
void HashMap::put(int key, string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country) {
	int hash = key % TABLE_SIZE;
	while (table[hash] != NULL && table[hash]->getKey() != key) // To avoid collision,the programme find another location with calculation(open addressing(closed hashing)
		hash = (hash + 1) % TABLE_SIZE;
	if (table[hash] != NULL) // Or if the keys are the same but a new record is being inserted, remove the previous record
		delete table[hash];
	table[hash] = new RecordHashEntry(key, iD, job_Title, email, last_Name, first_Name, phone_Num, skills, country); // Finally the record is inserted
}
HashMap::~HashMap() { // Deconstructor for hash table
	for (int i = 0; i < TABLE_SIZE; i++)
		if (table[i] != NULL)
			delete table[i];
	delete[] table;
}

void insertList() {
	HashMap List;
	int num = 0, key = 0;
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
		x >> num;

		while (num != 0) {
			key = key + num % 10;
			num = num / 10;
		}
		List.put(key, ID, Job_Title, Email, Last_Name, First_Name, Phone_Num, Skills, Country);
	}









}