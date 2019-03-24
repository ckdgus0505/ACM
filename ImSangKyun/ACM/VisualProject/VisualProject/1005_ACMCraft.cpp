/*
	1. 자료구조 : Graph
	2. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;
vector<int> time;

int func(int find, int depth, int node) {
	

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, K, W;

	cin >> T;
	for (int lo = 0; lo < T; ++lo) {
		cin >> N >> K;
		arr = vector<vector<int>>(N + 1);
		time = vector<int>(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> time[i];
		for (int i = 1; i <= K; ++i) {
			int x, y;
			cin >> x >> y;
			arr[y].push_back(x);
		}
		cin >> W;

	}

}