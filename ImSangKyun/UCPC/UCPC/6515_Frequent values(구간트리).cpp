#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct RangeFreq {
	int size;
	int mostFrequent;
	int leftNumber, leftFreq;
	int rightNumber, rightFreq;
	RangeFreq(){}
	RangeFreq(int size, int mostFrequent, int leftNumber, int leftFreq, int rightNumber, int rightFreq) : size(size), mostFrequent(mostFrequent),
		leftNumber(leftNumber), leftFreq(leftFreq), rightNumber(rightNumber), rightFreq(rightFreq) {}
};

const RangeFreq tmp(-1, -1, -1, -1, -1, -1);

RangeFreq merge(const RangeFreq& a, const RangeFreq& b) {
	if (a.size == -1 || b.size == -1)
		return (a.size == -1) ? b : a;
	RangeFreq ret;
	ret.size = a.size + b.size;
	ret.leftNumber = a.leftNumber;
	ret.leftFreq = a.leftFreq;
	if (a.size == a.leftFreq && a.leftNumber == b.leftNumber)
		ret.leftFreq += b.leftFreq;
	ret.rightNumber = a.rightNumber;
	ret.rightFreq = a.rightFreq;
	if (b.size == b.rightFreq && a.rightNumber == b.rightNumber)
		ret.rightFreq += a.rightFreq;
	ret.mostFrequent = std::max(a.mostFrequent, b.mostFrequent);
	if (a.rightNumber == b.leftNumber)
		ret.mostFrequent = std::max(ret.mostFrequent, a.rightFreq + b.leftFreq);
	return ret;
}

struct RMQ {
	int n;
	vector<RangeFreq> rangeFreq;
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeFreq = vector<RangeFreq>(n * 4);
		init(arr, 0, n - 1, 1);
	}

	RangeFreq init(const vector<int>& arr, int left, int right, int node) {
		if (left == right) { 
			RangeFreq t(1, 1, left, 1, left, 1);
			return rangeFreq[node] = t; 
		}
		int mid = (left + right) / 2;
		RangeFreq leftFreq = init(arr, left, mid, node * 2);
		RangeFreq rightFreq = init(arr, mid + 1, right, node * 2 + 1);
		return rangeFreq[node] = merge(leftFreq, rightFreq);
	}

	RangeFreq query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left < nodeRight)	return tmp;
		if (left <= nodeLeft && nodeRight <= right) return rangeFreq[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return merge(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		RangeFreq res = query(left, right, 1, 0, n - 1);
		return res.mostFrequent;
	}
};

int n, q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	struct RMQ rmq(arr);
	cout << rmq.query(1, 3) << '\n';
}