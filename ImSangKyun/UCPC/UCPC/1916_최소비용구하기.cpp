#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

int N, M;
const long MaxVal = numeric_limits<long>::max();
vector<vector<pair<int, int>>> arr;	//가중치, 정점

long dijkstra(int src, int dst) {
	priority_queue<pair<long, int>> pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int node = pq.top().second;
		long weight = -pq.top().first;
		pq.pop();

		if (node == dst)
			return weight;

		for (int i = 0; i < arr[node].size(); ++i) {
			int next = arr[node][i].second;
			int nextW = arr[node][i].first;
			pq.push(make_pair(-(nextW + weight), next));
		}
	}
	return MaxVal;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	arr = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back(make_pair(w, v));
	}
	int src, dst;
	cin >> src >> dst;

	long res = dijkstra(src, dst);
	if (res != MaxVal)
		cout << res << '\n';
	else
		cout << "error" << '\n';
}