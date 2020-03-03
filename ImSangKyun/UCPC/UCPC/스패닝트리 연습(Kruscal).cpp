#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int size) : parent(size), rank(size, 1) {
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}
	int find(int u) {
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	void merge(int u, int v) {
		int u = find(u), v = find(v);
		if (u == v)	return;
		if (rank[u] > rank[v])	swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v])	++rank[v];
	}
};

const int MAX_V = 100;
int V;	//정점의 개수
vector<pair<int, int>> adj[MAX_V];

int kruscal(vector<pair<int, int>>& selected) {	//O(ElgE)
	int ret = 0;
	selected.clear();
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 0; u < V; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	std::sort(edges.begin(), edges.end());
	DisjointSet dis(V);
	for (int i = 0; i < edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (dis.find(u) == dis.find(v))	continue;
		dis.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

int main(void) {


}