/*****************************************************************//**
 * \file   Diary.h
 * \brief  The class to save the current date
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#pragma once
#include "Diary.h"
#include <iostream>
using namespace std;

class Diary
{
public:
	// The current date string
	static string date;
	// Set the current date code
	static void NewDay(string day);
};