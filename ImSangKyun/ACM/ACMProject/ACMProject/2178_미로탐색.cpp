#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> arr;
vector<vector<bool>> discovered;
int N, M;
const int directX[4] = {0, 1, 0, -1};	//상, 우, 하, 좌
const int directY[4] = {-1, 0, 1, 0};


void bfs() {	//0, 0에서 부터 출발
	queue<pair<pair<char, char>, int>> q;
	q.push(make_pair(make_pair('0', '0'), 1));	//(Y, X), depth

	while (!q.empty()) {
		char hereX = q.front().first.second;
		char hereY = q.front().first.first;
		int depth = q.front().second;
		q.pop();

		++depth;
		for (int k = 0; k < 4; ++k) {
			int thereX = hereX - '0' + directX[k];
			int thereY = hereY - '0' + directY[k];
			if (thereX < 0 || thereX >= M || thereY < 0 || thereY >= N)
				continue;
			if (thereX == M - 1 && thereY == N - 1) {
				cout << depth << '\n';
				return;
			}
			if (arr[thereY][thereX] == '1' && !discovered[thereY][thereX]) {
				q.push(make_pair(make_pair(thereY + '0', thereX + '0'), depth));
				discovered[thereY][thereX] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	arr = vector<vector<char>>(N, vector<char>(M));
	discovered = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}
	bfs();
}