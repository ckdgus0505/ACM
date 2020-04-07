#include <cstdio>
#include <queue>
using namespace std;

int map[1000][1000];
bool visited[1000][1000][2]; // 마지막 2는 벽 뚫은 여부
int d_x[4] = {0, 0, 1,-1};
int d_y[4] = {1,-1, 0, 0};
int N; int M;

void Input();
int BFS();
int main(void) {

	Input();
	int ans = BFS();
	printf("%d\n", ans);
}

void Input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

int BFS() {
	queue<pair<pair<int, int>, pair<int, int>>> Q; // 첫 pair은 r,c 둘째 pair은 count, 벽
	Q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	visited[0][0][0] = true;

	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second.first;
		int wallcnt = Q.front().second.second;
		Q.pop();

		if (x == N - 1 && y == M - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int new_x = x + d_x[i];
			int new_y = y + d_y[i];

			if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < M) {
				if (map[new_x][new_y] == 1 && wallcnt == 0) {
					visited[new_x][new_y][wallcnt + 1] = true;
					Q.push(make_pair(make_pair(new_x, new_y), make_pair(cnt + 1, wallcnt + 1)));
				}
				else if (map[new_x][new_y] == 0 && visited[new_x][new_y][wallcnt] == false) {
					visited[new_x][new_y][wallcnt] = true;
					Q.push(make_pair(make_pair(new_x, new_y), make_pair(cnt + 1, wallcnt)));
				}
			}
		}
	}
	return -1;
}