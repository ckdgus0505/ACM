#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u) {
		//if (parent[u] == u)	return u;
		//return parent[u] = find(parent[u]);	//경로압축(path compression) 최적화
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v)	return;
		//if (rank[u] > rank[v])	swap(u, v);
		parent[u] = v;
		//if (rank[u] == rank[v])	++rank[v];	//union-by-rank 최적화
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	struct DisjointSet dis(N + 1);
	for (int i = 0; i < M; ++i) {
		int comm, a, b;
		cin >> comm >> a >> b;
		if (comm == 0) {
			dis.merge(a, b);
		}
		if (comm == 1) {
			if (dis.find(a) == dis.find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}