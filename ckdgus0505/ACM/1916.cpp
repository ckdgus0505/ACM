#include <iostream>
#include<vector>
#include<queue>
#define MAX 987654321
using namespace std;
int N; // ���� ��
int M; // ���� ��
int from;
int to;
vector < vector<pair<int, int>>> adj; // ���� ����Ʈ , first �� ����ġ, second�� ���

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
	priority_queue<pair<int, int>> pq; // ����ġ�� ���� pq
	pq.push(make_pair(0, src)); // first�� ����ġ, second �� ���

	while (!pq.empty())
	{
		int cost = -pq.top().first; // pq�� ����ġ
		int node = pq.top().second; // pq�� ���
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