#ifndef _H_MONTH_
#define _H_MONTH_
#include <iostream>

using namespace std;

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

#endif // !_H_MONTH_