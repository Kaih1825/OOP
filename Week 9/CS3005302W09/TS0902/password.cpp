/*****************************************************************//**
 * \file   password.cpp
 * \brief  Handle password input and verify that the password is in the correct format
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#include <iostream>
#include <string>
#include "PasswordUnnamed.h"

using namespace std;

namespace Authenticate
{
	/**
	 * Let user input password
	 *
	 */
	void inputPassword()
	{
		// Let user input until the password is valid
		do
		{
			// Print the hint
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;

			// Read user input
			cin >> password;
		} while (!isValid());
	}

	/**
	 * Return the password
	 *
	 * \return The password
	 */
	string getPassword()
	{
		return password;
	}
}
