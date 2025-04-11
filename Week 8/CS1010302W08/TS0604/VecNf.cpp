#include "VecNf.h"
#include <iostream>

VecNf::VecNf() {

}

VecNf::VecNf(float* dest, int cnt) {
	for (int i = 0; i < cnt; i++) {
		this->dest.push_back(dest[i]);
	}
}

VecNf::VecNf(const VecNf& rhs) {
	for (int i = 0; i < rhs.dest.size(); i++) {
		dest.push_back(rhs.dest[i]);
	}
}

int VecNf::Size()
{
	return dest.size();
}

void VecNf::operator=(VecNf rhs) {
	cout << "ASSIGNMENT!!!" << endl;
	dest.clear();
	for (auto i : rhs.dest) {
		dest.push_back(i);
	}
}

void VecNf::operator=(float rhs) {
	cout << "ASSIGNMENT!!!" << endl;
	dest.clear();
	dest.push_back(rhs);
}

float& VecNf::operator[](int index) {
	return dest[index];
}

VecNf VecNf::operator+(VecNf rhs) {
	vector<float> res;

	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		res.push_back(0);
		return VecNf(res.data(), res.size());
	}

	for (int i = 0; i < dest.size(); i++) {
		res.push_back(dest[i] + rhs.dest[i]);
	}

	return VecNf(res.data(), res.size());
}

VecNf VecNf::operator-(VecNf rhs) {
	vector<float> res;
	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		res.push_back(0);
		return VecNf(res.data(), res.size());
	}
	for (int i = 0; i < dest.size(); i++) {
		res.push_back(dest[i] - rhs.dest[i]);
	}

	return VecNf(res.data(), res.size());
}

float VecNf::operator*(VecNf rhs) {
	if (dest.size() != rhs.dest.size()) {
		cout << "dimensions inconsistent\n";
		return 0;
	}

	float sum = 0;
	for (int i = 0; i < dest.size(); i++) {
		sum += dest[i] * rhs.dest[i];
	}

	return sum;
}

VecNf operator*(float lhs, VecNf rhs) {
	vector<float> res;
	for (int i = 0; i < rhs.dest.size(); i++) {
		res.push_back(lhs * rhs.dest[i]);
	}

	return VecNf(res.data(), res.size());
}

VecNf operator*(VecNf lhs, float rhs) {
	vector<float> res;
	for (int i = 0; i < lhs.dest.size(); i++) {
		res.push_back(rhs * lhs.dest[i]);
	}

	return VecNf(res.data(), res.size());
}