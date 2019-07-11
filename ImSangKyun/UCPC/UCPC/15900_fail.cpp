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

	discovered = vector<bool>(N + 1, false);
	while (!q.empty()) {
		int n = q.front().first;
		int h = q.front().second;
		q.pop();
		
		for (int i : leaf) {
			if (n == i) 
				res += h;
		}

		discovered.at(n) = true;
		for (int i = 0; i < arr[n].size(); ++i) {
			if(discovered.at(arr[n][i]) != true)
				q.push(make_pair(arr[n][i], h + 1));
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<vector<int>>(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int res = 0;
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i].size() == 1) {
			leaf.push_back(i);
		}
	}
	height(res);

	while (res > 1)
		res %= 2;

	if (res == 1)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
	
}