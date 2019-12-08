#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef RECORDHASH_H
#define RECORDHASH_H

class Hash {
private:
	static const int tableSize = 200000;

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
	void FindWithSkills(string Skills);
	void FindChainedWithSkills(string Skills, int index,char letter);
	void FindWithJobTitle(string Job_Title);
	void FindChainedWithJobTitle(string Job_Title, int index, char letter);
	void FindWithCountry(string Country);
	void FindChainedWithCountry(string Country, int index);
	void FindWithSkillsXJob(string Skills, string Job_Title);
	void FindChainedWithSkillsXJob(string Skills, string Job_Title, int index,char letter);
	void FindWithSkillsXCountry(string Skills, string Country);
	void FindChainedWithSkillsXCountry(string Skills, string Country, int index);
	void RemoveWithPhoneNumber(string PhoneNumber);
	void RemoveWithCountry(string Country);
	void RemoveChainedWithCountry(string Country, int index);
	void EmptyTable();
};

#endif