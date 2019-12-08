#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

#include "RecordHash.h"

using namespace std::chrono;
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
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
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
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << "\n";
			Ptr = Ptr->next;
		}
	}
}

void Hash::FindWithPhoneNumber(string Phone_Number) {
	int index = HashIndex(Phone_Number);
	bool PhoneNumberFound = false;
	string ID, Job_Title, Email, Last_Name, First_Name,  Skills, Country;

	auto start = high_resolution_clock::now();
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
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		cout << "Time taken: " << duration.count() << " milliseconds\n";
	}
	else {
		cout << "No record found with " << Phone_Number << endl;
	}
}

void Hash::FindWithSkills(string Skills) {
	char letter = 'A';
	for (int c = 65; c <= 90; c++) {
		cout << "Showing results with Countries starting with " << letter << "\n";
		for (int i = 0; i < tableSize; i++) {
			auto start = high_resolution_clock::now();
			if (HashTable[i]->Skills == Skills && letter == (HashTable[i]->Country.at(0))) {
				cout << "---------------------------------------------------------------------------------------------------------------\n";
				cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Time taken: " << duration.count() << " milliseconds\n";
			}
			if (HashTable[i]->ID != "empty") {
				FindChainedWithSkills(Skills, i, letter);
			}
		}
		system("pause");
		system("CLS");
		letter = c+1;
	}
	cout << "All results found\n";
}

void Hash::FindChainedWithSkills(string Skills, int index, char letter) {
	Person* Ptr = HashTable[index];
	Ptr = Ptr->next;
	while (Ptr != NULL) {
		auto start = high_resolution_clock::now();
		if (Ptr->Skills == Skills && letter == ((Ptr->Country).at(0))) {
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << "\n";
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
		}
		Ptr = Ptr->next;
	}
}

void Hash::FindWithJobTitle(string Job_Title) {
	char letter = 'A';
	for (int c = 65; c <= 90; c++) {
		cout << "Showing results with Countries starting with " << letter << "\n";
		for (int i = 0; i < tableSize; i++) {
			auto start = high_resolution_clock::now();
			if (HashTable[i]->Job_Title == Job_Title && letter == (HashTable[i]->Country.at(0))) {
				cout << "---------------------------------------------------------------------------------------------------------------\n";
				cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Time taken: " << duration.count() << " milliseconds\n";
			}
			if (HashTable[i]->ID != "empty") {
				FindChainedWithJobTitle(Job_Title, i, letter);
			}
		}
		system("pause");
		system("CLS");
		letter = c + 1;
	}
	cout << "All results found\n";
}

void Hash::FindChainedWithJobTitle(string Job_Title, int index, char letter) {
	Person* Ptr = HashTable[index];
	Ptr = Ptr->next;
	while (Ptr != NULL) {
		auto start = high_resolution_clock::now();
		if (Ptr->Job_Title == Job_Title && letter == ((Ptr->Country).at(0))) {
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << "\n";
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
		}
		Ptr = Ptr->next;
	}
}


void Hash::FindWithCountry(string Country) {
	for (int i = 0; i < tableSize; i++) {
		auto start = high_resolution_clock::now();
		if (HashTable[i]->Country == Country) {
			cout << "---------------------------------------------------------------------------------------------\n" ;
			cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
			
		}
		if (HashTable[i]->ID != "empty") {
			FindChainedWithCountry(Country, i);
		}
	}
}

void Hash::FindChainedWithCountry(string Country, int index) {
	Person* Ptr = HashTable[index];
	Ptr = Ptr->next;
	while (Ptr != NULL) {
		auto start = high_resolution_clock::now();
		if (Ptr->Country == Country) {
			cout << "---------------------------------------------------------------------------------------------\n";
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << "\n";
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
		}
		Ptr = Ptr->next;
	}
}

