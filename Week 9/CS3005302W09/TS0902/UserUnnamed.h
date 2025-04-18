/*****************************************************************//**
 * \file   UserUnnamed.h
 * \brief  The unnamed namespace for valid username
 *
 * \author kai
 * \date   2025/4/18
 *********************************************************************/
#pragma once
#include <iostream>

namespace {
	// The variable to save the username
	std::string username;

	bool isValid() {
		// If there is non-letter in the username than return false
		for (auto i : username) {
			if (i < 'A' || (i > 'Z' && i < 'a') || i > 'z') {
				return false;
			}
		}

		// Return true if the length of username is 8, or return false
		return username.size() == 8;
	}
}
