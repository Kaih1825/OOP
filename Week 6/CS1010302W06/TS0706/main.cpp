/*****************************************************************//**
 * \file   main.cpp
 * \brief  Determine whether the given pair is legal according to the rules of Shisensho
 *
 * \author kai
 * \date   2025/3/28
 *********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// The struct of the point
struct point {
	int x = 0; // The x value of the point
	int y = 0; // The y value of the point
	int value = 0; // The value of the point
	int deep = 0; // The deep of the point
};

int main() {
	// The table of the Shisensho
	vector<vector<int> > table(8, vector<int>(8, 0));

	// The variable to judge the table is valid or not
	bool error = false;

	// Let user input the table
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			// The variable to save user input
			int num;

			// User input
			cin >> num;

			// Check if the user input is valid or not
			if (num < 0 || num>9) {
				cout << "bad pair" << endl;
				error = true;
				break;
			}

			// Set the table
			table[i][j] = num;
		}
	}

	// Return if the table is not valid
	if (error) {
		return 0;
	}

	// The direction of inspection
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	// The variable to save user input (the coordinates of the point)
	int x1, y1, x2, y2;

	// Let user input until EOF
	while (cin >> x1 >> y1 >> x2 >> y2) {
		// Check if the user input is valid or not
		if (x1 < 0 || x1>6 || y1 < 0 || y1>6 || x2 < 0 || x2>6 || y2 < 0 || y2>6) {
			cout << "bad pair" << endl;
			continue;
		}

		// The queue use in BFS
		vector<point> queue;

		// Convert the user input into points
		point pos1 = { x1 + 1,y1 + 1,table[y1 + 1][x1 + 1],0 };
		point pos2 = { x2 + 1,y2 + 1,table[y2 + 1][x2 + 1],0 };

		// Check if the user input is valid or not
		if (pos1.value != pos2.value || (x1 == x2 && y1 == y2)) {
			cout << "bad pair" << endl;
			continue;
		}

		// The root of the tree of BFS is pos1
		queue.push_back(pos1);

		// BFS
		for (int i = 0; i < queue.size(); i++) {
			// Break if the deep is >= 3
			if (queue[i].deep >= 3) {
				break;
			}

			// Ignore search if the value of the node is not 0 (space)
			if (queue[i].value != 0 && i != 0) {
				continue;
			}

			// Check the point of 4 direction that is the child of the node
			for (int j = 0; j < 4; j++) {
				// Continuous Inspection
				for (int k = 1; k < 9; k++) {
					//Displacement value
					int dxk = dx[j] * k;
					int dyk = dy[j] * k;

					// Check the point is out of range or not
					if (queue[i].x + dxk >= 0 && queue[i].x + dxk < 8 && queue[i].y + dyk >= 0 && queue[i].y + dyk < 8) {
						// The point we found
						point finded = { queue[i].x + dxk ,queue[i].y + dyk ,table[queue[i].y + dyk][queue[i].x + dxk],queue[i].deep + 1 };

						// If the value of the point on the left is not 0, than the point is not valid
						if (k > 1 && table[queue[i].y + dy[j] * (k - 1)][queue[i].x + dx[j] * (k - 1)] != 0) {
							break;
						}

						// Check if the point is in the queue or not
						bool has = false;

						for (auto k : queue) {
							if (k.x == finded.x && k.y == finded.y) {
								has = true;
								break;
							}
						}

						// If there is no same point in the queue, than push the point nto the queue
						if (!has) {
							queue.push_back(finded);
						}
					}
					else {
						break;
					}
				}
			}
		}
		// The variable to save the state of legal or not legal
		bool success = false;

		// Find the point in queue
		for (auto i : queue) {
			// If there is the point, than change the table[pos1.y][pos1.x] and table[pos2.y][pos2.x] into 0 (space)
			if (i.x == pos2.x && i.y == pos2.y && i.deep <= 3 && i.value != 0) {
				// Print the result
				cout << "pair matched" << endl;

				table[pos1.y][pos1.x] = 0;
				table[pos2.y][pos2.x] = 0;

				success = true;
			}
		}

		// If it is not legal, than print "bad pair"
		if (!success) {
			cout << "bad pair" << endl;
		}
	}
}
