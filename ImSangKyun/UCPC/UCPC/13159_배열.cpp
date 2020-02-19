#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int N, Q;
struct RMQ {	//Range Minimum Query
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = arr[left];
		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node * 2);
		int rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		arr[i] = i;
	struct RMQ rmq(arr);
	



	for (int lo = 0; lo < Q; ++lo) {
		int com, num1, num2, x;
		cin >> com;
		switch (com) {
		case 1:
			cin >> num1 >> num2;
			break;
		case 2:
			cin >> num1 >> num2 >> x;
			break;
		case 3:
			cin >> num1;
			break;
		case 4:
			cin >> num1;
			break;
		default :
			cout << "INPUT ERROR" << '\n';
			break;
		}
	}

}