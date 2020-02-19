#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long distance(int x1, int y1, int x2, int y2) {	//�� �� ������ �Ÿ��� ������ ��ȯ
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
		
		if (sub < d && d < add)	// sub < d < add  : ���� �� ������ ����
			cout << 2 << '\n';
		else if (add == d || (d == sub && d != 0)) // �����ϰų� �����ϵ� �� ���� ���� ��ġ���� �ʴ°�� (�� ������ ��ġ�ϸ� ���� ������ ����)
			cout << 1 << '\n';
		else if (d < sub || add < d)	//���������� ���������� ����(������ ����)
			cout << 0 << '\n';
		else if (d == 0) {	// �� ���� ���� ��ġ
			if (r1 == r2)	//������ ���̰� ������ �ذ� ������ ����
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}