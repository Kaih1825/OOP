/*****************************************************************//**
 * \file   PrintCombination.h
 * \brief  Declaration of the PrintCombination function
 *
 * \author kai
 * \date   2025/4/26
 *********************************************************************/
#pragma once

#include <vector>
#include <set>

#define NULL nullptr

using namespace std;

// Print all possible combinations of a given number of elements chosen from the array.
void PrintCombination(int* arrayPtr, int arraySize, int choice);
