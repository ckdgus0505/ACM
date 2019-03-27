#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> arr;
vector<int> time;
vector<int> cache;

int func(int node) {
	int& ret = cache[node];
	if (ret != -1)	return ret;
	if (node == 1)	return time[node];
	ret = -1;
	for (auto iter : arr[node]) {
		ret = max(ret, func(iter) + time[node]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, W;
	cin >> T;

	for (int lo = 0; lo < T; ++lo) {
		cin >> N >> K;
		arr = vector<vector<int>>(N+1);
		time = vector<int>(N + 1);
		cache = vector<int>(N + 1, -1);
		for (int i = 1; i <= N; ++i) 
			cin >> time[i];
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			arr[y].push_back(x);
		}
		cin >> W;

		cout << "result : " << func(W) << '\n';
	}

}