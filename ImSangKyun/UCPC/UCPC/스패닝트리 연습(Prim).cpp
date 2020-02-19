#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;	//������ ����
vector<pair<int, int>> adj[MAX_V];	//��������Ʈ

int prim(vector<pair<int, int>>& selected) {	//O(V^2 + E)
	selected.clear();
	vector<bool> added(V, false);	//�ش� ������ Ʈ���� ���ԵǾ��ִ°� ����
	vector<int> minWeight(V, INF), parent(V, -1);	//Ʈ���� ������ ���� �� �ش� ������ ��� �ּ� ������ ������ �����Ѵ�
	int ret = 0;	//��ü ����Ǿ��� ���� ����ġ ��
	minWeight[0] = parent[0] = 0;	//0������ ����
	for (int iter = 0; iter < V; ++iter) {
		int u = -1;
		for (int v = 0; v < V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))	//�ּڰ� ����
				u = v;
		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

int main(void) {

}