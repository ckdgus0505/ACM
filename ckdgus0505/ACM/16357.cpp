#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ys; // �Է¹��� y�� ����..
vector<int> rects; // �Է¹��� �簢������ y�࿡ ���翵��Ŵ

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rects.assign(20000001, 0);

	for (int i = 0; i < n; i++) {
		int ux, uy, vx, vy;
		cin >> ux >> uy >> vx >> vy;
		for (int j = vy + 10000000; j <= uy + 10000000; j++)
			rects[j]+= 1;
		ys.push_back(uy);
		ys.push_back(vy);
	}
	sort(ys.begin(), ys.end());
	int Max = 0;
	for (int iter = 0; iter < ys.size(); iter++) {
		for (int ite = 0; ite < ys.size(); ite++) {
			int tmp = rects[iter + 10000000] + rects[ite + 10000000];
			if (Max < tmp)
				Max = tmp;
		}
	}
	cout << Max << '\n';
}

