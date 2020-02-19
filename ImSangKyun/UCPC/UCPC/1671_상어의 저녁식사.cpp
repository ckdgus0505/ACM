#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int  MAX_SIZE = 1000;
int B[MAX_SIZE];
bool visit[MAX_SIZE];
vector<int> edge[MAX_SIZE];

int sharkSize[MAX_SIZE];
int sharkIntel[MAX_SIZE];
int sharkSpeed[MAX_SIZE];

int n;
int eat(int a, int b) {
	int ret = 0;
	if (sharkSize[a] < sharkSize[b]) return 0;
	else if (sharkSize[a] == sharkSize[b]) ret++;
	if (sharkIntel[a] < sharkIntel[b]) return 0;
	else if (sharkIntel[a] == sharkIntel[b]) ret++;
	if (sharkSpeed[a] < sharkSpeed[b]) return 0;
	else if (sharkSpeed[a] == sharkSpeed[b]) ret++;

	if (ret == 3) return 2;
	return 1;
}

bool f(int from) {	//dfs
	visit[from] = true;
	for (int i = 0; i < edge[from].size(); i++) {
		int to = edge[from][i];
		if (B[to] == -1 || !visit[B[to]] && f(B[to])) {
			B[to] = from;
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sharkSize[i] >> sharkIntel[i] >> sharkSpeed[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int eatFlag = eat(i, j);

			if (eatFlag == 1) edge[i].push_back(j); //먹을 수 있는경우
			else if (eatFlag == 2 && i < j) edge[i].push_back(j); // 능력치가 같은 경우
		}
	}
	memset(B, -1, sizeof(B));
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		f(i);
		memset(visit, 0, sizeof(visit));
		f(i);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) if (B[i] == -1) ret++;
	printf("%d", ret);

	return 0;
}
