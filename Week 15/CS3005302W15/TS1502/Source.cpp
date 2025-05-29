/*****************************************************************//**
 * \file   Source.cpp
 * \brief  A library database system to store some information of books
 *
 * \author kai
 * \date   2025/5/30
 *********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Find matching books by title and author, return sorted edition info
 *
 * \param books Find source: [title, author, edition]
 * \param title The title of the book
 * \param author The author of the book
 * \return Find result
 */
string findBook(vector<vector<string> > books, string title, string author) {
	// Vector to store matched books
	vector <vector<string> > foundBooks;

	// Loop through all books to find matches by title and author
	for (auto i : books) {
		if (i[1] == author && i[0] == title) {
			foundBooks.push_back(i);
		}
	}

	// Sort matched books by edition number (as integer)
	sort(foundBooks.begin(), foundBooks.end(), ([](vector<string> p1, vector<string> p2) {
		return atoi(p1[2].c_str()) < atoi(p2[2].c_str());
		}));

	// Result string to return
	string res = "";

	// If no books found, return error message
	if (foundBooks.empty()) {
		res = "Book doesn't exist.\n";
		return res;
	}

	// Construct result string with title, author, and sorted editions
	res += "Title: " + title + "\tAuthor: " + author + "\tEdition: ";
	for (int i = 0; i < foundBooks.size(); i++) {
		res += foundBooks[i][2];
		if (i < foundBooks.size() - 1) {
			res += ", ";
		}
	}

	return res;
}