void Hash::FindWithSkillsXJob(string Skills,string Job_Title) {
	char letter = 'A';
	for (int c = 65; c <= 90; c++) {
		cout << "Showing results with Countries starting with " << letter << "\n";
		for (int i = 0; i < tableSize; i++) {
			auto start = high_resolution_clock::now();
			if (HashTable[i]->Skills == Skills && HashTable[i]->Job_Title == Job_Title && letter == ((HashTable[i]->Country).at(0))) {
					cout << "---------------------------------------------------------------------------------------------------------------\n";
					cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<milliseconds>(stop - start);
					cout << "Time taken: " << duration.count() << " milliseconds\n";
			}
			if (HashTable[i]->ID != "empty") {
				FindChainedWithSkillsXJob(Skills ,Job_Title, i, letter);
			}
		}
		system("pause");
		system("CLS");
		letter = c + 1;
	}
	cout << "All results found\n";
}

void Hash::FindChainedWithSkillsXJob(string Skills, string Job_Title, int index, char letter) {
	Person* Ptr = HashTable[index];
	Ptr = Ptr->next;
	while (Ptr != NULL) {
		auto start = high_resolution_clock::now();
		if (Ptr->Skills == Skills  && letter == ((Ptr->Country).at(0))) {
			if (Ptr->Job_Title == Job_Title) {
				cout << "---------------------------------------------------------------------------------------------------------------\n";
				cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << "\n";
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Time taken: " << duration.count() << " milliseconds\n";
			}
		}
		Ptr = Ptr->next;
	}
}

void Hash::FindWithSkillsXCountry(string Skills,string Country) {
	for (int i = 0; i < tableSize; i++) {
		auto start = high_resolution_clock::now();
		if (HashTable[i]->Skills == Skills && HashTable[i]->Country == Country) {
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << endl;
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
			FindChainedWithSkillsXCountry(Skills,Country, i);
		}
	}
}

void Hash::FindChainedWithSkillsXCountry(string Skills, string Country, int index) {
	Person* Ptr = HashTable[index];
	Ptr = Ptr->next;
	while (Ptr != NULL) {
		auto start = high_resolution_clock::now();
		if (Ptr->Skills == Skills && Ptr->Country == Country) {
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << Ptr->ID << " " << Ptr->Job_Title << " " << Ptr->Email << " " << Ptr->Last_Name << " " << Ptr->First_Name << " " << Ptr->Phone_Number << " " << Ptr->Skills << " " << Ptr->Country << endl;
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			cout << "Time taken: " << duration.count() << " milliseconds\n";
		}
		Ptr = Ptr->next;
	}
}

void Hash::RemoveWithPhoneNumber(string Phone_Number) {
	int index = HashIndex(Phone_Number);
	Person* DeLPtr;
	Person* Ptr1;
	Person* Ptr2;

	if (HashTable[index]->ID == "empty" && HashTable[index]->Job_Title == "empty" && HashTable[index]->Email == "empty" && HashTable[index]->Last_Name == "empty" && HashTable[index]->First_Name == "empty"&& HashTable[index]->Phone_Number == "empty" && HashTable[index]->Skills == "empty" && HashTable[index]->Country == "empty") {
		cout << Phone_Number << "was not found\n";
	}
	else if (HashTable[index]->Phone_Number == Phone_Number && HashTable[index]->next == NULL){
		cout << "The following recod is deleted:\n";
		cout << "---------------------------------------------------------------------------------------------------------------\n";
		cout << HashTable[index]->ID << " " << HashTable[index]->Job_Title << " " << HashTable[index]->Email << " " << HashTable[index]->Last_Name << " " << HashTable[index]->First_Name << " " << HashTable[index]->Phone_Number << " " << HashTable[index]->Skills << " " << HashTable[index]->Country << "\n";
		HashTable[index]->ID = "empty";
		HashTable[index]->Job_Title = "empty";
		HashTable[index]->Email = "empty";
		HashTable[index]->Last_Name = "empty";
		HashTable[index]->First_Name = "empty";
		HashTable[index]->Phone_Number = "empty";
		HashTable[index]->Skills = "empty";
		HashTable[index]->Country = "empty";
	}
	else if (HashTable[index]->Phone_Number == Phone_Number) {
		DeLPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		cout << "---------------------------------------------------------------------------------------------------------------\n";
		cout << "The following record is deleted:\n";
		cout << DeLPtr->ID << " " << DeLPtr->Job_Title << " " << DeLPtr->Email << " " << DeLPtr->Last_Name << " " << DeLPtr->First_Name << " " << DeLPtr->Phone_Number << " " << DeLPtr->Skills << " " << DeLPtr->Country << "\n";
		delete DeLPtr;
	}
	else {
		Ptr1 = HashTable[index]->next;
		Ptr2 = HashTable[index];

		while (Ptr1 != NULL && Ptr1->Phone_Number != Phone_Number) {
			Ptr2 = Ptr1;
			Ptr1 = Ptr1->next;
		}

		if (Ptr1 == NULL) {
			cout << Phone_Number << "was not found\n";
		}
		else {
			DeLPtr = Ptr1;
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << "The following record is deleted:\n";
			cout << DeLPtr->ID << " " << DeLPtr->Job_Title << " " << DeLPtr->Email << " " << DeLPtr->Last_Name << " " << DeLPtr->First_Name << " " << DeLPtr->Phone_Number << " " << DeLPtr->Skills << " " << DeLPtr->Country << "\n";
			Ptr1 = Ptr1->next;
			Ptr2->next = Ptr1;

			delete DeLPtr;
		}
	}
}

