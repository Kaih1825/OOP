#pragma once
#include <vector>

using namespace std;

class VecNf {
private:
	vector<float> dest;

public:
	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);

	int Size();

	void operator=(VecNf rhs);
	void operator=(float rhs);

	float& operator[](int index);

	VecNf operator+(VecNf rhs);
	VecNf operator-(VecNf rhs);
	float operator*(VecNf rhs);
	friend VecNf operator*(float lhs, VecNf rhs);
	friend VecNf operator*(VecNf lhs, float rhs);
};
