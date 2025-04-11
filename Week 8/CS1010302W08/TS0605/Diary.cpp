#include "Diary.h"
#include "Creature.h"
#include <vector>

using namespace std;

string Diary::date;
void Diary::NewDay(string day)
{
	date = day;
	for (auto i : Creature::creatures) {
		i->logs.push_back("Day " + day);
	}
}
