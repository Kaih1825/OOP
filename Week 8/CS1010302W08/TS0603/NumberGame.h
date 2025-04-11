#pragma once
#include <iostream>
#include <vector>

using namespace std;

class NumberGame {
private:
	int inputNumber;
	vector<int> numbers;
	vector<int> result;
	string fileName;
public:
	void SetInput(int n);
	void ProcessInput();
	void SetFileName(string fileName);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};
