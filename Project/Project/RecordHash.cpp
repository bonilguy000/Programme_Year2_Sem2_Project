#include <cstdlib>
#include <iostream>
#include <string>

#include "RecordHash.h"

using namespace std;
Hash::Hash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new Person;
		HashTable[i]->ID = "empty";
		HashTable[i]->Job_Title = "empty";
		HashTable[i]->Email = "empty";
		HashTable[i]->Last_Name = "empty";
		HashTable[i]->First_Name = "empty";
		HashTable[i]->Phone_Number = "empty";
		HashTable[i]->Skills = "empty";
		HashTable[i]->Country = "empty";
		HashTable[i]->next = NULL;
	}

}

void Hash::InsertRecord(string ID, string Job_Title, string Email, string Last_Name, string First_Name, string Phone_Number, string Skills, string Country) {
	int index = HashIndex(Phone_Number);

	if (HashTable[index]->ID == "empty") {
		HashTable[index]->ID = ID;
		HashTable[index]->Job_Title = Job_Title;
		HashTable[index]->Email = Email;
		HashTable[index]->Last_Name = Last_Name;
		HashTable[index]->First_Name = First_Name;
		HashTable[index]->Phone_Number = Phone_Number;
		HashTable[index]->Skills = Skills;
		HashTable[index]->Country = Country;
	}
	else {
		Person* Ptr = HashTable[index];
		Person* n = new Person;
		n->ID = ID;
		n->Job_Title = Job_Title;
		n->Email = Email;
		n->Last_Name = Last_Name;
		n->First_Name = First_Name;
		n->Phone_Number = Phone_Number;
		n->Skills = Skills;
		n->Country = Country;
		n->next = NULL;
		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}


void Hash::PrintTable() {
	for (int i = 0; i < tableSize; i++) {
		if (HashTable[i]->ID != "empty") {
			cout << "----------------------------------------------------------------" << endl;
			cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << endl;
			cout << "----------------------------------------------------------------" << endl;
			PrintChainedRecords(i);
		}
	}
}

void Hash::PrintChainedRecords(int index) {
	Person* Ptr = HashTable[index];
	if (Ptr->ID == "empty") {

	}
	else {
		Ptr = Ptr->next;
		while (Ptr != NULL) {
			cout << "----------------------------------------------------------------" << endl;
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << endl;
			cout << "----------------------------------------------------------------" << endl;
			Ptr = Ptr->next;
		}
	}
}

void Hash::FindWithPhoneNumber(string Phone_Number) {
	int index = HashIndex(Phone_Number);
	bool PhoneNumberFound = false;
	string ID, Job_Title, Email, Last_Name, First_Name,  Skills, Country;

	Person* Ptr = HashTable[index];
	while (Ptr != NULL) {
		if (Ptr->Phone_Number == Phone_Number) {
			PhoneNumberFound = true;
			ID = Ptr->ID;
			Job_Title = Ptr->Job_Title;
			Email = Ptr->Email;
			Last_Name = Ptr->Last_Name;
			First_Name = Ptr->First_Name;
			Skills = Ptr->Skills;
			Country = Ptr->Country;
		}
		Ptr = Ptr->next;
	}
	if (PhoneNumberFound == true) {
		cout << ID << " " << Job_Title << " " << Email << " " << Last_Name << " " << First_Name << " " << Phone_Number << " " << Skills << " " << Country << endl;
	}
	else {
		cout << "No record found with " << Phone_Number << endl;
	}
}

int Hash::HashIndex(string key) {
	int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}
	index = hash % tableSize;
	return index;
}