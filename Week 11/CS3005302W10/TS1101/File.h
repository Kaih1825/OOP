/*****************************************************************//**
 * \file   File.h
 * \brief  Declaration of File class inheriting from Document
 *
 * \author kai
 * \date   2025/4/30
 *********************************************************************/
#pragma once

#include "Document.h"
#include <iostream>

using namespace std;

class File :public Document {
private:
	string pathname;

public:
	// Constructor to initialize file content and path
	File(string body, string pathname);

	// Get the file path
	string getPathname();
	// Set the file path
	void setPathname(string pathname);

	// Overloaded assignment operator
	void operator= (File rhs);
};
