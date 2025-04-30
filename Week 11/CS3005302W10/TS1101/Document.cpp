/*****************************************************************//**
 * \file   Document.cpp
 * \brief  Implementation of Document class
 *
 * \author kai
 * \date   2025/5/1
 *********************************************************************/
#include "Document.h"

 /**
  * Constructor that sets the text content
  *
  * \param text Text
  */
Document::Document(string text) {
	this->text = text;
}

/**
 * Get the current text
 *
 * \return Text
 */
string Document::getText() const {
	return text;
}

/**
 * Set new text content
 *
 * \param text Text
 */
void Document::setText(string text) {
	this->text = text;
}

/**
 * Assignment operator overload
 *
 * \param rhs Document to copy from
 */
void Document::operator= (Document rhs) {
	text = rhs.text;
}
