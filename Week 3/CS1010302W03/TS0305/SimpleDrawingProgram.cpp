#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> board;

void drawOnBoard() {
	for (auto i : board) {
		for (auto j : i) {
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

void drawSquare(int width, int x, int y) {
	if (board.empty() || board[0].empty() || x + width > board[0].size() || y + width > board.size()) {
		cout << "Out of range." << endl;
		return;
	}
	for (int i = y; i < y + width; i++) {
		for (int j = x; j < x + width; j++) {
			board[i][j] = true;
		}
	}
	drawOnBoard();
}

void drawLine(int x1, int y1, int x2, int y2) {
	if (board.empty() || board[0].empty() || x1 < 0 || y1 < 0 || x2 >= board[0].size() || y2 >= board.size()) {
		cout << "Out of range." << endl;
		return;
	}
	if (y1 == y2) { // Horizontal
		for (int i = x1; i <= x2; i++) {
			board[y1][i] = true;
		}
	}
	else if (x1 == x2) { // Vertical
		for (int i = y1; i <= y2; i++) {
			board[i][x1] = true;
		}
	}
	else if (x2 > x1) { // "\"
		for (int i = 0; i <= (x2 - x1); i++) {
			board[y1 + i][x1 + i] = true;
		}
	}
	else { // "/" 3 0 0 3
		for (int i = 0; i <= (x1 - x2); i++) {
			board[y1 + i][x1 - i] = true;
		}
	}
	drawOnBoard();
}

void drawTriangle(int w, int x, int y, string triangleFaces) {
	if (board.empty() || board[0].empty() || x < 0 || y < 0) {
		cout << "Out of range." << endl;
		return;
	}
	if (triangleFaces == "RU") {
		if (x + w > board[0].size() || y - w + 1 < 0) {
			cout << "Out of range." << endl;
			return;
		}
		for (int i = y - w + 1; i <= y; i++) {
			for (int j = x; j <= x + i - (y - w + 1); j++) {
				board[i][j] = true;
			}
		}
	}
	if (triangleFaces == "RD") {
		if (x + w > board[0].size() || y + w > board.size()) {
			cout << "Out of range." << endl;
			return;
		}
		for (int i = y; i <= y + w; i++) {
			for (int j = x; j < x + w - (i - y); j++) {
				board[i][j] = true;
			}
		}
	}
	if (triangleFaces == "LU") {
		if (x - w + 1 < 0 || y - w + 1 < 0) {
			cout << "Out of range." << endl;
			return;
		}
		for (int i = y - w + 1; i <= y; i++) {
			for (int j = x; j >= x - (i - (y - w + 1)); j--) {
				board[i][j] = true;
			}
		}
	}
	if (triangleFaces == "LD") {
		if (x - w + 1 < 0 || y + w > board.size()) {
			cout << "Out of range." << endl;
			return;
		}
		for (int i = y; i < y + w; i++) {
			for (int j = x; j > x - (y + w - i); j--) {
				board[i][j] = true;
			}
		}
	}
	drawOnBoard();
}

int main() {
	int boardWidth, boardHeight;
	cin >> boardWidth >> boardHeight;

	for (int i = 0; i < boardHeight; i++) {
		vector<bool> line;
		for (int j = 0; j < boardWidth; j++) {
			line.push_back(false);
		}
		board.push_back(line);
	}

	string draweType;
	while (cin >> draweType && draweType != "EXIT") {
		if (draweType == "S") {
			int width, x, y;
			cin >> width >> x >> y;
			drawSquare(width, x, y);
		}
		else if (draweType == "L") {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			drawLine(x1, y1, x2, y2);
		}
		else if (draweType == "T") {
			int w, x, y;
			string triangleFaces;
			cin >> w >> x >> y >> triangleFaces;
			drawTriangle(w, x, y, triangleFaces);
		}
		cout << endl;
	}
}