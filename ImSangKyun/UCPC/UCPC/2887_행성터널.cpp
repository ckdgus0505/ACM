#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
	int idx, x, y, z;
	int retDistance(struct Node& node) {
		return std::min({ abs(x - node.x), abs(y - node.y), abs(z - node.z) });
	}
};

int n;
vector<Node> arr;
vector<vector<pair<int, int>>> adj;
vector<pair<int, pair<int, int>>> edges;

struct Disjointset {
	vector<int> parent, rank;
	Disjointset(int size) : parent(size), rank(size, 1) {
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}
	int find(int u) {
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	void merge(int a, int b) {
		int u = find(a), v = find(b);
		if (u == v)	return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int kruscal() {
	int ret = 0;
	//간선추가는 main에서 했으므로 생략
	std::sort(edges.begin(), edges.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) -> bool{
		if (a.second.second < b.second.second)	return true;
		else	return false;
	});
	
	Disjointset dis(n);
	for (int i = 0; i < edges.size(); ++i) {
		int u = dis.find(edges[i].first), v = dis.find(edges[i].second.first);
		int weight = edges[i].second.second;
		if (u != v) {
			dis.merge(u, v);
			ret += weight;
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr = vector<Node>(n);
	adj = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < n; ++i) {
		arr[i].idx = i;
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	}
		

	std::sort(arr.begin(), arr.end(), [](Node a, Node b) -> bool {
		if (a.x < b.x)	return true;
		else		return false;
	});
	for (int i = 1; i < n; ++i) 
		edges.push_back(make_pair(arr[i - 1].idx, make_pair(arr[i].idx, arr[i].retDistance(arr[i - 1]))));
	std::sort(arr.begin(), arr.end(), [](Node a, Node b) -> bool {
		if (a.y < b.y)	return true;
		else		return false;
	});
	for (int i = 1; i < n; ++i)
		edges.push_back(make_pair(arr[i - 1].idx, make_pair(arr[i].idx, arr[i].retDistance(arr[i - 1]))));
	std::sort(arr.begin(), arr.end(), [](Node a, Node b) -> bool {
		if (a.z < b.z)	return true;
		else		return false;
	});
	for (int i = 1; i < n; ++i)
		edges.push_back(make_pair(arr[i - 1].idx, make_pair(arr[i].idx, arr[i].retDistance(arr[i - 1]))));

	cout << kruscal() << '\n';

}