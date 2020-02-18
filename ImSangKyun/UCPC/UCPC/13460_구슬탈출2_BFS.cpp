#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int Rx, Ry, Bx, By, Ox, Oy;
vector<vector<int>> arr;
bool visit[10][10][10][10];
int directX[] = { -1, 0, 1, 0 };
int directY[] = { 0, -1, 0, 1 };


struct ball {
	int depth;
	int rx, ry, bx, by;
};


void move(int& x, int& y, int d) {
	while (1) {
		x += directX[d]; 
		y += directY[d];
		if (x < 0 || x >= m || y < 0 || y >= n || arr[y][x] == '#') {
			x -= directX[d]; y -= directY[d];
			break;
		}
		else if (arr[y][x] == 'O')
			break;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int res = -1;

	cin >> n >> m;
	arr = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;
			if (ch == 'R') {
				Rx = j;
				Ry = i;
			}
			else if (ch == 'B') {
				Bx = j;
				By = i;
			}
			else if (ch == 'O') {
				Ox = j;
				Oy = i;
				arr[i][j] = static_cast<int>(ch);
			}
			else
				arr[i][j] = static_cast<int>(ch);

		}
	}

	queue<ball> q;
	q.push({ 0, Rx, Ry, Bx, By });
	visit[Rx][Ry][Bx][By] = true;
	
	while (!q.empty()) {
		ball cur = q.front();	q.pop();

		if (cur.depth > 10)
			break;
		if (cur.rx == Ox && cur.ry == Oy) {
			res = cur.depth;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int rx = cur.rx, ry = cur.ry;
			int bx = cur.bx, by = cur.by;
			move(rx, ry, i);
			move(bx, by, i);

			if (bx == Ox && by == Oy)
				continue;

			if (rx == bx && ry == by) {
				switch (i) {
				case 0:	//left
					cur.rx < cur.bx ? bx++ : rx++; break;
				case 1:	//up
					cur.ry < cur.by ? by++ : ry++; break;
				case 2:	//right
					cur.rx < cur.bx ? rx-- : bx--; break;
				case 3:	//down
					cur.ry < cur.by ? ry-- : by--; break;
				}
			}

			if (!visit[rx][ry][bx][by]) {
				ball n = { cur.depth + 1, rx, ry, bx, by };
				q.push(n);
				visit[rx][ry][bx][by] = true;
			}
		}
	}

	cout << res << '\n';
}