int main() {
	// The variable to save user input
	string input;
	// The vector to save all books
	vector<vector<string> > books;
	// Regex to extract content excluding double quotes
	regex checkRegex("[^\"]+");

	// Read input until EOF
	while (getline(cin, input)) {
		// Skip empty lines
		if (input.empty()) {
			continue;
		}

		// Extract command keyword
		string command;
		stringstream ss(input);
		ss >> command;

		// Insert Command
		if (command == "Insert") {
			vector<string> book;

			// Parse title and author from input
			for (int i = 0; i < 2; i++) {
				string parseResult = "";
				string buffer;

				while (ss >> buffer) {
					smatch result;
					regex_search(buffer, result, checkRegex);
					parseResult += result.str();
					if (buffer[buffer.size() - 1] == '\"') {
						break;
					}
					parseResult += " ";
				}

				if (parseResult.empty()) {
					break;
				}

				book.push_back(parseResult);
			}

			// Read edition number
			string eddition;
			ss >> eddition;
			book.push_back(eddition);

			// Check for incomplete input
			if (book.size() != 3 || eddition.empty()) {
				cout << "Incomplete Command.\n";
				continue;
			}

			// Check for duplicates
			bool insertSuccess = true;
			for (auto i : books) {
				bool have = true;

				for (int j = 0; j < 3; j++) {
					if (i[j] != book[j]) {
						have = false;
						break;
					}
				}

				if (have) {
					cout << "Datum already exist.\n";
					insertSuccess = false;
					break;
				}
			}

			// Insert if no duplicate
			if (insertSuccess) {
				books.push_back(book);
				cout << "Insert " << book[1] << "\'s " << book[0] << ", Edition: " << book[2] << ".\n";
			}
		}
		// Delete Command
		else if (command == "Delete") {
			string secondCommand;
			ss >> secondCommand;

			// Delete by Edition
			if (secondCommand == "Edition") {
				vector<string> book;

				// Parse title and author
				for (int i = 0; i < 2; i++) {
					string parseResult = "";
					string buffer;

					while (ss >> buffer) {
						smatch result;
						regex_search(buffer, result, checkRegex);
						parseResult += result.str();
						if (buffer[buffer.size() - 1] == '\"') {
							break;
						}
						parseResult += " ";
					}

					if (parseResult.empty()) break;

					book.push_back(parseResult);
				}

				// Parse edition
				string eddition;
				ss >> eddition;
				book.push_back(eddition);

				// Check for incomplete input
				if (book.size() != 3 || eddition.empty()) {
					cout << "Incomplete Command.\n";
					continue;
				}

				// Search and delete matching book
				bool deleteSuccess = false;

				for (int i = 0; i < books.size(); i++) {
					bool isSameBook = true;

					for (int j = 0; j < books[i].size(); j++) {
						if (books[i][j] != book[j]) {
							isSameBook = false;
							break;
						}
					}

					if (isSameBook) {
						books.erase(books.begin() + i);
						cout << "Delete " << book[1] << "\'s " << book[0] << ", Edition: " << book[2] << ".\n";
						deleteSuccess = true;
						break;
					}
				}

				if (!deleteSuccess) {
					cout << "Datum doesn't exist.\n";
				}
			}
			// Delete by Book
			else if (secondCommand == "Book") {
				vector<string> book;

				// Parse title and author
				for (int i = 0; i < 2; i++) {
					string parseResult = "";
					string buffer;

					while (ss >> buffer) {
						smatch result;
						regex_search(buffer, result, checkRegex);
						parseResult += result.str();
						if (buffer[buffer.size() - 1] == '\"') {
							break;
						}
						parseResult += " ";
					}

					if (parseResult.empty()) break;

					book.push_back(parseResult);
				}

				// Check for incomplete input
				if (book.size() != 2) {
					cout << "Incomplete Command.\n";
					continue;
				}

				// Find all matching books
				vector<int> deleteIndax;

				for (int i = books.size() - 1; i >= 0; i--) {
					bool isSame = true;

					for (int j = 0; j < 2; j++) {
						if (books[i][j] != book[j]) {
							isSame = false;
						}
					}

					if (isSame) {
						deleteIndax.push_back(i);
					}
				}

				// Delete matching books
				for (auto i : deleteIndax) {
					books.erase(books.begin() + i);
				}

				if (deleteIndax.size() != 0) {
					cout << "Delete " << book[1] << "\'s " << book[0] << ".\n";
				}
				else {
					cout << "Book doesn't exist.\n";
				}
			}
		}
		// Find Command
		else if (command == "Find") {
			string secondCommand;
			ss >> secondCommand;

			// Find by Book
			if (secondCommand == "Book") {
				vector<string> book;

				// Parse title and author
				for (int i = 0; i < 2; i++) {
					string parseResult = "";
					string buffer;

					while (ss >> buffer) {
						smatch result;
						regex_search(buffer, result, checkRegex);
						parseResult += result.str();
						if (buffer[buffer.size() - 1] == '\"') {
							break;
						}
						parseResult += " ";

					}

					if (parseResult.empty()) break;

					book.push_back(parseResult);
				}

				// Check for incomplete input
				if (book.size() != 2) {
					cout << "Incomplete Command.\n";
					continue;
				}

				// Output found result
				cout << findBook(books, book[0], book[1]) << endl;

			}
			// Find by Author
			else if (secondCommand == "Author") {
				string author = "";
				string buffer;

				// Parse author
				while (ss >> buffer) {
					smatch result;
					regex_search(buffer, result, checkRegex);
					author += result.str();
					if (buffer[buffer.size() - 1] == '\"') {
						break;
					}
					author += " ";
				}

				// Check for incomplete input
				if (author.empty()) {
					cout << "Incomplete Command.\n";
					continue;
				}

				// Search for titles of this author
				set<string> searchResult;
				for (auto i : books) {
					if (i[1] == author) {
						searchResult.insert(i[0]);
					}
				}

				if (searchResult.empty()) {
					cout << "No book found.\n";
					continue;
				}

				// Print the result
				cout << author << "'s Books: ";
				for (auto i = searchResult.begin(); i != searchResult.end(); i++) {
					cout << *i;
					if (next(i) != searchResult.end()) {
						cout << ", ";
					}
				}
				cout << endl;
			}
		}
		// Sort Commands
		else if (input == "Sort by Title") {
			// Sort by title then author
			sort(books.begin(), books.end(), [](vector<string> p1, vector<string> p2) {
				if (p1[0] == p2[0]) {
					return p1[1] < p2[1];
				}

				return p1[0] < p2[0];
				});

			// Deduplicate and print sorted book info
			vector<string> searchResult;

			for (auto i : books) {
				string foundResult = findBook(books, i[0], i[1]);

				if (find(searchResult.begin(), searchResult.end(), foundResult) == searchResult.end()) {
					searchResult.push_back(foundResult);
				}
			}

			// Print the result
			for (auto i : searchResult) {
				cout << i << endl;
			}
		}
		else if (input == "Sort by Author") {
			// Sort by author then title
			sort(books.begin(), books.end(), [](vector<string> p1, vector<string> p2) {
				if (p1[1] == p2[1]) {
					return p1[0] < p2[0];
				}

				return p1[1] < p2[1];
				});

			// Deduplicate and print sorted book info
			vector<string> searchResult;

			for (auto i : books) {
				string foundResult = findBook(books, i[0], i[1]);

				if (find(searchResult.begin(), searchResult.end(), foundResult) == searchResult.end()) {
					searchResult.push_back(foundResult);
				}
			}

			// Print the result
			for (auto i : searchResult) {
				cout << i << endl;
			}
		}
		else {
			// Unknown Command
			cout << "Unknown Command." << endl;
		}

	}
}
