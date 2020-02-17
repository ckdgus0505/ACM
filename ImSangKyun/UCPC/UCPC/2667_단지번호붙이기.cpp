#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<bool>> discovered;
vector<int> res;
queue<pair<int, int>> q;

const int directX[4] = { 0, 1, 0, -1 };
const int directY[4] = { -1, 0, 1, 0 };

int bfs(int y, int x) {
	q.push(make_pair(y, x));
	discovered.at(y).at(x) = true;
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		++cnt;
		
		for (int i = 0; i < 4; ++i) {
			int dx = x + directX[i];
			int dy = y + directY[i];
			if (dx >= 0 && dx < N && dy >= 0 && dy < N && arr[dy][dx]) {
				q.push(make_pair(dy, dx));
				discovered.at(dy).at(dx) = true;
			}
			else 
				continue;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N, 0));
	discovered = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] && !discovered.at(i).at(j)) {
				res.push_back(bfs(i, j));
			}
		}
	}
	std::sort(res.begin(), res.end());
	for (auto& iter : res) {
		cout << iter << '\n';
	}
}