#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
vector<int> arr;
vector<int> cache;	//idx, cnt
vector<bool> visit;

int func(int idx, int des) {
	int& ret = cache[idx];
	if (ret != -1 && ret != 99999999)	return ret;
	if (idx == des)
		return 0;

	int tmp = 99999999;
	visit.at(idx) = true;
	if (idx > 0 && !visit.at(idx - 1)) {
		tmp = std::min(tmp, func(idx - 1, des) + 1);
	}
	if (arr[idx] && !visit.at(arr[idx])) {
		tmp = std::min(tmp, func(arr[idx], des) + 2);
	}
	if (idx < N - 1 && !visit.at(idx + 1)) {
		tmp = std::min(tmp, func(idx + 1, des) + 1);
	}
	visit.at(idx) = false;
	return ret = tmp;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	arr = vector<int>(N, 0);
	cache = vector<int>(N, -1);
	visit = vector<bool>(N, false);

	vector<int> st;
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;
		if (c == '.')	continue;
		if (c == '(') {
			st.push_back(i);
		}
		if (c == ')') {
			int idx = st.back();	st.pop_back();
			arr[i] = idx;
			arr[idx] = i;
		}
	}
	
	for (int i = 0; i < Q; ++i) {
		cache = vector<int>(N, -1);
		visit = vector<bool>(N, false);

		int start, end;
		cin >> start >> end;
		cout << func(start-1, end-1) << '\n';
	}
}