#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> cache;

int lis(int select) {
	int& ret = cache[select];
	if (ret != -1)	return ret;
	
	ret = 1;
	for (int i = select+1; i < arr.size(); ++i) {
		if (arr[i] > arr[select])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, maxLen=0;
	cin >> N;
	arr = vector<int>(N);
	cache = vector<int>(N, -1);

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < N; ++i) {
		maxLen = std::max(maxLen, lis(i));
	}

	cout << N - maxLen << '\n';
}