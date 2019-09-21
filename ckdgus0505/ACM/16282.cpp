#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long  n;
	cin >> n;
	long long i = 0;
	long long max;
	do {
		max = i + (i + 1) * (pow(2, i + 1) - 1);
		i++;
	} while (n > max);
	cout << i-1 << endl;
	return 0;
}