#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> arr;

enum Direction { left, up, right, down };
int directX[4] = {-1, 0, 1, 0};	//Left, Up, Right, Down
int directY[4] = {0, -1, 0, 1};

bool isRange(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n)
		return true;
	return false;
}

bool isDot(int x, int y) {
	if (arr[y][x] == '.')
		return true;
	return false;
}

bool isWall(int x, int y) {
	if (arr[y][x] == '#')
		return true;
	return false;
}

bool isWhole(int x, int y) {
	if (arr[y][x] == 'O')
		return true;
	return false;
}

int moveBead(vector<vector<int>>& arr, int direct) {	//direct 방향으로 구슬을 이동한 결과를 arr에 담는다	0:이상없음, 1: Red가 구멍에 들어감, -1: Blue가 구멍에 들어감
	int Bx, By, Rx, Ry;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			if (arr[i][j] == 'B') {
				By = i;	Bx = j;
			}
			if (arr[i][j] == 'R') {
				Ry = i;	Rx = j;
			}
		}
	}

	int ret = 0;
	bool BRed, BBlue;
	BRed = BBlue = true;
	while (true) {
		int nextRY, nextRX, nextBY, nextBX;
		nextRY = Ry + directY[direct];
		nextRX = Rx + directX[direct];
		nextBY = By + directY[direct];
		nextBX = Bx + directX[direct];

		if (!BRed && !BBlue)	break;
		if (!isRange(nextBX, nextBY))
			BBlue = false;
		if (!isRange(nextRX, nextRY))
			BRed = false;


		if (BBlue && isDot(nextBX, nextBY)) {
			arr[By][Bx] = '.';
			arr[nextBY][nextBX] = 'B';
			By = nextBY;
			Bx = nextBX;
		}
		else if (BBlue && isWhole(nextBX, nextBY)) {
			ret - 1;
			By = nextBY;
			Bx = nextBX;
			BBlue = false;
		}
		else if (BBlue && isWall(nextBX, nextBY))
			BBlue = false;
		else if (BBlue && arr[nextBY][nextBX] == 'R')
			if (!BRed)
				BBlue = false;

		if (BRed && isDot(nextRX, nextRY)) {
			arr[Ry][Rx] = '.';
			arr[nextRY][nextRX] = 'R';
			Ry = nextRY;
			Rx = nextRX;
		}
		else if (BRed && isWhole(nextRX, nextRY) && ret != -1) {
			ret = 1;
			arr[Ry][Rx] = '.';
			Ry = nextRY;
			Rx = nextRX;
			BRed = false;
		}
		else if (BRed && isWall(nextRX, nextRY))
			BRed = false;
		else if (BRed && arr[nextRY][nextRX] == 'B')
			if (!BBlue)
				BRed = false;
	}
	return ret;
}

int solution(vector<vector<int>> arr, int cnt, int before) {
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char ch;

	cin >> n >> m;
	arr = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			arr[i][j] = static_cast<int>(ch);
		}
	}
	
	int res = moveBead(arr, Direction::left);
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			cout << static_cast<char>(arr[i][j]);
		}
		cout << '\n';
	}
	cout << res << '\n';

	//int res = solution(arr, 0);
	//cout << res << '\n';

	return 0;
}

/*	DEBUG용 코드
	int res = moveBead(arr, Direction::left);
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			cout << static_cast<char>(arr[i][j]);
		}
		cout << '\n';
	}
	cout << res << '\n';

*/