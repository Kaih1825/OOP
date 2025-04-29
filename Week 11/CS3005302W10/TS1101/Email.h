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
	Email(string body, string sender, string recipient, string title);

	void setSender(string sender);
	void setRecipient(string recipient);
	void setTitle(string title);

	string getSender();
	string getRecipient();
	string getTitle();

	void operator= (Email rhs);
};
