#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N, M, K;
vector<long long> arr;

long long sum(long long a, long long b) { return a + b; }

struct RMQ {
	int n;
	vector<long long> rangeSum;
	RMQ(const vector<long long>& array) {
		n = array.size();
		rangeSum.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	long long init(const vector<long long>& array, int left, int right, int node) {
		if (left == right)
			return rangeSum[node] = array[left];
		int mid = (left + right) / 2;
		long long leftSum = init(array, left, mid, node * 2);
		long long rightSum = init(array, mid + 1, right, node * 2 + 1);
		return rangeSum[node] = sum(leftSum, rightSum);
	}

	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return 0 ;
		if (left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return sum(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	long long query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	long long update(int index, long long newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index) return rangeSum[node];
		if (nodeLeft == nodeRight) return rangeSum[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = sum(
			update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	long long update(int index, long long newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	arr.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	RMQ sums(arr);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			sums.update(b-1, c);
		}
		else if (a == 2) {
			cout << sums.query(b-1, c-1) << '\n';
		}
	}
	return 0;
}