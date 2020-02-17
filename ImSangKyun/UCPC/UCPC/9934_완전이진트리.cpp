#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
vector<int> arr;
vector<vector<int>> tree;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;


	cin >> K;
	tmp = K;
	tree = vector<vector<int>>(K+1, vector<int>(pow(2, K) - 1));
	arr = vector<int>(pow(2, K) - 1);

	for (int k = 0; k < pow(2, K) - 1; k++)
		cin >> arr[k];

	int i = 2;
	int t = 0;
	int j = 0;
	while (K--) {
		if (K <= 0)	break;
		for (int n = 0; n < pow(2, K); n++) {
			tree[K][j] = arr[n * i + t];
			j++;
		}

		i *= 2;
		t = (t + 1) * 2 - 1;
		j = 0;
	}

	tree[K][0] = arr[(int)pow(2, tmp) / 2 - 1];
	cout << tree[K][0] << endl;

	while (K++ != tmp) {
		for (int n = 0; tree[K][n] != 0; n++)
			cout << tree[K][n] << " ";
		if (K != tmp)
			cout << endl;
	}
}