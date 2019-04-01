#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> arr;

void func(int size, int y, int x) {
	if (size == 1) {
		cout << arr[y][x];
		return;
	}

	int pivot = arr[y][x];
	bool close = false;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[y+i][x+j] != pivot) {
				i = j = size;
				close = true;
				cout << "(";
				int half = size / 2;
				func(half, y+0, x+0);
				func(half, y+0, x+half);
				func(half, y+half, x+0);
				func(half, y+half, x+half);
			}
		}
	}
	if (close)	
		cout << ")";
	else
		cout << pivot;
	
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N, 0));
	string str;

	for (int i = 0; i < N; ++i) {
		cin >> str;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = str.at(j) - '0';
		}
	}
	func(N, 0, 0);
	return 0;
}

/*
void qaurdtree(int x, int y, int n)
{
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[y + i][x + j] == '1')
				cnt++;
		}
	}

	if (cnt == n*n) {
		printf("1");
		return;
	}
	else if (cnt == 0) {
		printf("0");
		return;
	}

	printf("(");
	qaurdtree(x, y, n / 2);
	qaurdtree(x + n / 2, y, n / 2);
	qaurdtree(x, y + n / 2, n / 2);
	qaurdtree(x + n / 2, y + n / 2, n / 2);
	printf(")");
}
*/