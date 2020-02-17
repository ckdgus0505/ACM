#include <iostream>
#include <vector>
using namespace std;

struct RangeSum {
	int n;
	vector<long long> range;
	RangeSum(const vector<int>& arr) {
		n = arr.size();
		range.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}

	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return range[node] = arr[left];
		int mid = (left + right) / 2;
		long long leftSum = init(arr, left, mid, node * 2);
		long long rightSum = init(arr, mid + 1, right, node * 2 + 1);
		return range[node] = leftSum + rightSum;
	}

	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if(right < nodeLeft || nodeRight < left)	return 0;
		if (left <= nodeLeft && nodeRight <= right)	return range[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}
	long long query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)	return range[node];
		if (nodeLeft == nodeRight)	return range[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return range[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}
	long long update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;

	cin >> n >> m >> k;
	vector<int> arr(n + 1);

	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	RangeSum RS(arr);

	int a, b, c;
	for (int i = 0; i < m + k; ++i) {
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			RS.update(b-1, c);
			break;
		case 2:
			cout << RS.query(b-1, c-1) << '\n';
			break;
		}
	}
}