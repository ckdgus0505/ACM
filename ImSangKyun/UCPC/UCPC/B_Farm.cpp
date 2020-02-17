#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int a, b, n, w, cnt = 0, res;
	cin >> a >> b >> n >> w;
	for (int i = 1; i < n; ++i) {
		if (a*i + b * (n - i) == w) {
			++cnt;
			res = i;
		}
	}
	if (cnt != 1)	cout << -1 << '\n';
	else	cout << res << " " << n - res << '\n';
}