#include "Email.h"

Email::Email(string body, string sender, string recipient, string title) :Document(body) {
	this->sender = sender;
	this->recipient = recipient;
	this->title = title;
}

void Email::setSender(string sender) {
	this->sender = sender;
}

void Email::setRecipient(string recipient) {
	this->recipient = recipient;
}

void Email::setTitle(string title) {
	this->title = title;
}

string Email::getSender() {
	return sender;
}

string Email::getRecipient() {
	return recipient;
}

string Email::getTitle() {
	return title;
}

void Email::operator= (Email rhs) {
	setText(rhs.getText());
	this->sender = rhs.sender;
	this->recipient = rhs.recipient;
	this->title = rhs.title;
}