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

	// ������������ ã�´�. // square_nn�� 0��° �迭�� mini������ �����Ѵ�.
	for (long long i = 2; i * i <= maxi; i++) {
		if (zegop[i] == true) continue;
		for (long long j = i; j * j <= maxi; j += i) zegop[j] = true;
		for (long long j = ((mini - 1) / (i * i) + 1) * i * i; j <= maxi; j += i * i)
			if (!zegop_nn[j - mini]) { zegop_nn[j - mini] = true; ans--; }
	}

	cout << ans << endl;
}