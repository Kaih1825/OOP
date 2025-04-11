#include "Creature.h"
#include <string>
#include "Diary.h"

vector<Creature*> Creature::creatures;
Creature::Creature(string name) {
	this->name = name;
	creatures.push_back(this);
	logs.push_back("Day " + Diary::date);
}

Creature::Creature(string name, Creature base) {
	this->name = name;
	for (auto i : base.body) {
		body[i.first] = i.second;
	}
	creatures.push_back(this);
	logs.push_back("Day " + Diary::date);
}

Creature::Proxy Creature::operator[](string index) {
	return Proxy(*this, index);
}


void Creature::Proxy::operator=(int value)
{
	string type;
	if (value == parent.body[index]) {
		return;
	}
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (parent.body[index] > value) {
		type = "decreased";
	}
	else if (parent.body[index] < value) {
		type = "increased";
	}
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(value) + ").";
	parent.body[index] = value;
	parent.logs.push_back(log);
}

void Creature::Proxy::operator+=(int value)
{
	string type;
	if (value == 0) {
		return;
	}
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (value < 0) {
		type = "decreased";
	}
	else if (value > 0) {
		type = "increased";
	}
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(parent.body[index] + value) + ").";
	parent.body[index] += value;
	parent.logs.push_back(log);
}

void Creature::Proxy::operator-=(int value)
{
	string type;
	if (value == 0) {
		return;
	}
	if (parent.body[index] == 0) {
		type = "appeared";
	}
	else if (value > 0) {
		type = "decreased";
	}
	else if (value < 0) {
		type = "increased";
	}
	string log = parent.name + "'s " + index + " " + type + " (" + to_string(parent.body[index]) + " -> " + to_string(parent.body[index] - value) + ").";
	parent.body[index] -= value;
	parent.logs.push_back(log);
}

void Creature::PrintStatus() {
	cout << name << "'s status:\n";
	for (auto i : body) {
		if (i.second != 0) {
			cout << i.first << " * " << i.second << endl;
		}
	}
	cout << endl;
}

void Creature::PrintLog() {
	cout << name << "'s log:\n";
	for (auto i : logs) {
		cout << i << endl;
	}
	cout << endl;
}
