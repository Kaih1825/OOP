/*****************************************************************//**
 * \file   Template.h
 * \brief  Binary Search using template, and provide both iterative and recursive versions.
 *
 * \author kai
 * \date   2025/5/24
 *********************************************************************/
#pragma once

 /**
   * Perform an iterative binary search on a sorted array.
   *
   * \param a        The array to search
   * \param first    The starting index of the search range
   * \param last     The ending index of the search range
   * \param key      The value to search for
   * \param found    A boolean indicating if key was found
   * \param location The index of the key if found
   */
template<typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	// Check if the first element matches the key
	if (a[first] == key) {
		location = first;
		found = true;
		return;
	}

	// Check if the last element matches the key
	else if (a[last] == key) {
		location = last;
		found = true;
		return;
	}

	// Loop until the range collapses
	while (first != last) {
		// Calculate the middle index
		int middle = (last - first) / 2 + first;

		// Stop if only two elements left and not equal
		if (last - first <= 1 && a[middle] != key) {
			found = false;
			return;
		}

		// If key is smaller than middle, move left
		if (a[middle] > key) {
			last = middle;
		}
		// If key is larger than middle, move right
		else if (a[middle] < key) {
			first = middle;
		}
		// Found the key
		else {
			location = middle;
			found = true;
			return;
		}
	}
}

/**
	* Perform an iterative binary search on a sorted array.
	*
	* \param a        The array to search
	* \param first    The starting index of the search range
	* \param last     The ending index of the search range
	* \param key      The value to search for
	* \param found    A boolean indicating if key was found
	* \param location The index of the key if found
	*/
template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	// Check if the first element matches the key
	if (a[first] == key) {
		location = first;
		found = true;
		return;
	}
	// Check if the last element matches the key
	else if (a[last] == key) {
		location = last;
		found = true;
		return;
	}

	// Base case: range is invalid
	if (first == last) {
		found = false;
		return;
	}

	// Calculate the middle index
	int middle = (last - first) / 2 + first;

	// Stop if only two elements left and not equal
	if (last - first <= 1 && a[middle] != key) {
		found = false;
		return;
	}

	// If key is smaller than middle, recurse left
	if (a[middle] > key) {
		return RecBinarySearch(a, first, middle, key, found, location);
	}
	// If key is larger than middle, recurse right
	else if (a[middle] < key) {
		return RecBinarySearch(a, middle, last, key, found, location);
	}
	// Found the key
	else {
		location = middle;
		found = true;
		return;
	}
}
