#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> arr, tmp;
bool cache[8][8];

int directX[] = { -1, 1, 0, 0 };	//left, right, up, down
int directY[] = { 0, 0, -1, 1 };

queue<pair<int, int>> space, virus;	//x, y
vector<pair<int, int>> walls;	//벽을 세운 위치 좌표

void copyArray(const vector<vector<int>>& arr, vector<vector<int>>& dst);	//array 깊은복사
int spreadVirus(vector<vector<int>>& tmp) {
	queue<pair<int, int>> q = virus;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;	q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int nx = x + directX[i], ny = y + directY[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && tmp[ny][nx] == 0) {
				tmp[ny][nx] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tmp[i][j] == 0) {
				++res;
			}
		}
	}
	

	return res;
}

int createWall(int x, int y, int cnt) {
	int res = 0;
	if (cnt == 3) {
		copyArray(arr, tmp);
		res = max(res, spreadVirus(tmp));
		return res;
	}
	for (int i = 0; i < n; ++i) {
		if (i < y)	continue;
		for (int j = 0; j < m; ++j) {
			if (i == y && j < x)	continue;
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				res = std::max(res, createWall(j, i, cnt + 1));
				arr[i][j] = 0;
			}
		}
	}
	return res;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	arr = vector<vector<int>>(n, vector<int>(m, 0));
	walls = vector<pair<int, int>>(3);
	vector<vector<int>> tmp;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) 
				space.push(make_pair(j, i));
			else if (arr[i][j] == 2) {
				virus.push(make_pair(j, i));
				cache[i][j] = true;
			}
				
		}
	}
	
	int res = createWall(0, 0, 0);
	cout << res << '\n';

}

void copyArray(const vector<vector<int>>& arr, vector<vector<int>>& dst) {
	dst = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			dst[i][j] = arr[i][j];
}