#include "Account.h"
#include <string>

using namespace std;

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
