#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 987654321
using namespace std;

int N, E; // ������ ���� N, ������ ���� E
int v1, v2; // ������ 1, 2
vector<vector<pair<int, int>>> adj; // ���� ����Ʈ

vector<int> dijkstra(int src);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> E;

	adj = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 0; i < E; i++)
	{
		int src, dst, weight;
		cin >> src >> dst >> weight;

		adj[src].push_back(make_pair(weight, dst));
		adj[dst].push_back(make_pair(weight, src));
	}
	cin >> v1 >> v2;


	
	vector<int> one_to;
	vector<int> v1_to;
	vector<int> v2_to;

	one_to = dijkstra(1);
	v1_to = dijkstra(v1);
	v2_to = dijkstra(v2);



	if (v1_to[v2] == MAX)
		cout << -1 << '\n';
	else
	{
		int A = one_to[v1] + v1_to[v2] + v2_to[N];
		int B = one_to[v2] + v2_to[v1] + v1_to[N];
		int C = one_to[v1] + 2 * v1_to[v2] + v1_to[N];
		int D = one_to[v2] + 2 * v2_to[v1] + v2_to[N];
		
		cout << min(min(A, B), min(C, D)) << '\n';
	}
	

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