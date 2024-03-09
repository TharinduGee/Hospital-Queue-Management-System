#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class patient {
public:
	int priority;
	long ID;
	string firstname;
	string lastname;
	int age;
	char blood[5];
	//string blood;
	char gender;
	patient* next;



};

class linkedlist {
private:
	patient* head;
	patient* tail;
public:
	string departmentname;

	linkedlist() {
		head = NULL;
		tail = NULL;
	}

	patient input() {
		
		patient* p = new patient();
		cout << "\n   Please enter info for patient\n";
		//should validate the prority
		while (true) {
			int pri;
			cout << "\n   Priority (High = 3/Mid = 2/Low = 1):" ;
			cin >> pri;
			if (pri < 4 && pri >> 0) {
				p->priority = pri;
				break;
			}
			else {
				cout << "Data that you entered is not valid" << endl;
			}
		}
		
		
		cout << "\n   First name     : ";
		cin >> p->firstname;
		cout << "   Last name      : ";
		cin >> p->lastname;

		
		
		/*while (true) {
			cout << "   Blood Group    : ";
			cin >> p->blood;

			if ((p->blood == "O+") || (p->blood == "o+")) {
				break;
			}
			else {
				cout << "\n   Invalid Blood Group Try Again..\n\n" << endl;
			}
		}*/
		//there should be change in here 
		int flag = 0;
		again:
		cout << "   blood group    : ";
		cin >> p->blood;
		if ((strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "a-") == 0) || (strcmp(p->blood, "a-") == 0) ||
			(strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "b-") == 0) || (strcmp(p->blood, "b-") == 0) ||
			(strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "o-") == 0) || (strcmp(p->blood, "o-") == 0) ||
			(strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "ab-") == 0) || (strcmp(p->blood, "ab-") == 0))
			flag = 1;
		if (flag == 0)
		{
			cout << "\n   invalid blood group try again..\n\n";
			goto again;

		}
		cout << "   Gender(m/f)    : ";
		cin >> p->gender;
		cout << "   Age            : ";
		cin >> p->age;
		cout << "   Mobile number  : ";
		cin >> p->ID;
		
		
		if (check_unique(p->ID))
		{
			p->ID = 0;
			//cout << "\n   Data not valid. Operation cancelled.";
		}
		
		return *p;
	};

	void insertatpriority()
	{
		patient* p = new patient();
		*p = input();

		if (p->ID == 0) {
			cout << "\n   Data not valid. Operation cancelled.";
			delete p;
			return;
		}
		if (head == NULL)

		{
			head = p;
			tail = p;
			p->next = NULL;
			
		}
		else if (head->priority < p->priority) {
	
			p->next = head;
			head = p;

		}
		else {
			
			patient* curr = head;
			while (curr->next != NULL && curr->next->priority > p->priority) {
				curr = curr->next;
			}
			if (curr->next == NULL) {
				curr->next = p;
				tail = p;
			}
			else {
				p->next = curr->next;
				curr->next = p;
			}

		}

		
		system("cls");
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout << "\n  |-- CLINIC MANAGEMENT SYSTEM --|";
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
		cout << "\n  ----------PATIENT ADDED-----------";
		output(p);

	}

	void getpatientout()
	{
		system("cls");
		if (head == NULL)
		{
			cout << "\n  No Patient to operate";
		}
		else
		{
			patient* p = new patient();
			p = head;
			head = head->next;
			cout << "\n  Patient to check:";
			output(p);
		}
	}
	
	void listofpatients()
	{
		if (head == NULL)
		{
			cout << "\n  No patient";
		}
		system("cls");
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout << "\n  |-- CLINIC MANAGEMENT SYSTEM --|";
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
		patient* p = new patient;
		p = head;
		while (p != NULL)
		{
			cout << "\n   Patient data:\n";
			cout << "\n   Priority         : " << p->priority;
			cout << "\n   First Name       : " << p->firstname;
			cout << "\n   Last Name        : " << p->lastname;
			cout << "\n   Gender           : " << p->gender;
			cout << "\n   Age              : " << p->age;
			cout << "\n   Blood Group      : " << p->blood;
			cout << "\n   Mobile Number    : " << p->ID;
			cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
			p = p->next;
		}
		cout << "\n";
	}

	int check_unique(int token) {
		if (token == 0) {
			return false;
		}
		if (head == NULL ) 
			return false;
		else
		{
			int flag = 0;
			patient* p = new patient();
			p = head;

			while (p->next != NULL && p->ID != token)
			{
				p = p->next;
			}
			if (p->ID == token)
			{
				flag = 1;
				return true;
			}
			if (flag == 0)
				return false;
		}
	};

	void output(patient* p)
	{
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout << "\n   Patient data:\n";
		cout << "\n   Priority           : " << p->priority;
		cout << "\n   First Name         : " << p->firstname;
		cout << "\n   Last Name          : " << p->lastname;
		cout << "\n   Gender             : " << p->gender;
		cout << "\n   Age                : " << p->age;
		cout << "\n   Blood Group        : " << p->blood;
		cout << "\n   Mobile Number      : " << p->ID;
		cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	}

	void search_by_ID() {
		int id;
		cout  << "   Enter an ID : " ;
		cin >> id;
		if (head == NULL) {
			cout << "\n   There is no queue\n" << endl;
		}
		patient* p = new patient;
		p = head;
		while(p != NULL){
			if (p->ID == id) {
				cout << "\n   Patient data:\n";
				cout << "\n   First Name       : " << p->firstname;
				cout << "\n   Last Name        : " << p->lastname;
				cout << "\n   Gender           : " << p->gender;
				cout << "\n   Age              : " << p->age;
				cout << "\n   Blood Group      : " << p->blood;
				cout << "\n   Mobile Number    : " << p->ID;
				cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
				break;
			}
			p = p->next;
		}
		cout << "   There is no patient by this ID" << endl;

	};

};

int readnumber()
{
	
	// done by ascii table
	char num;
	cin >> num;
	if (int(num) > 53 || int(num) < 49) {
		cout << "\n   Invalid choice" << endl;
		system("pause");
	}
	return  int(num) - 48;
}

void departmentmenu(linkedlist* q)
{
	int choice = 0;
	while (choice != 5)
	{
		system("cls");
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout << "\n  |-- CLINIC MANAGEMENT SYSTEM --|";
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout << "\n\n   " << q->departmentname;
		cout << "\n   [1] Add patient\n";
		cout << "   [2] Take patient to Doctor\n";
		cout << "   [3] Display list\n";
		cout << "   [4] Search by id \n";
		cout << "   [5] Change department or exit\n";
		cout << "\n   Please enter your choice : ";

		choice = readnumber(); // this method get number from 1 to 4 and declared to the choice.

		cout << "  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

		switch (choice)
		{
		case 1:	
			q->insertatpriority();
			cout << "\n";
			system("pause");
			break;
		

		case 2:	
			q->getpatientout();
			cout << "\n";
			system("pause");
			break;

		case 3:	system("cls");
			q->listofpatients();
			cout << "\n";
			system("pause");
			break;


		case 4: 
			q->search_by_ID();
			cout << "\n";
			system("pause");
			break;
		}
	}
}