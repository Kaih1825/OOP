#include <iostream>

using namespace std;

int main() {
	unsigned long long n;
	while (cin >> n) {
		unsigned long long sec = n % 60;
		unsigned long long min = (n % 3600) / 60;
		unsigned long long hour = n / 3600;
		printf("%lld hours %lld minutes and %lld seconds\n", hour, min, sec);
	}
}
