#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> arr;

int func(int num, vector<int> flag) {
	vector<int> tmp = flag;
	int res = 0;
	for (int i = num+1; i < N; ++i) {
		if (flag[i])	continue;
		if (i + arr[i].first -1 >= N)	continue;
		for (int j = 0; j < arr[j].first; ++j)
			flag[i + j] = 1;
		res = max(res, func(i, flag));
		for (int j = 0; j < arr[j].first; ++j)
			flag[i + j] = 0;
	}
	return res + arr[num].second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<pair<int, int>>(N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		arr[i].first = x;	//time
		arr[i].second = y;	//payment
	}
	int res = 0;
	vector<int> flag(N, 0);
	for (int i = 0; i < N; ++i) {
		if (i + arr[i].first -1 >= N)	continue;
		for (int j = 0; j < arr[j].first; ++j) 
			flag[i + j] = 1;
		res = max(res, func(i, flag));
		for (int j = 0; j < arr[j].first; ++j)
			flag[i + j] = 1;
	}
	cout << res << '\n';

	return 0;
}