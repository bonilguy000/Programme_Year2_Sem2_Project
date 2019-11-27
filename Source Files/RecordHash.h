#ifndef RecordHash_h
#define RecordHash_h
#include <string>

using namespace std;
class RecordHashEntry {
private:
	string ID, Job_Title, Email, Last_Name, First_Name, Phone_Num, Skills, Country;
	int key;

public:

	RecordHashEntry(int key,string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country) {
		this->key = key;
		this->ID = iD;
		this->Job_Title = job_Title;
		this->Email = email;
		this->Last_Name = last_Name;
		this->First_Name = first_Name;
		this->Phone_Num = phone_Num;
		this->Skills = skills;
		this->Country = country;
	}
	int getKey() {
		return key;
	}
	int getRecord() {
		return ID;
		return Job_Title;
		return Email;
		return Last_Name;
		return First_Name;
		return Phone_Num;
		return Skills;
		return Country;
	}
};
const int TABLE_SIZE = 100000;

class HashMap {
private:
	RecordHashEntry **table;
public:
	HashMap() {
		table = new RecordHashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}
	int get(int key) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] == NULL)
			return-1;
		else
			return table[hash]->getRecord();
	}
	void put(int key, string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country) {
		int hash = key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new RecordHashEntry(key, iD,job_Title,email,last_Name,first_Name,phone_Num,skills,country);
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};
#endif