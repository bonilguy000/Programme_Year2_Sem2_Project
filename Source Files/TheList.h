#ifndef TheList_h
#define TheList_h

#include "RecordNode.h"
#include "ReadFile.h"

class TheList {
public:
	RecordNode* head;

public:

	TheList();

	~TheList();

	bool isEmpty();

	void printTheList();

	void insertList();//has Readfile.h(which has file reader and row counter)

	void removeRecordsPorC(); //Remove record with Phone Number or Country

	void singleSearch(); //Search based on one data

	void multiSearch(); //Search based on two data

	void setHead(RecordNode* node);

	RecordNode* getHead();
};
void TheList::insertList() {
	count();
	
	ifstream inputfile;
	//make a conditional statement on which file to access 
	inputfile.open("DS_10K.txt");// when user which file he's going visit 
	cout << "Please insert your ID" << endl;
	cin >> ID;
	cout << "Please type your current job" << endl;
	cin >> Job_Title;
	cout << "Enter your e-mail" << endl;
	cin >> Email;
}


#endif

