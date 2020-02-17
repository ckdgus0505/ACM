#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> cache;

int func(int val) {
	int& ret = cache[val];
	if (ret != -1)	return ret;
	if (!val)	return 1;
	ret = 0;
	for (int i = 1; i <= 3; ++i) {
		if(i <= val)
			ret += func(val - i);
	}
	return ret;
}

int main(void) {
	int T;
	cin >> T;
	for (int lo = 0; lo < T; ++lo) {
		//loop Start
		cin >> n;
		cache = vector<int>(n + 1, -1);
		cout << func(n) << '\n';
	}
}