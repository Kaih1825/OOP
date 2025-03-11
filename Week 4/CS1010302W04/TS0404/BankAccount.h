/*****************************************************************//**
 * \file   BankAccount.h
 * \brief  The class for BankAccount, offer withdraw, save, getBalance and getAllMoneyInBank functions
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#ifndef BankAccount_H
#define BankAccount_H

class BankAccount {
private:
	int balance;
	static int total;
public:
	BankAccount();
	BankAccount(int input);
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};

#endif // BankAccount_H