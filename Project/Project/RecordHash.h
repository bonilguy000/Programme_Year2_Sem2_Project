#ifndef RecordHash_h
#define RecordHash_h
#include <string>
//Record hash here
using namespace std;
class RecordHashEntry {
private:
	string ID, Job_Title, Email, Last_Name, First_Name, Phone_Num, Skills, Country;
	int key;

public:
	RecordHashEntry(int key, string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country) {
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
	int getKey() { //used to grab key from private
		return key;
	}
	string getRecord() { //used to grab record from private
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

class HashMap {
private:
	RecordHashEntry **table;
public:
	HashMap();
	string get(int key);
	// Insert a new record
	void put(int key, string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country);
	~HashMap();
};
#endif
