#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;	//정점의 개수
vector<pair<int, int>> adj[MAX_V];	//인접리스트

int prim(vector<pair<int, int>>& selected) {	//O(V^2 + E)
	selected.clear();
	vector<bool> added(V, false);	//해당 정점이 트리에 포함되어있는가 여부
	vector<int> minWeight(V, INF), parent(V, -1);	//트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다
	int ret = 0;	//전체 연결되었을 때의 가중치 값
	minWeight[0] = parent[0] = 0;	//0번부터 시작
	for (int iter = 0; iter < V; ++iter) {
		int u = -1;
		for (int v = 0; v < V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))	//최솟값 추출
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