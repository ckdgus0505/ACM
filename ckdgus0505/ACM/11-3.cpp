#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int answer;
vector<int> arr;
vector<int> sub;

void init();
int solution();


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	answer = solution();
	cout << answer << endl;
	return 0;
}

void init() {
	cin >> N;
	cin >> K;
	arr.assign(N, 0);
	sub.assign(N - 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i > 0) {
			sub[i - 1] = arr[i] - arr[i - 1];
		}
	}
}

int solution() {
	int ret = arr[N - 1] - arr[0];

	sort(sub.begin(), sub.end(), greater<int>());

	for (int i = 0; i < K-1; i++) {
		ret -= sub[i];
	}

	return ret;
}