void Hash::RemoveWithCountry(string Country) {
	Person* DeLPtr;

	for (int i = 0; i < tableSize; i++) {
		if (HashTable[i]->Country == Country && HashTable[i]->next == NULL) {
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << "The following record is deleted:\n";
			cout << HashTable[i]->ID << " " << HashTable[i]->Job_Title << " " << HashTable[i]->Email << " " << HashTable[i]->Last_Name << " " << HashTable[i]->First_Name << " " << HashTable[i]->Phone_Number << " " << HashTable[i]->Skills << " " << HashTable[i]->Country << "\n";
			HashTable[i]->ID = "empty";
			HashTable[i]->Job_Title = "empty";
			HashTable[i]->Email = "empty";
			HashTable[i]->Last_Name = "empty";
			HashTable[i]->First_Name = "empty";
			HashTable[i]->Phone_Number = "empty";
			HashTable[i]->Skills = "empty";
			HashTable[i]->Country = "empty";
		}
		else if (HashTable[i]->Country == Country) {
			DeLPtr = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << "The following record is deleted:\n";
			cout << DeLPtr->ID << " " << DeLPtr->Job_Title << " " << DeLPtr->Email << " " << DeLPtr->Last_Name << " " << DeLPtr->First_Name << " " << DeLPtr->Phone_Number << " " << DeLPtr->Skills << " " << DeLPtr->Country << "\n";
			delete DeLPtr;
		}

		if (HashTable[i]->ID != "empty" && HashTable[i]->next != NULL) {
			RemoveChainedWithCountry(Country, i);
			RemoveChainedWithCountry(Country, i);
		}

	}
}

void Hash::RemoveChainedWithCountry(string Country, int index) {
	Person* DeLPtr;
	Person* Ptr1;
	Person* Ptr2;
	bool deleted = false;
	Ptr1 = HashTable[index]->next;
	Ptr2 = HashTable[index];
	while (Ptr1->next != NULL) {
		if (Ptr1->Country == Country) {
			DeLPtr = Ptr1;
			cout << "---------------------------------------------------------------------------------------------------------------\n";
			cout << "The following record is deleted:\n";
			cout << DeLPtr->ID << " " << DeLPtr->Job_Title << " " << DeLPtr->Email << " " << DeLPtr->Last_Name << " " << DeLPtr->First_Name << " " << DeLPtr->Phone_Number << " " << DeLPtr->Skills << " " << DeLPtr->Country << "\n";
			Ptr1 = Ptr1->next;
			Ptr2->next = Ptr1;
			delete DeLPtr;
		}
		Ptr1 = Ptr1->next;
		Ptr2 = Ptr2->next;
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