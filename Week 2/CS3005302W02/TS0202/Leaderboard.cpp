/*****************************************************************//**
 * \file   Leaderboard.cpp
 * \brief  Read the names and scores data from scores.txt, then print the players' name and score which scores is in top three
 *
 * \author kai
 * \date   2025/2/26
 *********************************************************************/
#include <iostream> // Use in input and output
#include <fstream> // Use in reading file
#include <vector> // Use in list
#include <utility> // Use in pair
#include <algorithm> // Use in sort

using namespace std;

/**
 * Get the name and scores of top three players and sort them
 *
 * \param sortedNames The sorted result of names
 * \param sortedScores The sorted result of scores
 */
void getHighScores(string sortedNames[], int sortedScores[]) {
	// Create the input file stream to read file
	ifstream in;
	// Open the "scores.txt" file
	in.open("scores.txt");

	// If the file is not found, than end thr program
	if (in.fail()) {
		cout << "Not Found";
		return;
	}

	// The vector to save the names and scores in scores.txt
	vector<string> names;
	vector<int> scores;

	// If the ifstream not reading eof, then keep reading names and scores
	while (!in.eof()) {
		// The variable to save the name and score of this reading player
		int score;
		string name;

		// Read the name
		in >> name;

		// If the state flag is not fail, than read the score
		if (!in.fail()) {
			in >> score;
		}

		// If the state flag is not fail, than add the name and score of this player into vector
		if (!in.fail()) {
			names.push_back(name);
			scores.push_back(score);
		}
	}

	// The vector that save name-score pair
	vector<pair<string, int>> nameScorePair;
	// Put the name and score together (using pair) and put in nameScorePair vector
	for (int i = 0; i < names.size(); i++) {
		// Create temporary Pair (only for this player)
		pair<string, int> thisplayer;

		// Put the name to first and score to second element of pair
		thisplayer.first = names[i];
		thisplayer.second = scores[i];

		// Add this pair to nameScorePair
		nameScorePair.push_back(thisplayer);
	}

	// Sort the pair vector according to the score (the second element of each pair), from highest to lowest.
	sort(nameScorePair.begin(), nameScorePair.end(), [](pair<string, int> firstPair, pair<string, int> secondPair) {
		return firstPair.second > secondPair.second;
		});

	// Put the results into sortedNames abd sortedScores arrays
	for (int i = 0; i < 3; i++) {
		sortedNames[i] = nameScorePair[i].first;
		sortedScores[i] = nameScorePair[i].second;
	}

	// Close the input file stream
	in.close();
}

int main() {
	// The variable to save the ressult
	int sortedScores[3];
	string sortedNames[3];

	// Get the name and scores of top three players
	getHighScores(sortedNames, sortedScores);

	// Print thr reaults
	for (int i = 0; i < 3; i++) {
		cout << sortedNames[i] << endl << sortedScores[i] << endl;
	}

	return 0;
}
