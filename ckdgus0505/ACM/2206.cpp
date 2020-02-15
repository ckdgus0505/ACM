#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int N, M;
int Min = 987654321;
vector<vector<int>> maps;
int new_x[4] = {1,0,-1,0};
int new_y[4] = {0,1,0,-1};
int visited[1000][1000];
void dfs(int y, int x, int cnt);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	maps.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &maps[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 1) {
				maps[i][j] = 0;
				memset(visited, 0, sizeof(visited));
				dfs(0, 0, 0);
				maps[i][j] = 1;
			}
		}
	}
	if (Min != 987654321)
		cout << Min + 1 << '\n';
	else cout << -1 << '\n';
}

void dfs(int y, int x, int cnt) {
	if (y == N-1 && x == M-1) {
		Min = min(Min, cnt);
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if ((y + new_y[i] >= 0 && y + new_y[i] < N) && (x + new_x[i] >= 0 && x + new_x[i] < M)) {
			if (maps[y + new_y[i]] [x + new_x[i]] == 0 && visited[y + new_y[i]][x+new_x[i]] == 0)
			{
				visited[y][x] = 1;
				dfs(y+new_y[i],x+new_x[i],cnt+1);
				visited[y][x] = 0;
			}
		}
	}
}