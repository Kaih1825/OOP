#include "Document.h"

Document::Document(string text) {
	this->text = text;
}

string Document::getText() const {
	return text;
}

void Document::setText(string text) {
	this->text = text;
}

void Document::operator= (Document rhs) {
	text = rhs.text;
}
