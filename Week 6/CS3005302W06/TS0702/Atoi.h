/*****************************************************************//**
 * \file   Atoi.h
 * \brief  Declaration of the Atoi class for converting a string into an integer
 *
 * \author kai
 * \date   2025/3/25
 *********************************************************************/
#include <string>

using namespace std;

class Atoi {

private:
	string beTrans; // Store the original string value

public:
	Atoi(); // Construct a class Atoi where beTran is ""
	Atoi(string s); // Construct a class Atoi where beTran is s
	void SetString(string s); // Set beTran of this class to s
	const string GetString(); // Return beTran of this class
	int Length(); // Return the length of beTran
	bool IsDigital(); // Return true if beTran can be transformed into an integer, otherwise return false
	int StringToInteger(); // Convert beTran to an integerand return
};