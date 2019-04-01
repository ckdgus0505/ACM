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
	sort(arr.begin(), arr.end(), [](pair<int, int>a, pair<int, int>b)->bool {	//algorithm의 sort 함수와 람다 식 사용
		if (a.first == b.first) {		//a의 x와 b의 x 가 같으면 y를 기준으로 정렬
			return a.second < b.second;
		}
		else return a.first < b.first; 
	});

	int minVal = numeric_limits<int>::max();
	for (int i = 0; i < N-1; ++i) {
		for (int j = i + 1; j < N; ++j) {// 이거 넣으면 O(n^2)
			int tmp = static_cast<int>(pow(static_cast<double>(arr[j].first - arr[i].first), 2.0)
				+ pow(static_cast<double>(arr[j].second - arr[i].second), 2.0));	//static_cast, dynamic_cast 는 C++에서 강제 형 변환 할때 사용하는 방법이다
			minVal = min(minVal, tmp);
		}
	}
	cout << minVal << '\n';
	return 0;
}