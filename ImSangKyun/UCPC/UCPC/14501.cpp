#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> valid;	//available

int func(int day) {
	bool next = false;
	int val = 0;

	if (day > N) {
		return 0;
	}
	if (day + arr[day].first - 1 > N)
		return 0;
	
	for (int i = 0; i < arr[day].first && day+i<=N; ++i)
		valid[day + i] = 1;

	for (int i = day+1; i <= N; ++i) {
		if (!valid[i] && i + arr[i].first - 1 <= N) {
			val = std::max(val, func(i)+arr[day].second);
			next = true;
		}
	}

	for (int i = 0; i < arr[day].first && day + i <= N; ++i)
		valid[day + i] = 0;

	if (!next)
		return arr[day].second;
	return val;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<pair<int, int>>(N+1);
	valid = vector<int>(N+1, 0);
	for (int i = 1; i <= N; ++i) {
		int x, y;
		cin >> x >> y;
		arr[i].first = x;
		arr[i].second = y;
	}

	int val = 0;
	for (int i = 1; i <= N; ++i) {
		val = std::max(val, func(i));
	}
	cout << val << '\n';

	return 0;
}