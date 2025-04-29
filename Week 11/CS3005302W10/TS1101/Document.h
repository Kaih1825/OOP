#pragma once
#include <iostream>

using namespace std;

class Document {
private:
	string text;

public:
	Document(string text);

	string getText() const;
	void setText(string text);


	void operator= (Document rhs);
};
