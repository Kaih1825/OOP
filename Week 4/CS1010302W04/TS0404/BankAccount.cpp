/*****************************************************************//**
 * \file   BankAccount.cpp
 * \brief  Implementation the functions of BankAccount class
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#include "BankAccount.h"

 // The static variable of the total in the BankAccount class
int BankAccount::total = 0;

/**
 * Construct a BankAccount where the balance is 0
 *
 */
BankAccount::BankAccount() {
	// Set the balance into 0
	this->balance = 0;
}

/**
 * Construct a BankAccount where the balance is input
 *
 * \param input The default balance
 */
BankAccount::BankAccount(int input) {
	// Set the balance into the input value
	this->balance = input;
	// Save the money into bank
	this->total += input;
}

/**
 * Withdraw money in the bank with the value of output
 *
 * \param output The money want to take out from bank
 */
void BankAccount::withdraw(int output) {
	// Set the new balance
	this->balance -= output;
	// Take the money out of the bank
	this->total -= output;
}

/**
 * Save money in the bank with the value of input.
 *
 * \param input The money want to save
 */
void BankAccount::save(int input) {
	// Set the new balance
	this->balance += input;
	// Save the money into the bank
	this->total += input;
}

/**
 * Get the current balance of this account
 *
 * \return The current balance
 */
int BankAccount::getBalance() {
	// Return the current balance
	return this->balance;
}

/**
 * Get the value of the total money amount in the bank
 *
 * \return The total money
 */
int BankAccount::getAllMoneyInBank() {
	// return the value of the total money amount in the bank
	return BankAccount::total;
}
