#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int N;
vector<int> arr;
const int maxVal = numeric_limits<int>::max();
const int minVal = numeric_limits<int>::min();
const int MOD = 1000000000 + 1;

int func(int idx, int plus, int min, int mul, int div, bool high) {
	if (idx == N - 1)	return arr[idx];
	int res1 = minVal;//ÃÖ´ñ°ª 
	int	res2 = maxVal;//ÃÖ¼Ú°ª

	if (plus > 0) {
		res1 = std::max(res1, func(idx + 1, plus - 1, min, mul, div, true) + arr[idx]);
		res2 = std::min(res2, func(idx + 1, plus - 1, min, mul, div, false) + arr[idx]);
	}
	if (min > 0) {
		res1 = std::max(res1, func(idx + 1, plus, min-1, mul, div, true) - arr[idx]);
		res2 = std::min(res2, func(idx + 1, plus, min-1, mul, div, false) - arr[idx]);
	}
	if (mul > 0) {
		res1 = std::max(res1, func(idx + 1, plus, min, mul-1, div, true) * arr[idx]);
		res2 = std::min(res2, func(idx + 1, plus, min, mul-1, div, false) * arr[idx]);
	}
	if (div > 0) {
		res1 = std::max(res1, func(idx + 1, plus, min, mul, div-1, true) / arr[idx]);
		res2 = std::min(res2, func(idx + 1, plus, min, mul, div-1, false) / arr[idx]);
	}
	res1 %= MOD;
	res2 %= MOD;
	if (high)	return res1;
	else
		return res2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	std::reverse(arr.begin(), arr.end());

	int plus, min, mul, div, high, low;

	cin >> plus >> min >> mul >> div;
	
	high = func(0, plus, min, mul, div, true);
	low = func(0, plus, min, mul, div, false);
	
	cout << high << '\n' << low << '\n';
}