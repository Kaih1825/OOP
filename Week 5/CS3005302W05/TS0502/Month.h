/*****************************************************************//**
 * \file   Month.h
 * \brief  Declares the Month class used to display the formatted month
 *
 * \author Kai
 * \date   2025/3/19
 *********************************************************************/
#pragma once
class Month
{
public:
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);
	~Month();

	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	Month nextMonth();
private:
	int month;
};

