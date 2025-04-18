/*****************************************************************//**
 * \file   Creature.h
 * \brief  Define the Creature class and its Proxy for attribute access
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Creature {
private:
	// Stores body attributes with corresponding integer values
	map<string, int> body;
	// Creature name
	string name;

	// Proxy class for modifying body attributes using [] operator
	class Proxy {
		// Reference to parent Creature
		Creature& parent;
		// Attribute name being accessed
		string index;
	public:
		// Constructor
		Proxy(Creature& c, string i) :parent(c), index(i) {};

		// Assign a value to a body part in Creature
		void operator= (int value);
		// Increase the number of specified body parts in Creature
		void operator+= (int value);
		// Reduce the number of specified body parts in Creature
		void operator-= (int value);
	};

public:
	// Global list of all created Creature objects
	static vector<Creature*> creatures;
	// Action logs of the Creature
	vector<string> logs;

	// Constructor with name
	Creature(string name);
	// Constructor with name and base Creature
	Creature(string name, Creature base);

	// Access attribute via Proxy
	Proxy operator[](string index);

	// Print current body attributes
	void PrintStatus();
	// Print action logs
	void PrintLog();

};
