#ifndef TheList_h
#define TheList_h

#include "RecordHash.h"
#include "ReadFile.h"

class TheList {

public:

	TheList();

	~TheList();

	bool isEmpty();

	void printTheList();

	void insertList();//has Readfile.h(which has file reader and row counter)

	void removeRecordsPorC(); //Remove record with Phone Number or Country

	void singleSearch(); //Search based on one data

	void multiSearch(); //Search based on two data

};

void TheList::printTheList() {

}
void TheList::insertList() {
	// Yo whats the purpose of this m8 -Bonil
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

