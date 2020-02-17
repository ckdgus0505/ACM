#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int N;
vector<int> arr;
vector<vector<int>> cache;

int func(int idx, int cnt) {
	int& ret = cache[idx][cnt];
	if (ret)	return ret;
	if (idx == 0)	--cnt;
	if (idx == N)	return arr[idx];
	if (idx == N - 1 && cnt == 1)	return numeric_limits<int>::min();
	if (cnt < 1)
		ret = std::max(ret, func(idx + 1, cnt + 1) + arr[idx]);
	if(idx < N-1)
		ret = std::max(ret, func(idx + 2, 0) + arr[idx]);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	arr = vector<int>(N+1, 0);
	cache = vector<vector<int>>(N+1, vector<int>(2, 0));
	for (int i = 1; i <= N; ++i) 
		cin >> arr[i];
	cout << func(0, 0) << '\n';
}