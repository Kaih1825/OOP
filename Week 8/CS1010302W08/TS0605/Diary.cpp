/*****************************************************************//**
 * \file   Diary.cpp
 * \brief  Implementation of functions and classes declared in `Diary.h`.
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#include "Diary.h"
#include "Creature.h"
#include <vector>

using namespace std;

// Static variable in class
string Diary::date;

/**
 * Set the current date code
 *
 * \param day The input day code
 */
void Diary::NewDay(string day)
{
	// Set the day
	date = day;

	// Add "Day <day code>" in log of every creatures
	for (auto i : Creature::creatures) {
		i->logs.push_back("Day " + day);
	}
}
