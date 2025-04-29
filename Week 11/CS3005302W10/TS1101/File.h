#pragma once
#include "Document.h"
#include <iostream>

using namespace std;

class File :public Document {
private:
	string pathname;

public:
	File(string body, string pathname);
	string getPathname();
	void setPathname(string pathname);

	void operator= (File rhs);
};
