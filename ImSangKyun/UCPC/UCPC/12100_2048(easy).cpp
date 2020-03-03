#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> arr;
enum Direction { left, up, right, down };

int maxValue(vector<vector<int>>& graph) {
	int res = -1;
	for (auto& iter : graph)
		for (auto& it : iter)
			res = std::max(res, it);

	return res;
}

vector<vector<int>> copy_vector(vector<vector<int>>& src) {
	vector<vector<int>> dst(n, vector<int>(n));
	for (int i = 0; i < n; ++i)		//Deep Copy
		for (int j = 0; j < n; ++j)
			dst[i][j] = src[i][j];
	return dst;
}

int func(vector<vector<int>> graph, Direction d, int cnt) {
	if (cnt > 5)
		return maxValue(graph);
	queue<int> q;
	vector<vector<int>> tmp(n, vector<int>(n));
	int res = -1;

	for (int i = 0; i < n; ++i)		//Deep Copy
		for (int j = 0; j < n; ++j)
			tmp[i][j] = graph[i][j];

	switch (d) {
	case Direction::left:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tmp[i][j])
					q.push(tmp[i][j]);
				tmp[i][j] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int data = q.front();	q.pop();

				if (tmp[i][idx] == 0)
					tmp[i][idx] = data;
				else if (tmp[i][idx] == data) {
					tmp[i][idx] *= 2;
					++idx;
				}
				else {
					++idx;
					tmp[i][idx] = data;
				}
			}
		}
		break;
	case Direction::up:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tmp[j][i])
					q.push(tmp[j][i]);
				tmp[j][i] = 0;
			}

			int idx = 0;
			while (!q.empty()) {
				int data = q.front();	q.pop();

				if (tmp[idx][i] == 0)
					tmp[idx][i] = data;
				else if (tmp[idx][i] == data) {
					tmp[idx][i] *= 2;
					++idx;
				}
				else {
					++idx;
					tmp[idx][i] = data;
				}
			}
		}
		break;
	case Direction::right:
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				if (tmp[i][j])
					q.push(tmp[i][j]);
				tmp[i][j] = 0;
			}

			int idx = n - 1;
			while (!q.empty()) {
				int data = q.front();	q.pop();

				if (tmp[i][idx] == 0)
					tmp[i][idx] = data;
				else if (tmp[i][idx] == data) {
					tmp[i][idx] *= 2;
					--idx;
				}
				else {
					--idx;
					tmp[i][idx] = data;
				}
			}
		}
		break;
	case Direction::down:
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				if (tmp[j][i])
					q.push(tmp[j][i]);
				tmp[j][i] = 0;
			}

			int idx = n - 1;
			while (!q.empty()) {
				int data = q.front();	q.pop();

				if (tmp[idx][i] == 0)
					tmp[idx][i] = data;
				else if (tmp[idx][i] == data) {
					tmp[idx][i] *= 2;
					--idx;
				}
				else {
					--idx;
					tmp[idx][i] = data;
				}
			}
		}
		break;
	}
	res = std::max(res, func(copy_vector(tmp), Direction::left, cnt + 1));
	res = std::max(res, func(copy_vector(tmp), Direction::up, cnt + 1));
	res = std::max(res, func(copy_vector(tmp), Direction::right, cnt + 1));
	res = std::max(res, func(copy_vector(tmp), Direction::down, cnt + 1));
	return res;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	int res = -1;
	res = std::max(res, func(arr, Direction::left, 1));
	res = std::max(res, func(arr, Direction::up, 1));
	res = std::max(res, func(arr, Direction::right, 1));
	res = std::max(res, func(arr, Direction::down, 1));
	cout << res << '\n';
}