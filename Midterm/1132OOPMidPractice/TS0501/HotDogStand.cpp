#include "HotDogStand.h"
#include <iostream>

using namespace std;

int HotDogStand::totalSellAmount;

HotDogStand::HotDogStand()
{
}

HotDogStand::HotDogStand(const char* id)
{
	standId = (char*)id;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount)
{
	standId = (char*)id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	hotDogSellAmount += 1;
	totalSellAmount += 1;
}

void HotDogStand::print()
{
	printf("%s %d\n", standId, hotDogSellAmount);
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
