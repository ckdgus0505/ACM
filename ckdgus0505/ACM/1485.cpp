#include<iostream>
#include<math.h>
using namespace std;

typedef pair<int, int> pos;
int T; // testcase
pos a, b, c, d;
double sqdistance(pos a, pos b);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int i = 0; i < T; i++) {
		double ab = 0;
		double bc = 0;
		double cd = 0;
		double ad = 0;
		double ac = 0;
		double bd = 0;

		cin >> a.first >> a.second;
		cin >> b.first >> b.second;
		cin >> c.first >> c.second;
		cin >> d.first >> d.second;
		ab = sqdistance(a, b);
		bc = sqdistance(b, c);
		cd = sqdistance(c, d);
		ac = sqdistance(a, c);
		ad = sqdistance(a, d);
		bd = sqdistance(b, d);

		if ((ab == bc) && (cd == ad) && (ab == cd)) { // ac가 대각선
			if (ab + ad - bd == 0)
				cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if ((ab == cd) && (ac == bd) && (ab == ac)) { // ad가 대각선
				if (ab + ac - bc == 0)
					cout << 1 << '\n';
				else cout << 0 << '\n';
		}
		else if ((ac == bc) && (ad == bd) && (ac == ad)) { // ab가 대각선

				if (ac + ad - cd == 0)
					cout << 1 << '\n';
				else cout << 0 << '\n';
		}
		else cout << 0 << '\n';

	}
}
double sqdistance(pos a, pos b) {
	return pow((double)(a.first - b.first), 2.0) + pow((double)(a.second - b.second), 2.0);
}