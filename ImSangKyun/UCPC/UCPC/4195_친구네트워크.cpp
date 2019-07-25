#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Disjointset {
	vector<string> parent;
	vector<int> rank, size;
	Disjointset(int n) : parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u) {
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v)	return;
		if (rank[u] > rank[v])	swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v])	++rank[v];
	}
	int retsize(int u) {
		u = find(u);
		return size[u];
	}
};

// String 다룰줄 몰라서 일단 보류

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int lo = 0; lo < T; ++lo) {
		//TestCase
		int F;
		cin >> F;	//100,000미만


	}
}