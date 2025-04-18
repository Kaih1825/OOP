/*****************************************************************//**
 * \file   VecNf.h
 * \brief  A class named VecNf to store a multidimensional vector and implement some simple vector operations
 *
 * \author Kai
 * \date   2025/4/11
 *********************************************************************/
#pragma once
#include <vector>

using namespace std;

class VecNf {
private:
	// The vector of user input
	vector<float> dest;

public:
	// Construct a one-dimensional zero vector in default
	VecNf();
	// Construct a cnt dimensional vector using the first cnt  numbers in dest
	VecNf(float* dest, int cnt);
	// Construct a new vector from a VecNf
	VecNf(const VecNf& rhs);

	// The size of vector <dest> (dimensional)
	int Size();

	// Assign the value (vector -> vector)
	void operator=(VecNf rhs);
	// Assign the value (float -> vector)
	void operator=(float rhs);

	// Return the value of the certain dimension variable in the vector
	float& operator[](int index);

	// Implement the addition of two vectors
	VecNf operator+(VecNf rhs);
	// Implement the subtraction of two vectors.
	VecNf operator-(VecNf rhs);
	// Implement the Inner product of two vectors. (define operator *)
	float operator*(VecNf rhs);

	// float * vector (scalar multiplication)
	friend VecNf operator*(float lhs, VecNf rhs);
	// vector * float (scalar multiplication)
	friend VecNf operator*(VecNf lhs, float rhs);
};
