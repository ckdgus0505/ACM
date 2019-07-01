#include <iostream>
#include <vector>


using namespace std;

bool adjcheck(int row, int col, vector<vector<int>>& l_t, int N) {

	if(col-1>=1)
		if (l_t[row][col - 1] == 1)
			return true;
	if(col+1<=N-1)
		if (l_t[row][col + 1] == 1)
			return true;

	return false;
}

bool riding_ladders(int MRL, vector<vector<int>> &l_t, int N, int M, int H) {
	//MRL => Max Row Line
	//for ������ ���μ��� �ִ´�.
	// ��ٸ��� �¿�� ���� ����
	// ��ΰ� ���� ���ٸ�
	// ������ ��ȯ�Ѵ�.
	// �ƴϸ�(����쿡 ����) false�� ��ȯ�Ѵ�.
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (l_t[i][j] != 1)
				if (!adjcheck(i, j, l_t, N)) {
					addline(count+1)
				}
		}
	}
	game_start()
}

bool addline(int count, int obj, vector<vector<int>>& l_t, int N, int M, int H) {
	//MRL => Max Row Line
	//for ������ ���μ��� �ִ´�.
	// ��ٸ��� �¿�� ���� ����
	// ��ΰ� ���� ���ٸ�
	// ������ ��ȯ�Ѵ�.
	// �ƴϸ�(����쿡 ����) false�� ��ȯ�Ѵ�.

	if (count == obj) {
		return riding_ladders();
	}
	if (count > obj) {
		return false;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (l_t[i][j] != 1)
				if (!adjcheck(i, j, l_t, N)) {
					l_t[i][j] = 1;
					addline(count + 1, obj, l_t, N, M, H);
					l_t[i][j] = 0;
				}
		}
	}
	return false;
}


int main(void) {
	int N; // ���μ�����
	int M; // ���μ� ����
	int H; // ���μ��� ���� �� �ִ� ��ġ ����
	cin >> N;
	cin >> M;
	cin >> H;
	vector<vector<int>> l_t(H+1, vector<int>(N, 0)); 
	//l_t�� ladder_table �� ����.
	// index 0�� ������. �׸��� H�� �������μ��� �������� �ؼ� ������ H-1 �̴�.
	int row;
	int col;
	for (int i = 0; i < M; i++) {
		cin >> row;
		cin >> col;
		l_t[row][col] = 1;
	}

	for (int i = 0; i <= M;i++) {
		if (addline(0, i, l_t, N, M, H)) {
			cout << i;
			return;
		}
	}
	cout << -1;
	return;

	cout << "success\n";
}
