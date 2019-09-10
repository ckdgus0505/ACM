#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<double> cache;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cache.assign(1000001, 0.0);
	cache[0] = 0.0;
	cache[1] = 1.0;

	for (int i = 2; i <= 1000000; i++) {

		if (i <= 0) return 0.0;
		if (i == 1) return 1.0;
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				cache[i] += ((1.0 / 6.0) * (cache[i - j] + 1));
			}
			else cache[i] += (1.0 / 6.0);
		}
	}
	int a;
	cin >> a;
	printf("%.16f\n", cache[a]);
}