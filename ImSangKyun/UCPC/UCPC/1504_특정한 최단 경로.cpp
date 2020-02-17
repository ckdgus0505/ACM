#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, E;
const int maxVal = 2100000000;
vector<vector<pair<int, int>>> arr;

vector<int> dijkstra(int src, int dst) {
	vector<int> dist(N + 1, maxVal);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();

		if (dist[node] < weight)	continue;
		for (int i = 0; i < arr[node].size(); ++i) {
			int next = arr[node][i].second;
			int nextW = arr[node][i].first + weight;
			if (dist[next] > nextW) {
				dist[next] = nextW;
				pq.push(make_pair(-nextW, next));
			}
		}
	}
	return dist;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;
	arr = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(c, b));
		arr[b].push_back(make_pair(c, a));
	}
	int m1, m2;
	cin >> m1 >> m2;
	vector<int> res = dijkstra(1, N);
	vector<int> a1, a2;
	a1 = dijkstra(m1, N);
	a2 = dijkstra(m2, N);
	int result = min(res[m1] + a1[m2] + a2[N], res[m2] + a2[m1] + a1[N]);
	if (result >= maxVal || result < 0)
		cout << -1 << '\n';
	else
		cout << result << '\n';
}