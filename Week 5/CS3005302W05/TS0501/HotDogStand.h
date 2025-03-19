/*****************************************************************//**
 * \file   HotDogStand.h
 * \brief  Declares the HotDogStand class used to simulate the sales activity of a hot dog stand.
 *
 * \author Kai
 * \date   2025/3/18
 *********************************************************************/
#pragma once
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char* id);
	HotDogStand(const char* id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char* standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

