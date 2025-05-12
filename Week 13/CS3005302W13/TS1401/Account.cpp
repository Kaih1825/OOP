#include "Account.h"

/**
 * Initializes balance to 0
 *
 */
Account::Account() {
	balance = 0;
}

/**
 * Constructor with initial deposit
 *
 * \param initialDeposit Initial amount to deposit
 */
Account::Account(double initialDeposit) {
	balance = initialDeposit;
}

/**
 * Get current balance
 *
 * \return Current balance
 */
double Account::getBalance() {
	return balance;
}

/**
 * Returns new balance
 *
 * \param amount The amount
 * \return new balance
 */
 //returns new balance or -1 if error 
double Account::deposit(double amount)
{
	if (amount > 0) balance += amount;
	// Throw error
	else throw NegativeDeposit();
	return balance;
}

/**
 * Returns new balance
 *
 * \param amount The amount
 * \return new balance
 */
double Account::withdraw(double amount)
{
	// Throw error
	if ((amount > balance) || (amount < 0)) throw InsufficientFunds();
	else balance -= amount;
	return balance;
}
