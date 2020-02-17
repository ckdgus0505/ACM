#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int i;
	long long N, res = 7;
	cin >> N;
	if (N <= res) {
		cout << 1 << '\n';
		return 0;
	}
	for (i = 2; N > res; ++i) 
		res = i * pow(2, i + 1) + pow(2, i + 1) - 1;
	cout << i-1 << '\n';
	return 0;
}