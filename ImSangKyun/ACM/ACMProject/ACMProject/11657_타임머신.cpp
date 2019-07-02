#include <iostream>
#include <vector>
using namespace std;

int N, M;
const int INF = 100000000;
vector<vector<pair<int, int>>> arr;

vector<int> bellmanFord(int src) {
	vector<int> upper(N+1, INF);
	bool updated;
	
	upper[src] = 0;
	for (int iter = 1; iter <= N; ++iter) {
		updated = false;
		for (int here = 1; here <= N; ++here) {
			for (int i = 0; i < arr[here].size(); ++i) {
				int there = arr[here][i].first;
				int cost = arr[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated)	break;
	}
	if (updated)	upper[0] = -1;
	return upper;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	arr = vector<vector<pair<int, int>>>(N+1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		bool duplicate = false;
		cin >> a >> b >> c;
		for (int j = 0; j < arr[a].size(); ++j) {
			if (arr[a][j].first == b) {
				duplicate = true;
				if (arr[a][j].second > c) {
					arr[a][j].second = c;
				}
			}
		}
		if (!duplicate) {
			arr[a].push_back(make_pair(b, c));
		}
	}
	vector<int> res = bellmanFord(1);
	if (res[0] == -1)	cout << -1 << '\n';
	else
		for (int i = 2; i <= N; ++i) {
			if (res[i] == INF)
				cout << -1 << '\n';
			else
				cout << res[i] << '\n';
		}
	
}