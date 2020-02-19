#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
const int MAXVAL = 100000000;	// 가중치 X 간선의 개수보다 클 것
vector<vector<pair<int, int>>> arr;

vector<int> dijkstra(int src) {
	vector<int> dist(V + 1, MAXVAL);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;	//가중치
		int here = pq.top().second;	//정점
		pq.pop();

		if (dist[here] < cost)	continue;
		for (int i = 0; i < arr[here].size(); ++i) {
			int there = arr[here][i].first;	//정점
			int nextDist = cost + arr[here][i].second;	//가중치
			if (dist[there] > nextDist) {	
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> K;

	arr = vector<vector<pair<int, int>>>(V + 1);

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back(make_pair(v, w));
	}
	vector<int> dist = dijkstra(K);
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == MAXVAL)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}