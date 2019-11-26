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

#endif

