//Kruscal
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max();
int V, E;
vector<vector<pair<int, int>>> adj;

class DisjointSet {
	vector<int> parent, rank;
public:
	DisjointSet(int size) : parent(size), rank(size, 1) {
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}
	int find(int u) {
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	bool merge(int a, int b) {
		int u = find(a), v = find(b);
		if (u == v)	return false;
		if (rank[u] < rank[v])	std::swap(u, v);
		parent[v] = u;
		if (rank[u] == rank[v])	rank[u]++;
		return true;
	}
};

int kruscal(vector<pair<int, int>>& selected) {
	selected.clear();
	int ret = 0;	//스패닝트리의 최소 가중치 크기
	vector<pair<int, pair<int, int>>> arr;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < adj[i].size(); ++j)
			arr.push_back(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));
	std::sort(arr.begin(), arr.end());
	DisjointSet dis(V);
	for (int i = 0; i < arr.size(); ++i) {
		int u = arr[i].second.first, v = arr[i].second.second;
		int weight = arr[i].first;
		if (dis.merge(u, v)) {
			ret += weight;
			selected.push_back(make_pair(u, v));
		}
		else
			continue;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	adj = vector<vector<pair<int, int>>>(V);
	for (int i = 0; i < E; ++i) {
		int u, v, weight;
		cin >> u >> v >> weight;
		u -= 1;
		v -= 1;
		adj[u].push_back(make_pair(v, weight));
		adj[v].push_back(make_pair(u, weight));
	}
	vector<pair<int, int>> selected(V);
	int res = kruscal(selected);
	cout << res << '\n';
}