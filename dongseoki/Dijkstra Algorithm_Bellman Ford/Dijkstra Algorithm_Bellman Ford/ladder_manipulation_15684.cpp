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
	//for 문으로 가로선을 넣는다.
	// 사다리를 태운다 게임 시작
	// 모두가 전부 같다면
	// 진실을 반환한다.
	// 아니면(모든경우에 대해) false를 반환한다.
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
	//for 문으로 가로선을 넣는다.
	// 사다리를 태운다 게임 시작
	// 모두가 전부 같다면
	// 진실을 반환한다.
	// 아니면(모든경우에 대해) false를 반환한다.

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
	int N; // 세로선개수
	int M; // 가로선 개수
	int H; // 가로선을 놓을 수 있는 위치 개수
	cin >> N;
	cin >> M;
	cin >> H;
	vector<vector<int>> l_t(H+1, vector<int>(N, 0)); 
	//l_t는 ladder_table 의 약자.
	// index 0는 버린다. 그리고 H는 좌측가로선을 기준으로 해서 개수는 H-1 이다.
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
