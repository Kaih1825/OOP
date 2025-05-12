/*****************************************************************//**
 * \file   Account.h
 * \brief  Account class for managing deposits and withdrawals
 *
 * \author Kai
 * \date   2025/5/12
 *********************************************************************/
#pragma once

#include "InsufficientFunds.h"
#include "NegativeDeposit.h"

 // Account class for managing deposits and withdrawals
class Account
{
private:
	// Current account balance
	double balance;
public:
	// Default constructor
	Account();

	// Constructor with initial deposit
	Account(double initialDeposit);

	// Get current balance
	double getBalance();

	//returns new balance or -1 if error 
	double deposit(double amount);

	//return new balance or -1 if invalid amount 
	double withdraw(double amount);
};