/*****************************************************************//**
 * \file   HotDogStand.cpp
 * \brief  Implementation the functions of HotDogStand class
 *
 * \author Kai
 * \date   2025/3/18
 *********************************************************************/
#include "HotDogStand.h"
#include <iostream>
#include <string>

 //  Static member variable to keep track of total hot dogs sold by all stands
int HotDogStand::totalSellAmount = 0;

/**
 *  Default constructor
 *
 */
HotDogStand::HotDogStand()
{
	// Nothing to initialize here
}

/**
 * Constructor with only stand ID, initializes sold amount to 0
 *
 * \param id The ID of the hot dog stand
 */
HotDogStand::HotDogStand(const char* id)
{
	// Allocate memory and copy the stand ID string
	char* inputId = new char[strlen(id) + 1];

	strcpy_s(inputId, strlen(id) + 1, id);
	standId = inputId;

	// Update sold count for stands
	hotDogSellAmount = 0;
}

/**
 * Constructor with stand ID and initial sold amount
 *
 * \param id The ID of the hot dog stand
 * \param amount The initial number of hot dogs sold
 */
HotDogStand::HotDogStand(const char* id, int amount)
{
	// Allocate memory and copy the stand ID string
	char* inputId = new char[strlen(id) + 1];

	strcpy_s(inputId, strlen(id) + 1, id);
	standId = inputId;

	// Update sold count for stands
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}

/**
 * Destructor - releases dynamically allocated memory for standId
 *
 */
HotDogStand::~HotDogStand()
{
	delete[] standId;
}

/**
 * Simulates selling one hot dog
 * Increments both this stand's and total sold count
 *
 */
void HotDogStand::justSold()
{
	hotDogSellAmount += 1;
	totalSellAmount += 1;
}

/**
 * Prints the stand ID and the number of hot dogs sold by this stand
 *
 */
void HotDogStand::print()
{
	printf("%s %d\n", standId, hotDogSellAmount);
}

/**
 * Returns the number of hot dogs sold by this stand
 *
 * \return The number of hot dogs sold by this stand
 */
int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

/**
 * Returns the total number of hot dogs sold by all stands
 *
 * \return The total number of hot dogs sold by all stands
 */
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}