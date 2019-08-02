#include <iostream>
#include<vector>
#include<queue>
#define MAX 987654321
using namespace std;
int N; // 도시 수
int M; // 버스 수
int from;
int to;
vector < vector<pair<int, int>>> adj; // 인접 리스트 , first 는 가중치, second는 노드

vector<int> dijkstra(int src);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> M;

	adj = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; i++)
	{
		int src, dest, cost;
		cin >> src >> dest >> cost;

		adj[src].push_back(make_pair(cost, dest));
	}
	cin >> from >> to;
	vector<int> dist = dijkstra(from);

	cout << dist[to] << "\n";
}

vector<int> dijkstra(int src)
{
	vector<int> ret(N + 1, MAX);
	ret[src] = 0;
	priority_queue<pair<int, int>> pq; // 가중치를 넣을 pq
	pq.push(make_pair(0, src)); // first는 가중치, second 는 노드

	while (!pq.empty())
	{
		int cost = -pq.top().first; // pq의 가중치
		int node = pq.top().second; // pq의 경로
		pq.pop();

		if (ret[node] < cost) continue;
		for (int i = 0; i < adj[node].size(); i++)
		{
			int next = adj[node][i].second;
			int nextcost = cost + adj[node][i].first;
			if (ret[next] > nextcost) {
				ret[next] = nextcost;
				pq.push(make_pair(-nextcost, next));
			}
		}
	}
	return ret;
}