/*****************************************************************//**
 * \file   Creature.cpp
 * \brief  Implementations for Creature and Proxy class methods
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#include "Creature.h"
#include <string>
#include "Diary.h"

 // Static container to track all created creatures
vector<Creature*> Creature::creatures;

/**
 * Constructor that sets name and logs creation date
 *
 * \param name Creature name
 */
Creature::Creature(string name) {
	// Assign creature name
	this->name = name;

	// Register this creature in the global creature list
	creatures.push_back(this);

	// Log creation date using Diary's current date
	logs.push_back("Day " + Diary::date);
}

/**
 * Constructor that copies body attributes from base Creature
 *
 * \param name Creature name
 * \param base Base Creature
 */
Creature::Creature(string name, Creature base) {
	// Assign creature name
	this->name = name;

	// Copy all body attributes from the base creature
	for (auto i : base.body) {
		body[i.first] = i.second;
	}

	// Register this creature in the global creature list
	creatures.push_back(this);

	// Log creation date using Diary's current date
	logs.push_back("Day " + Diary::date);
}

/**
 * Returns a Proxy object for attribute access
 *
 * \param index Attribute name
 * \return Proxy object
 */
Creature::Proxy Creature::operator[](string index) {
	// Return a proxy to access the specified attribute
	return Proxy(*this, index);
}

/**
 * Assign a value to a body attribute and log the change
 *
 * \param value New attribute value
 */
void Creature::Proxy::operator=(int value)
{
	// Store type of change: appeared, increased, decreased
	string type;
	if (value == parent.body[index]) {
		return;
	}

	// Determine the type of change based on previous value
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (parent.body[index] > value) {
		type = "decreased";
	}
	else if (parent.body[index] < value) {
		type = "increased";
	}

	// Construct log message
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(value) + ").";

	// Apply new value to attribute
	parent.body[index] = value;

	// Append log message to creature's log
	parent.logs.push_back(log);
}

/**
 * Increment a body attribute and log the change
 *
 * \param value Increment value
 */
void Creature::Proxy::operator+=(int value)
{
	// Store type of change: appeared, increased, decreased
	string type;

	// No change; skip logging
	if (value == 0) {
		return;
	}

	// Determine type based on current value and increment
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (value < 0) {
		type = "decreased";
	}
	else if (value > 0) {
		type = "increased";
	}

	// Construct log message
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(parent.body[index] + value) + ").";

	// Apply increment to attribute
	parent.body[index] += value;

	// Append log to creature's log
	parent.logs.push_back(log);
}

/**
 * Decrement a body attribute and log the change
 *
 * \param value Decrement value
 */
void Creature::Proxy::operator-=(int value)
{
	// Store type of change: appeared, increased, decreased
	string type;

	// No change; skip logging
	if (value == 0) {
		return;
	}

	// Determine type based on value direction
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (value > 0) {
		type = "decreased";
	}
	else if (value < 0) {
		type = "increased";
	}

	// Construct log message
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(parent.body[index] - value) + ").";

	// Apply decrement to attribute
	parent.body[index] -= value;

	// Append log to creature's log
	parent.logs.push_back(log);
}

/**
 * Print all non-zero body attributes to console
 *
 */
void Creature::PrintStatus() {
	// Output creature's name
	cout << name << "'s status:\n";

	// Iterate through all body attributes
	for (auto i : body) {
		// Only print non-zero attributes
		if (i.second != 0) {
			cout << i.first << " * " << i.second << endl;
		}
	}

	// Print an empty line for spacing
	cout << endl;
}

/**
 * Print the creature's action log to console
 *
 */
void Creature::PrintLog() {
	// Output creature's name
	cout << name << "'s log:\n";

	// Print all log entries
	for (auto i : logs) {
		cout << i << endl;
	}

	// Print an empty line for spacing
	cout << endl;
}
