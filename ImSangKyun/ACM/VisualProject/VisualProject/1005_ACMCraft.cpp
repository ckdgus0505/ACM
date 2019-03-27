#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, W;
vector<vector<int>> arr;	//노드 순서로, x->y 일때 arr[y].push_back(x) 로 역순저장
vector<int> time;	//각 건물을 짓는데 필요한 시간
vector<int> cache;	//메모이제이션

int func(int node) {
	int& ret = cache[node];
	if (ret != -1)	return ret;	
	if (arr[node].empty())	return time[node];	//시작지점이 반드시 1이 아니므로 시작으로 간주될 법한 노드는 바로 리턴
	for (auto iter : arr[node]) {
		ret = max(ret, func(iter) + time[node]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int lo = 0; lo < T; ++lo) {
		cin >> N >> K;
		arr = vector<vector<int>>(N+1);
		time = vector<int>(N + 1, 0);
		cache = vector<int>(N + 1, -1);
		for (int i = 1; i <= N; ++i) 
			cin >> time[i];
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			arr[y].push_back(x);
		}
		cin >> W;

		cout << func(W) << '\n';
	}

}