#include "Diary.h"
#include "Creature.h"

int main() {

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 0;
	unknownB["leg"] -= 0;
	unknownB["leg"] = 16;
	unknownB.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0000");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA.PrintLog();

}
