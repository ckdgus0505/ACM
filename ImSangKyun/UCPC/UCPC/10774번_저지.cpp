#include <iostream>
#include <vector>
using namespace std;

int J, A;
vector<int> arr;
vector<pair<char, int>> player;

struct Disjointset {
	vector<int> parent;
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> J >> A;
	arr = vector<int>(J);
	player = vector<pair<char, int>>(A);

	for (int i = 0; i < J; ++i) {
		char ch;
		cin >> ch;
		switch (ch) {
		case 'S':
			arr[i] = 1;
			break;
		case 'M':
			arr[i] = 2;
			break;
		case 'L':
			arr[i] = 3;
			break;
		}
	}
	
	for (int i = 0; i < A; ++i) {
		char ch; int num;
		cin >> ch >> num;
		player[i] = make_pair(ch, num);
	}

}