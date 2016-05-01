// FinalProjectMenu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void menu();

int main()
{
	menu();
    return 0;
}

void menu()
{
	bool runMenu = true;
	char confirm;
	string name;
	string description;
	string date;
	int amount;

	while(runMenu)
	{
		cout << "[A]dd an account" << endl;
		cout << "[I]nput a new transaction to an account" << endl;
		cout << "[V]iew transaction history" << endl;
		cout << "[S]earch for a transaction" << endl;
		cout << "[G]et a summary of all accounts" << endl;
		cout << "[E]xit" << endl;
		cin >> confirm;

		if (confirm == 'a' || confirm == 'A')
		{
			cout << "Which account do you want to add, Checking, Saving, or Money Market?" << endl;
			cin >> confirm;
			if (confirm == 'c' || confirm == 'C')
			{
				//add checking account
				while(confirm != 'n' || confirm != 'N')
				{
					cout << "Do you wish to enter debit or credit?" << endl;
					cin >> confirm;
					if (confirm == 'c' || confirm == 'C')
					{
						//credit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					if (confirm == 'd' || confirm == 'D')
					{
						//debit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					cout << "Do you wish to enter another transaction?" << endl;
					cin >> confirm;
				}
			}
			if (confirm == 's' || confirm == 'S')
			{
				//add saving account
			while(confirm != 'n' || confirm != 'N')
				{
					cout << "Do you wish to enter debit or credit?" << endl;
					cin >> confirm;
					if (confirm == 'c' || confirm == 'C')
					{
						//credit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					if (confirm == 'd' || confirm == 'D')
					{
						//debit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					cout << "Do you wish to enter another transaction?" << endl;
					cin >> confirm;
				}
			}
			if (confirm == 'm' || confirm == 'M')
			{
				//add Money Market account
				while(confirm != 'n' || confirm != 'N')
				{
					cout << "Do you wish to enter debit or credit?" << endl;
					cin >> confirm;
					if (confirm == 'c' || confirm == 'C')
					{
						//credit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					if (confirm == 'd' || confirm == 'D')
					{
						//debit
						cout << "Enter Name of transaction" << endl;
						cin >> name;

						cout << "Date of transaction" << endl;
						cin >> date;

						cout << "Enter description" << endl;
						cin >> description;

						cout << "Enter the amount of the transaction" << endl;
						cin >> amount;
					}
					cout << "Do you wish to enter another transaction?" << endl;
					cin >> confirm;
				}
			}
		}
		if (confirm == 'i' || confirm == 'I')
		{
			//add a new transaction to an existing account
		}
		if (confirm == 'v' || confirm == 'V')
		{
			//view transactions
		}
		if (confirm == 's' || confirm == 'S')
		{
			//search for a transaction
		}
		if (confirm == 'g' || confirm == 'G')
		{
			//summary of all acounts
		}
		if (confirm == 'e' || confirm == 'E')
		{
			break;
		}
	}
	return;
}
