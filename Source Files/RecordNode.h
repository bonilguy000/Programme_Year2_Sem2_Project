#ifndef RecordNode_h
#define RecordNode_h
#include <string>

using namespace std;
class RecordNode {
public:
	string ID, Job_Title, Email, Last_Name, First_Name, Phone_Num, Skills, Country;
	RecordNode* next;

public:

	RecordNode(string iD, string job_Title, string email, string last_Name, string first_Name, string phone_Num, string skills, string country) {
		this->ID = iD;
		this->Job_Title = job_Title;
		this->Email = email;
		this->Last_Name = last_Name;
		this->First_Name = first_Name;
		this->Phone_Num = phone_Num;
		this->Skills = skills;
		this->Country = country;
	}
};

#endif