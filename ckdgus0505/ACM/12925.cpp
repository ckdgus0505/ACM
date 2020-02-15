#include <string>
#include <vector>
#include <iostream>

using namespace std;
int cnt = 0;
vector<int> col_v;
vector<int> cross1_v;
vector<int> cross2_v;
int cnt_v = 0;

void dfs(int n, int row, int col);

int solution(int n) {
	vector<vector<int>> map;
	int answer = 0;
	col_v.assign(n, 0);
	cross1_v.assign(2 * n - 1, 0);
	cross2_v.assign(2 * n - 1, 0);
	dfs(n, -1, -1);
	return cnt;
}

void dfs(int n, int row, int col) {
	if (cnt_v == n) {
		cnt++;
		return;
	}
	if (row == -1 && col == -1) {
		for (int i = 0; i < n; i++) {
			col_v[i] = 1;
			cross1_v[i] = 1;
			cross2_v[n-1-i] = 1;
			cnt_v++;

			dfs(n, 0, i);

			col_v[i] = 0;
			cross1_v[i] = 0;
			cross2_v[n - 1 - i] = 0;
			cnt_v--;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (col_v[i] == 1 || cross1_v[row+1 + i] == 1 || cross2_v[row+1+n-1-i] == 1) continue;
			else {
				col_v[i] = 1;
				cross1_v[row + 1 + i] = 1;
				cross2_v[row + 1 + n - 1 - i] = 1;
				cnt_v++;

				dfs(n, row+1, i);

				col_v[i] = 0;
				cross1_v[row + 1 + i] = 0;
				cross2_v[row + 1 + n - 1 - i] = 0;
				cnt_v--;
			}
		}
	}
	return;
}

int main(void) {
	cout << solution(4) << endl;
}
