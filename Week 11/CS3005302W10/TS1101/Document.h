/*****************************************************************//**
 * \file   Document.h
 * \brief  Declaration of Document class contains a member variable of type string named text that stores any textual content for the document
 *
 * \author kai
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include <iostream>

using namespace std;

class Document {
private:
	string text;

public:
	// Constructor to initialize the document with text
	Document(string text);

	// Get the current text of the document
	string getText() const;
	// Set new text for the document
	void setText(string text);

	// Overloaded assignment operator
	void operator= (Document rhs);
};
