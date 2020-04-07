#include <iostream>
#include <vector>
using namespace std;

vector <vector<int> > paper;
vector <int> cp;
int ans = 26;

void input();
int convolution(int r, int c, int n, vector<vector<int>> bp);
vector<vector<int>> cover(int r, int c, int n, vector<vector<int>> bp);
int dynamic(int r, int c, vector<int> cp, vector<int> bp);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	dynamic(0, 0, cp, paper);
	cout << ans << endl;
}
void input() {

	paper.assign(10, vector<int>(10, 0));
	cp.assign(6, 5);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}
}

int convolution(int r, int c, int n, vector<vector<int>> bp) { // 색종이를 넣을 수 있으면 1, 없으면, 0, 종이가 작으면 -1;
	if (r + n <= 10 && c + n <= 10) {
		int res = 1;
		for (int i = r; i < r + n; i++) {
			for (int j = c; j < c + n; j++) {
				res *= bp[i][j];
			}
		}
		return res;
	}
	else return -1;
}

vector<vector<int>> cover(int r, int c, int n, vector<vector<int> > bp) {
	vector <vector <int>> tmp = bp;
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			bp[i][j] = 0;
		}
	}
	return tmp;
}

int dynamic(int r, int c, vector<int> cp, vector<vector<int>> bp) {
	
	if (r == 9 && c == 9) {
		int ret = 25;
		for (int i = 1; i <= 5; i++) {
			ret -= cp[i];
		}
		if (ans >= 1 && ans <= 25) {
			if (ret < ans) ans = ret;
		}
		return ret;
	}

	if (bp[r][c] == 1) {
		int i, j;
		for (i = 5; i > 0; i--) {
			if (convolution(r, c, i, bp) != 1) break;
		}
		for (j = i; j <= 5; j++) {
			vector<int> ncp = cp;
			if (cp[i] >= 1) cp[i]--;
			else return -1;
			if (c + i < 10)
			dynamic (r, c+i, ncp, cover(r, c, j, bp));
			else 
			dynamic(r+1, 0, ncp, cover(r, c, j, bp));
		}
	}
}