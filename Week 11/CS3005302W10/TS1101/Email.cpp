/*****************************************************************//**
 * \file   Email.cpp
 * \brief  Implementation of Email class
 *
 * \author kai
 * \date   2025/5/1
 *********************************************************************/
#include "Email.h"

 /**
  *  Constructor to initialize email content and metadata
  *
  * \param body Email Body
  * \param sender Email Sender
  * \param recipient Email recipient
  * \param title Email title
  */
Email::Email(string body, string sender, string recipient, string title) :Document(body) {
	this->sender = sender;
	this->recipient = recipient;
	this->title = title;
}

/**
 * Set the sender of the email
 *
 * \param sender Email sender
 */
void Email::setSender(string sender) {
	this->sender = sender;
}

/**
 * Set the recipient of the email
 *
 * \param recipient Email recipient
 */
void Email::setRecipient(string recipient) {
	this->recipient = recipient;
}

/**
 * Set the title of the email
 *
 * \param title Email title
 */
void Email::setTitle(string title) {
	this->title = title;
}

/**
 * Get the sender of the email
 *
 * \return Email sender
 */
string Email::getSender() {
	return sender;
}

/**
 * Get the recipient of the email
 *
 * \param recipient Email recipient
 */
string Email::getRecipient() {
	return recipient;
}

/**
 * Get the title of the email
 *
 * \param title Email title
 */
string Email::getTitle() {
	return title;
}

/**
 * Assignment operator overload for Email
 *
 * \param rhs Email to copy from
 */
void Email::operator= (Email rhs) {
	// Copy body from base class
	setText(rhs.getText());

	// Copy all variable
	this->sender = rhs.sender;
	this->recipient = rhs.recipient;
	this->title = rhs.title;
}