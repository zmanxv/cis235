#include "Account.h"
#include <string>

// Constants
int MIN_DATE = 1,
    MAX_DATE = 31,
    MIN_MONTH = 1,
    MAX_MONTH = 12;

using namespace std;

//***********************************************************************
// The validateDay function validates that the day is valid.		*
// Parameters: None.							*
//***********************************************************************
void Account::validateDay()
	{
		if (day < MIN_DATE || day > MAX_DATE)
		{
			throw InvalidDay();
		}
		// Test for leap year
		else if (month == 2)
		{
			if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29)
			{
				throw InvalidDay();	
			}
			else if (day > 28)
			{
				throw InvalidDay();
			}
		}
		else if ((month == 4 || month == 6 || month == 9, || month = 11) && day > (MAX_DATE-1))
		{
			throw InvalidDay();
		}
	}

//***********************************************************************
// The validateMonth function validates that the day is valid.		*
// Parameters: None.							*
//***********************************************************************
void Account::validateMonth()
	{
		if (month < MIN_MONTH || month > MAX_MONTH)
		{
			throw InvalidMonth();
		}
	}

//***********************************************************************
// The deposit function adds a Transaction to the Account balance and	*
// increases the transaction count.										*
// Parameters: A Transaction, which includes the amount to be deposited.*
//***********************************************************************
void Account::deposit(Transaction t)
{
	// Add the Transaction amount to the Account balance
	balance += t.amount;

	// Increment the transaction count
	transactCount++;
}

//***********************************************************************
// The withdrawal function tests whether the Account has sufficient		*
// funds. If so, it	deducts the Transaction amount from the	Account		*
// balance and increases the transaction count.							*
// Parameters: A Transaction, which includes the amount to be withdrawn.*
// Returns: A boolean testing whether or not the withdrawal can be made.*
//***********************************************************************	
bool Account::withdraw(Transaction T)
{
   // If the Transaction amount is greater than the 
	// Account balance, the withdrawal cannot be made
	if (balance < t.amount)
	{
		return false;
	}
    // Otherwise, make the withdrawal
   else
   {
		// Subtract the Transaction amount from the 
		// Account balance
		balance -= t.amount;

	   // Increment the transaction count
		transactCount++;

		return true;
   }
}
