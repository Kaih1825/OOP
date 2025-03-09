/*****************************************************************//**
 * \file   SimpleDrawingProgram.cpp
 * \brief  A simple drawing program allow users to draw square, isosceles right triangle and lines on the console.
 *
 * \author kai
 * \date   2025/3/8
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// The variable to save the board state
vector<vector<bool>> board;

/**
 * The function to print the board on the console
 * When the value in the board vector is true, it will print "X"; otherwise, it will print "*".
 *
 */
void drawOnBoard() {
	// Get the each line in board (y-axis)
	for (auto i : board) {
		// Get the each value in the line (x-axis)
		for (auto j : i) {
			// Print the symbol on the board
			if (j) {
				cout << "X";
			}
			else {
				cout << "*";
			}
		}
		cout << "\n";
	}
}

/**
 * Draw the square on board
 *
 * \param width The width of the square
 * \param x The x value of the Top-Left point (origin point)
 * \param y The y value of the Top-Left point (origin point)
 */
void drawSquare(int width, int x, int y) {
	// Determine if the square is outside the specified range.
	if (board.empty() || board[0].empty() || x + width > board[0].size() || y + width > board.size()) {
		cout << "Out of range." << endl;
		return;
	}

	// Eeach line of the square
	for (int i = y; i < y + width; i++) {
		// Each point of the line
		for (int j = x; j < x + width; j++) {
			// Set the point in the board to True.
			board[i][j] = true;
		}
	}

	// Print the board on the console
	drawOnBoard();
}

/**
 * Draw the line on board
 *
 * \param x1,y1 The (x,y) value of the First point of line
 * \param x2,y2 The (x,y) value of the Second point of line
 */
void drawLine(int x1, int y1, int x2, int y2) {
	// Determine if the line is outside the specified range.
	if (board.empty() || board[0].empty() || x1 < 0 || y1 < 0 || x2 >= board[0].size() || y2 >= board.size()) {
		cout << "Out of range." << endl;
		return;
	}


	// If the second point is lower than the first point, than switch the point
	if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 > y2) || (x1 == x2 && y1 > y2) || (y1 == y2 && x1 > x2)) {
		// The variable is save the temp variable
		int tmp = x1;
		x1 = x2;
		x2 = tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if (y1 == y2) {     // Draw the line of "-"
		// Draw from left to right
		for (int i = x1; i <= x2; i++) {
			board[y1][i] = true;
		}
	}
	else if (x1 == x2) { // The line of "|"
		// Draw from top to bottom
		for (int i = y1; i <= y2; i++) {
			board[i][x1] = true;
		}
	}
	else if (x2 > x1) { // The line of "\"
		// Draw from left-top to right-bottom
		for (int i = 0; i <= (x2 - x1); i++) {
			board[y1 + i][x1 + i] = true;
		}
	}
	else {			    // The line of "\"
		// Draw from right-top to left-bottom
		for (int i = 0; i <= (x1 - x2); i++) {
			board[y1 + i][x1 - i] = true;
		}
	}

	// Print the board on the console
	drawOnBoard();
}

/**
 * Draw the triangle on board
 *
 * \param w The side length of the triangle
 * \param x The x value of the origin point
 * \param y The y value of the origin point
 * \param triangleFaces The side that the triangle faces
 */
void drawTriangle(int w, int x, int y, string triangleFaces) {
	// Determine if the triangle is outside the specified range.
	if (board.empty() || board[0].empty() || x < 0 || y < 0) {
		cout << "Out of range." << endl;
		return;
	}

	// The triangle is face to right up
	if (triangleFaces == "RU") {
		// Determine if the triangle is outside the specified range.
		if (x + w > board[0].size() || y - w + 1 < 0) {
			cout << "Out of range." << endl;
			return;
		}

		// Draw the trigangle from top to bottom
		for (int i = y - w + 1; i <= y; i++) {
			for (int j = x; j <= x + i - (y - w + 1); j++) {
				board[i][j] = true;
			}
		}
	}

	// The triangle is face to right down
	if (triangleFaces == "RD") {
		// Determine if the triangle is outside the specified range.
		if (x + w > board[0].size() || y + w > board.size()) {
			cout << "Out of range." << endl;
			return;
		}

		// Draw the trigangle from top to bottom
		for (int i = y; i <= y + w; i++) {
			for (int j = x; j < x + w - (i - y); j++) {
				board[i][j] = true;
			}
		}
	}

	// The triangle is face to left up
	if (triangleFaces == "LU") {
		// Determine if the triangle is outside the specified range.
		if (x - w + 1 < 0 || y - w + 1 < 0) {
			cout << "Out of range." << endl;
			return;
		}

		// Draw the trigangle from top to bottom
		for (int i = y - w + 1; i <= y; i++) {
			for (int j = x; j >= x - (i - (y - w + 1)); j--) {
				board[i][j] = true;
			}
		}
	}

	// The triangle is face to left down
	if (triangleFaces == "LD") {
		// Determine if the triangle is outside the specified range.
		if (x - w + 1 < 0 || y + w > board.size()) {
			cout << "Out of range." << endl;
			return;
		}

		// Draw the trigangle from top to bottom
		for (int i = y; i < y + w; i++) {
			for (int j = x; j > x - (y + w - i); j--) {
				board[i][j] = true;
			}
		}
	}

	// Print the board on the console
	drawOnBoard();
}

int main() {
	// The variable to save the board width and height
	int boardWidth, boardHeight;

	// Let user to input the width and height of the board
	cin >> boardWidth >> boardHeight;

	// Generate each line of the board
	for (int i = 0; i < boardHeight; i++) {
		// The variable to save the line
		vector<bool> line;

		// Generate the each point og the line
		for (int j = 0; j < boardWidth; j++) {
			line.push_back(false);
		}

		// Put the line into the board
		board.push_back(line);
	}

	// The variable to save the type of the figure
	string drawType;

	// Let user input type of figure until user input EXIT
	while (cin >> drawType && drawType != "EXIT") {
		// User input S stand for square
		if (drawType == "S") {
			// The variable to save the width of the square and the origin point
			int width, x, y;

			// Let user input the width of the square and the origin point
			cin >> width >> x >> y;

			// Draw the square
			drawSquare(width, x, y);
		}

		// User input S stand for line
		else if (drawType == "L") {
			// The variable to save the position of the first and second point of the line
			int x1, y1, x2, y2;

			// Let user input the first and second point of the line
			cin >> x1 >> y1 >> x2 >> y2;

			// Draw the line
			drawLine(x1, y1, x2, y2);
		}

		// User input S stand for triangle
		else if (drawType == "T") {
			// The variable to save the width and the origin point of the triangle
			int w, x, y;
			// The variable to save the face of the triangle
			string triangleFaces;

			// Let user input the width, the origin point and the face of the triangle
			cin >> w >> x >> y >> triangleFaces;

			// Draw the triangle
			drawTriangle(w, x, y, triangleFaces);
		}
		cout << endl;
	}

	return 0;
}