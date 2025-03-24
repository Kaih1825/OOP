/*****************************************************************//**
 * \file   Form.h
 * \brief  Declaration of the Form class for processing and comparing input words.
 *
 * \author Kai
 * \date   2025/3/24
 *********************************************************************/
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Form
{
private:
	string inputWord; // The word user input
	string fileName; // The name of the file that contains all the valid words
	vector<string> result; // The vector of all result
public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
