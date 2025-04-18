/*****************************************************************//**
 * \file  Authenticate.h
 * \brief The namespace to handle user input of username and passeord
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#pragma once
#include <iostream>

namespace Authenticate
{
	// Input username and check legality
	void inputUserName();
	// Input password and check legality
	void inputPassword();

	// Get Password
	std::string getPassword();
	// Get username
	std::string getUserName();
}
