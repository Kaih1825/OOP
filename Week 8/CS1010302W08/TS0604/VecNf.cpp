/*****************************************************************//**
 * \file   VecNf.cpp
 * \brief  Implementation of functions and classes declared in `VecNf.h`.
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#include "VecNf.h"
#include <iostream>

 /**
  * Construct a one-dimensional zero vector in default.
  *
  */
VecNf::VecNf() {

}

/**
 * Construct a cnt dimensional vector using the first cnt  numbers in dest.
 *
 * \param dest The input float pointer array (vector)
 * \param cnt The size of dest
 */
VecNf::VecNf(float* dest, int cnt) {
	// Save the input array into the vector
	for (int i = 0; i < cnt; i++) {
		this->dest.push_back(dest[i]);
	}
}

/**
 * Construct a new vector from a VecNf.
 *
 * \param rhs The source vector
 */
VecNf::VecNf(const VecNf& rhs) {
	// Save the array in rhs into the vector
	for (int i = 0; i < rhs.dest.size(); i++) {
		dest.push_back(rhs.dest[i]);
	}
}

/**
 * The size of vector <dest> (dimensional)
 *
 * \return The size of vector <dest> (dimensional)
 */
int VecNf::Size()
{
	return dest.size();
}

/**
 * Assign the value (vector -> vector)
 *
 * \param rhs The source vector
 */
void VecNf::operator=(VecNf rhs) {
	cout << "ASSIGNMENT!!!" << endl;

	// Clear the vector in this
	dest.clear();

	// Save the vector in rhs into vector (dest)
	for (auto i : rhs.dest) {
		dest.push_back(i);
	}
}

/**
 * Assign the value (float -> vector)
 *
 * \param rhs The source float
 */
void VecNf::operator=(float rhs) {
	cout << "ASSIGNMENT!!!" << endl;

	// Clear the vector in this
	dest.clear();

	// Save the float(rhs) into vector (dest)
	dest.push_back(rhs);
}

/**
 * Return the value of the certain dimension variable in the vector
 *
 * \param index The index of dest
 * \return The value of the certain dimension variable in the vector
 */
float& VecNf::operator[](int index) {
	return dest[index];
}

/**
 * Implement the addition of two vectors
 *
 * \param rhs The right-hand-sidde of the addition
 * \return The addition result
 */
VecNf VecNf::operator+(VecNf rhs) {
	// The variable to save the result
	vector<float> res;

	// For any arithmetic operator, the two VecNf must have the same dimensional. If they are not, print "dimensions inconsistent" and return 0.
	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		res.push_back(0);
		return VecNf(res.data(), res.size());
	}

	//  Add two vector
	for (int i = 0; i < dest.size(); i++) {
		res.push_back(dest[i] + rhs.dest[i]);
	}

	// Return the vector
	return VecNf(res.data(), res.size());
}

/**
 * Implement the subtraction of two vectors.
 *
 * \param rhs The right-hand-side of the subtraction
 * \return The subtraction result
 */
VecNf VecNf::operator-(VecNf rhs) {
	// The variable to save the result
	vector<float> res;

	// For any arithmetic operator, the two VecNf must have the same dimensional. If they are not, print "dimensions inconsistent" and return 0.
	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		res.push_back(0);
		return VecNf(res.data(), res.size());
	}

	//  Minus two vector
	for (int i = 0; i < dest.size(); i++) {
		res.push_back(dest[i] - rhs.dest[i]);
	}

	// Return the vector
	return VecNf(res.data(), res.size());
}

/**
 * Implement the Inner product of two vectors. (define operator *)
 *
 * \param rhs The right-hand-side of the Inner product
 * \return The Inner product result
 */
float VecNf::operator*(VecNf rhs) {
	// For any arithmetic operator, the two VecNf must have the same dimensional. If they are not, print "dimensions inconsistent" and return 0.
	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		return 0;
	}

	// The variable to save the compute result
	float sum = 0;

	// Compute the Inner product
	for (int i = 0; i < dest.size(); i++) {
		sum += dest[i] * rhs.dest[i];
	}

	// Return the result
	return sum;
}

/**
 * float * vector (scalar multiplication)
 *
 * \param lhs The left-hand-side (float)
 * \param rhs The right-hand-side (vector)
 * \return The scalar multiplication of a floating-point number and a vector
 */
VecNf operator*(float lhs, VecNf rhs) {
	// The variable to save the result
	vector<float> res;

	// Compute the result
	for (int i = 0; i < rhs.dest.size(); i++) {
		res.push_back(lhs * rhs.dest[i]);
	}

	// Return the result
	return VecNf(res.data(), res.size());
}

/**
 * vector * float (scalar multiplication)
 *
 * \param lhs The left-hand-side (vector)
 * \param rhs The right-hand-side (float)
 * \return The scalar multiplication of a floating-point number and a vector
 */
VecNf operator*(VecNf lhs, float rhs) {
	// The variable to save the result
	vector<float> res;

	// Compute the result
	for (int i = 0; i < lhs.dest.size(); i++) {
		res.push_back(rhs * lhs.dest[i]);
	}

	// Return the result
	return VecNf(res.data(), res.size());
}