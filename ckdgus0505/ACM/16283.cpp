#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, n, w;

	int x, y;
	cin >> a >> b >> n >> w;

	if (a == b) { // ��� ������ ���� ���� ���
		if (a + b == w && a == w / (double)n)
			cout << 1 << ' ' << 1 << '\n'; // 
		else cout << -1 << '\n';
	}
	else { // ��� ������ ���� �ٸ� ���
		x = (b * n - w) / (double)(b - a);
		y = (w - (a * n)) / (double)(b - a);
		if (((x - (int)x) == 0) && ((y - (int)y) == 0)) // x,y�� ����
			if (x >= 1 && y >= 1) //x,y�� 1���� ū ����
				cout << x << ' ' << y << endl;
			else cout << -1 << '\n';
		else cout << -1 << '\n';
	}
}