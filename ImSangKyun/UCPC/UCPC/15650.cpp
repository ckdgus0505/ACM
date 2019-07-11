#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void func(int num, int bePick) {
	if (bePick == 0) {
		for (auto& iter : arr) {
			cout << iter << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = num + 1; i <= N; ++i) {
		arr.push_back(i);
		func(i, bePick - 1);
		arr.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	func(0, M);

	return 0;
}