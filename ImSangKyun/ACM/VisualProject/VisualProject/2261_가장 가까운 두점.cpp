#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
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
	sort(arr.begin(), arr.end(), [](pair<int, int>a, pair<int, int>b)->bool {	//algorithm�� sort �Լ��� ���� �� ���
		if (a.first == b.first) {		//a�� x�� b�� x �� ������ y�� �������� ����
			return a.second < b.second;
		}
		else return a.first < b.first; 
	});

	int minVal = numeric_limits<int>::max();
	for (int i = 0; i < N-1; ++i) {
		for (int j = i + 1; j < N; ++j) {// �̰� ������ O(n^2)
			int tmp = static_cast<int>(pow(static_cast<double>(arr[j].first - arr[i].first), 2.0)
				+ pow(static_cast<double>(arr[j].second - arr[i].second), 2.0));	//static_cast, dynamic_cast �� C++���� ���� �� ��ȯ �Ҷ� ����ϴ� ����̴�
			minVal = min(minVal, tmp);
		}
	}
	cout << minVal << '\n';
	return 0;
}