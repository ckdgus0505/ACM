#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int V;
int capacity[402][402], flow[402][402];

int networkFlow(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int totalflow = 0;
	while (true) {
		vector<int> parent(402, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front(); q.pop();
			for (int there = 0; there < 402; ++there)// v는 아마 N+M+2;
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		if (parent[sink] == -1) break;
		int amount = 987654321;
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalflow += amount;
	}
	return totalflow;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) // i 는 소의 번호
	{
		int l;
		cin >> l;
		 capacity[0][i] = 1; // 스타트에서부터 소까지
		for (int j = 0; j < l; j++)
		{
			int a;
			cin >> a;
			capacity[i][a + 200] = 1; // 소에서 축사까지
		}
	}
	for (int i = 1; i <= N; i++)
		capacity[200 + i][401] = 1; // 축사에서 끝까지

	/* 경로 완성!*/

	cout << networkFlow(0, 401) << '\n';

	return 0;
}