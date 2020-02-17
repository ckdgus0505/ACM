#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long distance(int x1, int y1, int x2, int y2) {	//두 점 사이의 거리의 제곱을 반환
	int d1 = x1 - x2, d2 = y1 - y2;
	return d1 * d1 + d2 * d2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int iter = 0; iter < T; ++iter) {
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long long d = distance(x1, y1, x2, y2);
		long long add = r1 + r2; add *= add;
		long long sub = r1 - r2; sub *= sub;
		
		if (sub < d && d < add)	// sub < d < add  : 원이 두 점에서 만남
			cout << 2 << '\n';
		else if (add == d || (d == sub && d != 0)) // 외접하거나 내접하되 두 점이 서로 일치하지 않는경우 (두 점까지 일치하면 값이 무수히 많음)
			cout << 1 << '\n';
		else if (d < sub || add < d)	//내접하지도 외점하지도 않음(교점이 없음)
			cout << 0 << '\n';
		else if (d == 0) {	// 두 점이 서로 일치
			if (r1 == r2)	//반지름 길이가 같으면 해가 무수히 많음
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}