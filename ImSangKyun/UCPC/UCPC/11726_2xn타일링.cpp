#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> cache;

int func(int num) {
	int& ret = cache[num];
	if (ret)	return ret;
	if (num == 1 || num == 0)
		return 1;
	ret = (func(num - 1) + func(num - 2)) % 10007;
	return ret;
}

int main(void) {
	cin >> N;
	cache = vector<int>(N+1, 0);

	cout << func(N);

	return 0;
}