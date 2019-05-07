#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
	cout << node << " ";
	visited[node] = true;
	for (int i = 0; i < adj[node].size(); ++i) {
		int next = adj[node][i];
		if (!visited[next]) 
			dfs(next);
	}
}

void bfs(int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << here << " ";
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N+1);
	visited = vector<bool>(N+1, false);

	for (int i = 0; i < M; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	for (int i = 1; i < adj.size(); ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);	cout << '\n';
	bfs(V); cout << '\n';
}