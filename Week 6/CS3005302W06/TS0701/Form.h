#include <string>
#include <fstream>
using namespace std;
class Form
{
private:
	string inputWord;
	ifstream inputFStream;
public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
