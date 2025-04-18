/*****************************************************************//**
 * \file   NumberGame.h
 * \brief  Declaration of functionsand classes used to determine legitimate numbers in a given list based on the decomposition of an integer.
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class NumberGame {
private:
	// The number user input (A)
	int inputNumber;
	// The splited number of input
	vector<int> numbers;
	// The vector to save the result
	vector<int> result;
	// The file name (S)
	string fileName;
public:
	// set the given integer A
	void SetInput(int n);
	// splitting the integer A into several digits
	void ProcessInput();
	// set the file name of the file where list S is located
	void SetFileName(string fileName);
	// read list S from the file
	void LoadNumberList();
	// print all the valid numbers in S ascendingly
	void PrintAllValid();
	// reset all variables
	void Reset();
};

