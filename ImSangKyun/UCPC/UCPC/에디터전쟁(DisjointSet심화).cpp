#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Disjointset {
	vector<int> parent, rank, enemy, size;
	Disjointset(int n) : parent(n), rank(n, 1), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u) {
		return parent[u] = (parent[u] == u) ? u : find(parent[u]);
	}
	int merge(int u, int v) {
		if (u == -1 || v == -1)	return std::max(u, v);
		if (rank[u] > rank[v])	swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v])	++rank[v];
		return v;
	}
	bool dis(int u, int v) {
		u = find(u); v = find(v);
		if (u == v)	return false;
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if (enemy[u] == v)	return false;
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1)	enemy[b] = a;
		return true;
	}
};

int maxParty(const Disjointset& buf, int n) {
	int ret = 0;
	for (int node = 0; node < n; ++node) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			if (enemy > node)	continue;	//같은쌍을 두번 세지 않도록 하기 위함
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main(void) {
	//
}