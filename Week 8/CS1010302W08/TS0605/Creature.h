#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Creature {
private:
	map<string, int> body;
	string name;

	class Proxy {
		Creature& parent;
		string index;
	public:
		Proxy(Creature& c, string i) :parent(c), index(i) {};
		void operator= (int value);
		void operator+= (int value);
		void operator-= (int value);
	};

public:
	static vector<Creature*> creatures;
	vector<string> logs;
	Creature(string name);
	Creature(string name, Creature base);

	Proxy operator[](string index);

	void PrintStatus();
	void PrintLog();

};
