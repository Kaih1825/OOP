/*****************************************************************//**
 * \file   File.cpp
 * \brief  Implementation of File class
 *
 * \author kai
 * \date   2025/5/1
 *********************************************************************/
#include "File.h"

 /**
  * Constructor to initialize file content and pathname
  *
  * \param body File body
  * \param pathname File pathname
  */
File::File(string body, string pathname) :Document(body) {
	this->pathname = pathname;
}

/**
 * Get the file path
 *
 * \return File path
 */
string File::getPathname() {
	return pathname;
}

/**
 * Set the file path
 *
 * \param pathname File path
 */
void File::setPathname(string pathname) {
	this->pathname = pathname;
}

/**
 * Assignment operator overload for File
 *
 * \param rhs
 */
void File::operator= (File rhs) {
	// Copy body from base class
	setText(rhs.getText());

	// Copy pathname
	this->pathname = rhs.pathname;
}