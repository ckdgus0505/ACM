#include <iostream>
#include <cmath>
using namespace std;
bool zegop[1000001] = { false };
bool zegop_nn[1000001] = { false };

long long maxi;
long long mini;
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> mini >> maxi;
	ans = maxi-mini+1;

	// 제곱ㄴㄴ수를 찾는다. // square_nn의 0번째 배열을 mini값으로 가정한다.
	for (long long i = 2; i * i <= maxi; i++) {
		if (zegop[i] == true) continue;
		for (long long j = i; j * j <= maxi; j += i) zegop[j] = true;
		for (long long j = ((mini - 1) / (i * i) + 1) * i * i; j <= maxi; j += i * i)
			if (!zegop_nn[j - mini]) { zegop_nn[j - mini] = true; ans--; }
	}

	cout << ans << endl;
}