#include <iostream>
#include <vector>
using namespace std;

int N, M;

struct Disjointset {
	vector<int> parent, rank;
	Disjointset(int n) : parent(n), rank(n, 1) {
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
		if (rank[u] == rank[v])	++rank[v];
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	
	struct Disjointset dis(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				dis.merge(i, j);
			}
		}
	}

	int root, tmp;
	bool flag = true;
	cin >> tmp;
	root = dis.find(tmp - 1);
	for (int i = 0; i < M-1; ++i) {
		cin >> tmp;
		if (!(root == dis.find(tmp - 1))) {
			flag = false;
		}
	}
	if (!flag)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';
}