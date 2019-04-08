#include <iostream>
using namespace std;

int main(void) {
	int A[100][100], B[100][100], C[100][100] = { 0, }, n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> A[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < k; ++j)
			cin >> B[j][k];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < m; ++l) {
				C[i][j] += A[i][l] * B[l][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) 
			cout << C[i][j] << ' ';
		cout << '\n';
	}
}