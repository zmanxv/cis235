// Specification file for the Account class.
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

// Constants
int MIN_DATE = 1,
    MAX_DATE = 31,
    MIN_MONTH = 1,
    MAX_MONTH = 12;

class Account
{
	
private:

	//***********************************************************************
	// The Date structure holds the month, day,	and year for a Transaction.	*
	//***********************************************************************
	struct Date
	{
		int month;
		int day;
		int year;	
	};

	//***********************************************************************
	// The Transaction structure holds the amount, Date, and description of *
	// 	an individual transaction in the ledger.							*
	//***********************************************************************
	struct Transaction
	{
		double amount;			// The dollar amount
		Date transactDate;
		string description;
	};

	// Class variables 
	string acctName;		// The account name
	double balance;			// Account balance
	int transactCount;		// The number of transactions made
	
public:

	//***********************************************************************
	// Exception classes													*
	//***********************************************************************
	class InvalidDay
	{};

	class InvalidMonth
	{};
	
	//***********************************************************************
	// Exception functions defined in cpp					*
	//***********************************************************************
	void validateDay();
	
	void validateMonth();


	//***********************************************************************
	// No argument constructor												*
	//***********************************************************************
	Account()
	{
		acctName = "";
		balance = 0.00;
		transactCount = 0;
	}

	//***********************************************************************
	// This constructor accepts the account name and starting balance.		*
	// Parameters: String for the name, double for the Account's starting	*
	// balance.																*
	//***********************************************************************	
	Account(string s, double bal)
	{ 
		acctName = s;
		balance = bal; 
		transactCount = 0; 
	}

	//***********************************************************************
	// The setAcctName function can be used to change the name of the		*
	// Account.																*
	// Parameters: String for the name.										*
	//***********************************************************************	
	void setAcctName(string s)
	{
		acctName = s;
	}

	//***********************************************************************
	// The setAmount function is used to set the dollar amount of a			*
	// Transaction.															*
	// Parameters: Double for the dollar amount.							*
	//***********************************************************************	
	void setAmount(double amt)
	{
		Transaction t;

		t.amount = amt;
	}
	
	//***********************************************************************
	// The setDate function is used to set the Date	for a Transaction in	* 
	// the ledger.															*
	// Parameters: An integer each for the month, day, and year of the Date.*
	//***********************************************************************	
	void setDate(int m, int d, int y)
	{
		Transaction t;
		
		t.transactDate.month = m;
		t.transactDate.date = d;
		t.transactDate.year = y;

		validateDay();
		validateMonth();
	}

	void deposit(Transaction t);	// Defined in Account.cpp
   
	bool withdraw(transaction t);	// Defined in Account.cpp
	
	// TO DO: getHistory function
	
	// TO DO: search function

	//***********************************************************************
	// The getBalance function is used to return the dollar amount of the	*
	// Account balance.														*
	// Returns: The account balance as a double.							*
	//***********************************************************************	
	double getBalance() const
    { 
		return balance; 
	}
   
	//***********************************************************************
	// The getTransactCount function is used to return the number of		*
	// Transactions made in	the Account.									*
	// Returns: The transaction count as an integer.						*
	//***********************************************************************	
	int getTransactCount() const
	{ 
		return transactCount; 
	}
	
	// TO DO: send transactions to the database
	
};

#endif
