#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int N;
const int INF = numeric_limits<int>::min();
vector<int> arr;
vector<vector<int>> cache;

int func(int cnt, int idx) {
	int& ret = cache[cnt][idx];
	if (ret != INF)	return ret;
	if (cnt == 3)
		return arr[idx];
	for (int i = idx + 1; i < N; ++i) {
		int tmp = func(cnt + 1, i);
		if (tmp != INF)
			ret = std::max(ret, tmp * arr[idx]);
	}
	if (cnt == 2)
		ret = max(ret, arr[idx]);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<int>(N);
	cache = vector<vector<int>>(4, vector<int>(N, INF));
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int ret = INF;
	for (int i = 0; i < N - 1; ++i)
		ret = max(ret, func(1, i));
	cout << ret << '\n';
}