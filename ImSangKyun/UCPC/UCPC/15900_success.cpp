#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<vector<int>> arr;
queue<pair<int, int>> q;
vector<bool> discovered;
vector<int> leaf;

void height(int& res) {
	q.push(make_pair(1, 0));
	discovered.at(1) = true;

	while (!q.empty()) {
		int n = q.front().first;
		int h = q.front().second;
		q.pop();

		if (arr[n].size() == 1) 
			res += h;

		for (int i = 0; i < arr[n].size(); ++i) {
			if (discovered.at(arr[n][i]) != true) {
				q.push(make_pair(arr[n][i], h + 1));
				discovered.at(arr[n][i]) = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<vector<int>>(N + 1);
	discovered = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int res = 0;
	height(res);

	while (res > 1)
		res %= 2;

	if (res == 1)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';

}