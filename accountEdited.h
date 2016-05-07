#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>

using namespace std;

class account
{
private:
	struct Date
	{
		int day;
		int month;
		int year;
	};
	struct Transaction
	{
		string name;
		double amount;
		Date transactDate;
		string description;
	};
	Transaction transaction;
	int acNo;
	char name[50];
	int balance;
	char type;
public:
	account();
	void setTransaction(string, double, string, int, int, int);
	void create_account();//function to get data from user
	void show_account() const;//function to show data on screen
	void modify();//function to add new data
	void dep(int);//function to accept amount and add to balance amount
	void draw(int);//function to accept amount and subtract from balance amount
	void report() const;//function to show data in tabular format
	int retacno() const;//function to return account number
	int retBalance() const;//function to return balance amount
	char rettype() const;//function to return type of account
};         //class ends here

#endif
