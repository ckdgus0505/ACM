#include <iostream>
#include <vector>
using namespace std;

vector<int> dx, dy;
long long distance(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;
	return x * x + y * y;
}

int main(void) {
	int T;
	cin >> T;
	for (int iter = 0; iter < T; ++iter) {
		dx = dy = vector<int>(4, 0);
		for (int i = 0; i < 4; ++i) 
			cin >> dx[i] >> dy[i];
		
		long long base = distance(dx[0], dy[0], dx[3], dy[3]);
		bool flag = true;
		for (int i = 0; i < 3; ++i) {
			if (distance(dx[i], dy[i], dx[i + 1], dy[i + 1]) != base)
				flag = false;
		}
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}