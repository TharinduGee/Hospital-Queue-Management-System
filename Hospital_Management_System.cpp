#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "Header.h"
using namespace std;



int main() {
	int i, choice = 1;
	linkedlist departments[4];

	while (choice != 5)
	{
		departments[0].departmentname = "GENERAL CLINIC\n";
		departments[1].departmentname = "HEART CLINIC\n";
		departments[2].departmentname = "DENTAL CLINIC\n";
		departments[3].departmentname = "ENT CLINIC\n";
	
		cout << "\n  ##################################";
		cout << "\n  |-- CLINIC MANAGEMENT SYSTEM --|";
		cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
		cout << "   Main Menu\n\n";

		for (i = 0; i < 4; i++)
		{
			cout << "   " << (i + 1) << ": " << departments[i].departmentname;
		}
		cout << "   5: Exit";
		cout << "\n\n   Please enter your choice : ";
		cin >> choice;
		
		if (choice >= 1 && choice <= 4)
		{
			departmentmenu(&departments[choice - 1]);
		}
		else {
			cout << "\n   Invalid Input" << endl;
		}

	}
	if (choice == 5)
		cout << "\n\t\tThank you! \n";

	return 0;
}