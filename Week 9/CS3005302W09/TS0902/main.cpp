/*****************************************************************//**
 * \file   main.cpp
 * \brief  Print user input of user name and password
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#include <iostream>
#include "Authenticate.h"

using namespace std;
using namespace Authenticate;

int main()
{
	// Let user inout user name
	inputUserName();
	// Let user input password
	inputPassword();

	// Output
	cout << "Your username is " << getUserName() <<
		" and your password is: " <<
		getPassword() << endl;

	return 0;
}
