#include <iostream>
#include <vector>
using namespace std;

struct NativeDisjointSet {
	vector<int> parent;
	NativeDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u) const {
		if (u == parent[u])	return u;
		return find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v)	return;
		parent[u] = v;
	}
};

int main(void) {
	int N;
	cin >> N;

	NativeDisjointSet dis(N);	//기본모델
	//1717_집합의 표현 문제에서 최적화 한 부분 보기

}