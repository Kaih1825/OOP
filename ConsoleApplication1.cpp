#include <iostream>
#include <math.h>
using namespace std;

#define noTLE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

double factorial(double n) {
	/*if (n == 1 || n == 0) {
		return 1;
	}
	return log10(n) + factorial(n - 1);*/
	double ans=0;
	for (unsigned long long i = 1; i <= n; i++) {
		ans += log10(i);
	}
	return ans;
}

int main()
{
	//noTLE;

	unsigned long long n, k;
	while (scanf_s("%llu %llu",&n,&k)!= EOF) {
		if (n == k) {
			cout << 1 << endl;
			continue;
		}
		double ans = (factorial(n)) - (factorial(k) + factorial(n - k));
		//cout << ceil(ans);
		printf("%.0f", ans + 1);
	}
}
