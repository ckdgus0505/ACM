#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> arr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<pair<int, int>>(N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		arr[i] = make_pair(x, y);
	}


}