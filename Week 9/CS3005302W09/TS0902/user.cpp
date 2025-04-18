/*****************************************************************//**
 * \file   user.cpp
 * \brief  Handle username input and verify that the username is in the correct format
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#include <iostream>
#include <string>
#include "UserUnnamed.h"

using namespace std;


namespace Authenticate {
	/**
	 * Let user input password
	 *
	 */
	void inputUserName()
	{
		// Let user input until the username is valid
		do
		{
			// Print the hint
			cout << "Enter your username (8 letters only)" << endl;

			// Read user input
			cin >> username;
		} while (!isValid());
	}

	/**
	 * Return the username
	 *
	 * \return The username
	 */
	string getUserName()
	{
		return username;
	}
}
