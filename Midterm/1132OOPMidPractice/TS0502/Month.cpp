#include "Month.h"
Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	string input = { first,second,third };
	if (input == "Jan") {
		month = 1;
	}
	else if (input == "Jan") {
		month = 1;
	}
	else if (input == "Feb") {
		month = 2;
	}
	else if (input == "Mar") {
		month = 3;
	}
	else if (input == "Apr") {
		month = 4;
	}
	else if (input == "May") {
		month = 5;
	}
	else if (input == "Jun") {
		month = 6;
	}
	else if (input == "Jul") {
		month = 7;
	}
	else if (input == "Aug") {
		month = 8;
	}
	else if (input == "Sep") {
		month = 9;
	}
	else if (input == "Oct") {
		month = 10;
	}
	else if (input == "Nov") {
		month = 11;
	}
	else if (input == "Dec") {
		month = 12;
	}
	else {
		month = 1;
	}
}

Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12) {
		month = 1;
	}
	else {
		month = monthInt;
	}
}


Month::~Month()
{

}

void Month::inputInt()
{
	int monthInt;
	cin >> monthInt;
	if (monthInt < 1 || monthInt > 12) {
		month = 1;
	}
	else {
		month = monthInt;
	}
}

void Month::inputStr()
{
	char first, second, third;
	cin >> first >> second >> third;
	string input = { first,second,third };
	if (input == "Jan") {
		month = 1;
	}
	else if (input == "Jan") {
		month = 1;
	}
	else if (input == "Feb") {
		month = 2;
	}
	else if (input == "Mar") {
		month = 3;
	}
	else if (input == "Apr") {
		month = 4;
	}
	else if (input == "May") {
		month = 5;
	}
	else if (input == "Jun") {
		month = 6;
	}
	else if (input == "Jul") {
		month = 7;
	}
	else if (input == "Aug") {
		month = 8;
	}
	else if (input == "Sep") {
		month = 9;
	}
	else if (input == "Oct") {
		month = 10;
	}
	else if (input == "Nov") {
		month = 11;
	}
	else if (input == "Dec") {
		month = 12;
	}
	else {
		month = 1;
	}
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	string output;
	if (month == 1) {
		output = "Jan";
	}
	else if (month == 2) {
		output = "Feb";
	}
	else if (month == 3) {
		output = "Mar";
	}
	else if (month == 4) {
		output = "Apr";
	}
	else if (month == 5) {
		output = "May";
	}
	else if (month == 6) {
		output = "Jun";
	}
	else if (month == 7) {
		output = "Jul";
	}
	else if (month == 8) {
		output = "Aug";
	}
	else if (month == 9) {
		output = "Sep";
	}
	else if (month == 10) {
		output = "Oct";
	}
	else if (month == 11) {
		output = "Nov";
	}
	else if (month == 12) {
		output = "Dec";
	}
	else {
		output = "Jan";
	}

	cout << output;
}

Month Month::nextMonth()
{
	int tm = month;
	Month next(tm + 1);
	return next;
}
