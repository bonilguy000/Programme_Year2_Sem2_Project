#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef RECORDHASH_H
#define RECORDHASH_H

class Hash {
private:
	static const int tableSize = 100000;

	struct Person {
		string ID;
		string Job_Title;
		string Email;
		string Last_Name;
		string First_Name;
		string Phone_Number;
		string Skills;
		string Country;
		Person* next;
	};

	Person* HashTable[tableSize];
public:
	Hash();
	int HashIndex(string key);
	void InsertRecord(string ID, string Job_Title, string Email, string Last_Name, string First_Name, string Phone_Number, string Skills, string Country);
	
	void PrintTable();
	void PrintChainedRecords(int index);
	void FindWithPhoneNumber(string Phone_Number);
};

#endif