#include "Form.h"

using namespace std;

void Form::SetInputWord(string inputWord) {
	this->inputWord = inputWord;
}

void Form::ProcessInputWord() {}


void Form::SetFileName(string fileName) {
	this->inputFStream.open("words.txt");
}

void Form::Load_CompareWord() {}

void Form::PrintFoundWords() {}