/*****************************************************************//**
 * \file   Email.h
 * \brief  Declaration of Email class inheriting from Document
 *
 * \author kai
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include "Document.h"
#include <iostream>

using namespace std;

class Email :public Document {
private:
	string sender;
	string recipient;
	string title;

public:
	// Constructor to initialize email fields
	Email(string body, string sender, string recipient, string title);

	// Set the sender of the email
	void setSender(string sender);
	// Set the recipient of the email
	void setRecipient(string recipient);
	// Set the title of the email
	void setTitle(string title);

	// Get the sender of the email
	string getSender();
	// Get the recipient of the email
	string getRecipient();
	// Get the title of the email
	string getTitle();

	// Overloaded assignment operator
	void operator= (Email rhs);
};
