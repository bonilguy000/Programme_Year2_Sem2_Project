#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <locale>

#include "RecordHash.h"

using namespace std::chrono;

int main()
{
	
	Hash Test;
	int choice;
	int choice2;
	string fileInput;
	string ID, Job_Title, Email, Last_Name, First_Name, Phone_Number, Skills, Country, Country2;
	string UsrInput;
	string UsrInput2;
	bool Insert = false;
	do {
		cout << "Select an option:\n";
		cout << "1. Insert a dataset\n" << "2. Delete record(s)\n" << "3. Search record(s)\n" << "4.Print all records\n" << "5.Quit\n";
		cout << "Option: ";
		cin >> choice;
		system("CLS");
		switch (choice) {
		case 1:
		{
			{cout << "Please insert a txt data file: ";
			cin >> fileInput;
			ifstream File(fileInput);
			auto start = high_resolution_clock::now();
			if (Insert == true)
				Test.EmptyTable();
			while (File.eof() != true) {
				getline(File, ID, '\t');
				getline(File, Job_Title, '\t');
				getline(File, Email, '\t');
				getline(File, Last_Name, '\t');
				getline(File, First_Name, '\t');
				getline(File, Phone_Number, '\t');
				getline(File, Skills, '\t');
				getline(File, Country, '\t');
				getline(File, Country2, '\n');
				Country = Country + Country2;
				Test.InsertRecord(ID, Job_Title, Email, Last_Name, First_Name, Phone_Number, Skills, Country);
			}
			Test.PrintTable();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<seconds>(stop - start);
			Insert = true;
			cout << "Time taken: " << duration.count() << " seconds.\n";
			system("pause");
			system("CLS");
			}
		}
		break;
		case 2:
			system("CLS");
			cout << "Select how you would like to delete a record(s): \n";
			cout << "1. Phone Number(Single deletion)\n" << "2. Country(delete by batch)\n" << "3. Return\n";
			cout << "Option: ";
			cin >> choice2;
			switch (choice2) {
			case 1:
				system("CLS");
				cout << "\nInput a Phone Number for deleting a record: ";
				cin >> UsrInput;
				cin.ignore();
				Test.RemoveWithPhoneNumber(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 2:
				system("CLS");
				cout << "\nInput a Country for deleting a batch of records: ";
				cin.ignore();
				getline(cin, UsrInput);
				Test.RemoveWithCountry(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 3:
				system("CLS");
				break;
			}
			break;

		case 3:
			system("CLS");
			cout << "Select how you would like to search for a record(s): \n";
			cout << "1. Phone Number\n" << "2. Skills\n" << "3. Job Title\n" << "4. Country\n" << "5. Skill x Job Title\n" << "6. Skills x Country\n" << "7. Return\n";
			cout << "Option: ";
			cin >> choice2;
			switch (choice2) {
			case 1:
				system("CLS");
				cout << "\nInput a Phone Number for searching a record: ";
				cin >> UsrInput;
				cin.ignore();
				Test.FindWithPhoneNumber(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 2:
				system("CLS");
				cout << "\nInput a Skill for searching record(s): " ;
				cin.ignore();
				getline(cin, UsrInput);
				Test.FindWithSkills(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 3:
				system("CLS");
				cout << "\nInput a Job Title for searching record(s): ";
				cin.ignore();
				getline(cin, UsrInput);
				Test.FindWithJobTitle(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 4:
				system("CLS");
				cout << "\nInput a Country for searching record(s): ";
				cin.ignore();
				getline(cin, UsrInput);
				Test.FindWithCountry(UsrInput);
				system("pause");
				system("CLS");
				break;
			case 5:
				system("CLS");
				cout << "\nInput a Skill for searching record(s): ";
				cin.ignore();
				getline(cin, UsrInput);
				cout << "\nInput a Job Title for searching record(s): ";
				getline(cin, UsrInput2);
				Test.FindWithSkillsXJob(UsrInput, UsrInput2);
				system("pause");
				system("CLS");
				break;
			case 6:
				system("CLS");
				cout << "\nInput a Skill for searching record(s): ";
				cin.ignore();
				getline(cin, UsrInput);
				cout << "\nInput a Country for searching record(s): ";
				getline(cin, UsrInput2);
				Test.FindWithSkillsXCountry(UsrInput, UsrInput2);
				system("pause");
				system("CLS");
				break;
			case 7:
				system("CLS");
				break;
			}
			break;
		case 4:
			Test.PrintTable();
			break;
		case 5:
			cout << "Thanks for using this programme\n";
			system("pause");
		}
	} while (choice != 5);

		//cout << "Input a Phone Number for searching a record: ";
		//cin >> UsrInput;
		//cin.ignore();
		//Test.FindWithPhoneNumber(UsrInput);
		//system("pause");
		//system("CLS");

		//cout << "Input a Skill for searching record(s): " ;
		//cin.ignore();
		//getline(cin, UsrInput);
		//Test.FindWithSkills(UsrInput);
		//system("pause");
		//system("CLS");

		//cout << "Input a Job Title for searching record(s): ";
		//cin.ignore();
		//getline(cin, UsrInput);
		//Test.FindWithJobTitle(UsrInput);
		//system("pause");
		//system("CLS");

		//cout << "Input a Country for searching record(s): ";
		//cin.ignore();
		//getline(cin, UsrInput);
		//Test.FindWithCountry;
		//system("pause");
		//system("CLS");

		/*cout << "Input a Skill for searching record(s): ";
		cin.ignore();
		getline(cin, UsrInput);
		cout << "Input a Country for searching record(s): ";
		cin.ignore();
		getline(cin, UsrInput2);
		Test.FindWithSkillsXCountry(UsrInput, UsrInput2);
		system("pause");
		system("CLS");

		cout << "Input a Skill for searching record(s): ";
		cin.ignore();
		getline(cin, UsrInput);
		cout << "Input a Job Title for searching record(s): ";
		cin.ignore();
		getline(cin, UsrInput2);
		Test.FindWithSkillsXJob(UsrInput, UsrInput2);
		system("pause");
		system("CLS");

		cout << " Input a Phone Number for record deletion: ";
		cin >> UsrInput;
		cin.ignore();
		Test.RemoveWithPhoneNumber(UsrInput);
		system("pause");
		system("CLS");
		return 0;
		*/
		/*Tasks to complete(0/5)
		1. Make record class(8 attributes):
			1. ID (string)	- alphanumeric	unique	identifier
			2. Job Title	(string)
			3. Email Address	(string)
			4. Last	Name	(string)
			5. First	Name	(string)
			6. Phone	Number	(string)
			7. Skills	(string)
			8. Country	(string)
		2. Insertion of dataset:
			-Create a file reader that counts how many records are in there
			and also inserts it.
			-Users can add data as a batch with .txt filename input
			from user to insert new datasets
			-New data will replace existing one(delete old records)
			or else memory overflow
			-No single record adding allowed
		3. Deletion of record(s):
			-Programme should be able to delete single records with
			Phone Nmber ONLY
			-Programme should also delete records in a single batch
			by Country
		4. Searching for record(s):
			- The programmes should provide the following search function
			by the following SINGLE attribute:
				1. Phone Number
				2.Skills
				3.Job Title
				4.Country
			Programme will display all records (if any) in a sorted
			fashion(ascending or descending, any is fine)
			according to Country
			-Programme should provide search function by AT MOST TWO
			attributes. For instance, Skills x Job Title or
			Skills x Country, etc. Attributes mentioned in the
			previous point are recommended
			This function can be done either at a single step, keying in
			two values of attribute at the same time. Or an extension
			function of the SINGLE attribute search. Users can be prompted
			to see whether he/she wishes to do deeper search after single
			attribute search is done.
		5. Task 2-4 must have a timer that times the operation(s) and
			displays the time elapsed after operation(s). Sub-function
			timing is not required.
			-For task 2, only the total time for inserting
			single batch of data should be displayed.
			-For task 3, only the total time taken for deletion of a
			single record should be displayed (maybe also single batch)
			-For task 4, only the total time taken for searching for a
			single record should be displayed

		*/
	
}