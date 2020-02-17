#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxInt = numeric_limits<int>::max();
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

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)	return maxInt;	//찾고자 하는 범위를 벗어나면 최댓값을 반환하여 반환값이 무시되도록 함
		if (left <= nodeLeft && nodeRight <= right)	return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)	return rangeMin[node];
		if (nodeLeft == nodeRight)	return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


}