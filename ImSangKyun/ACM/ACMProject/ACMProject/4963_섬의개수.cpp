#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> discovered;
const int directX[8] = { -1, 0, 1, 1, 1, 0, -1, -1};//аб╩С, ╩С, ©Л╩С, ©Л, ©Лго, го, абго, аб
const int directY[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
int w, h;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	discovered[y][x] = true;
	//int looptime = 0;

	while (!q.empty()) {
		pair<int, int> direct = q.front();
		q.pop();
		//cout << "loop : " << ++looptime << '\n';
		for (int k = 0; k < 8; ++k) {
			int X = direct.second + directX[k];
			int Y = direct.first + directY[k];
			if (X < 0 || X >= w || Y < 0 || Y >= h)
				continue;
			if (!discovered[Y][X] && adj[Y][X]) {
				q.push(make_pair(Y, X));
				discovered[Y][X] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> w >> h;
		if (!w && !h)	break;

		adj = vector<vector<int>>(h, vector<int>(w, -1));
		discovered = vector<vector<bool>>(h, vector<bool>(w, false));
		int cnt = 0;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> adj[i][j];
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (adj[i][j] && !discovered[i][j]) {
					bfs(j, i);
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
	}

}