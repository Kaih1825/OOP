#include <iostream>
#include <vector>

using namespace std;

int main() {
	int count;
	while (cin >> count) {
		vector<double> in;
		double sum = 0;
		for (int i = 0; i < count; i++) {
			double input;
			cin >> input;
			in.push_back(input);
			sum += input;
		}
		double av = sum / in.size();
		sum = 0;
		for (int i = 0; i < count; i++) {
			sum += pow(in[i] - av, 2);
		}
		double sd = sum / in.size();

		printf("Average:%g\tStandard deviation:%g\n", av, sqrt(sd));
	}
}
