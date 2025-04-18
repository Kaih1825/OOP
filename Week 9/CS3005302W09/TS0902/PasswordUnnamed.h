/*****************************************************************//**
 * \file   PasswordUnnamed.h
 * \brief  The unnamed namespace for valid password
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#pragma once
#include <iostream>

namespace {
	// The variable to save the password
	std::string password;

	/**
	 * Check the password is valid or not
	 *
	 * \return
	 */
	bool isValid() {
		// Return false if the password lenght is less tha 8
		if (password.size() < 8) {
			return false;
		}

		// Return true if the password contains at least one non-letter character.
		for (auto i : password) {
			if (i < 'A' || (i > 'Z' && i < 'a') || i > 'z') {
				return true;
			}
		}

		return false;
	}
}
