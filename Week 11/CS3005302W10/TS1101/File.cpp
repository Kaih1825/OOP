#include "File.h"

File::File(string body, string pathname) :Document(body) {
	this->pathname = pathname;
}

string File::getPathname() {
	return pathname;
}

void File::setPathname(string pathname) {
	this->pathname = pathname;
}

void File::operator= (File rhs) {
	setText(rhs.getText());
	this->pathname = rhs.pathname;
}