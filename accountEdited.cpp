#include "stdafx.h"
#include "account.h"
#include "Account.h"
#include <iomanip>

using namespace std;

account::account()
{
}

void account::setTransaction(string n, double a, string des, int d, int m, int y)
{
	transaction.name = n;
	transaction.amount = a;
	transaction.description = des;
	transaction.transactDate.day = d;
	transaction.transactDate.month = m;
	transaction.transactDate.year = y;
}

void account::create_account()
{
	cout << "\nEnter The account No. :";
	cin >> acNo;
	cout << "\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> balance;
	cout << "\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout << "\nAccount No. : " << acNo;
	cout << "\nAccount Holder Name : ";
	cout << name;
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << balance;
}


void account::modify()
{
	cout << "\nAccount No. : " << acNo;
	cout << "\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nModify Type of Account : ";
	cin >> type;
	type = toupper(type);
	cout << "\nModify Balance amount : ";
	cin >> balance;
}


void account::dep(int a)
{
	balance += a;
}

void account::draw(int a)
{
	balance -= a;
}

void account::report() const
{
	cout << acNo << setw(10) << " " << name << setw(10) << " " << type << setw(6) << balance << endl;
}


int account::retacno() const
{
	return acNo;
}

int account::retBalance() const
{
	return balance;
}

char account::rettype() const
{
	return type;
}
