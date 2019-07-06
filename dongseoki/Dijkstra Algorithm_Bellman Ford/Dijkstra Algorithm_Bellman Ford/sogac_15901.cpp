
//https://twpower.github.io/76-how-to-use-queue-in-cpp


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; //N개의 쓰레기.
int M; //M개의 소각로 칸
int K; // 종류 K개.
int Q; // 명령어의 개수.
int L, R; // 소각 위치.
int p, q; // p번 종류의 쓰레기 q개를 현재 대기열 뒤에 넣는다.
int t; // 재활용을 위해 현재 대기열 맨 앞의 쓰레기 t개를 제거한다.
vector<int> sogac;
queue<int> wait;

int command(int cnum) {
	
}

void sogac_jacup(void) {
	//이렇게 한 번 태우고 나면 L번 칸부터 R번 칸까지는 비게 되는데, 
	//그때 대기열의 앞에서부터 순서대로 쓰레기를 가져와 L번 칸부터 R번 칸까지 채운다. 
	//쓰레기를 가져와 채우다가 더 이상 대기열 상에 쓰레기가 남지 않았으면 그 뒤로는 아무것도 놓지 않는다.
	cin >> L, R;
	// 태우기
	for (int i = L; i <= R; i++)
		sogac[i] = 0;
	int qsize = wait.size();

	// 쓰레기 가져와 채우기. 
	for (int i = L; i <= min((R - L + 1), qsize); i++) {
		sogac[i] = wait.front();
		wait.pop();
	}
	
}
void print_waste(void) {
	int i =1;
	cin >> i;
	cout << sogac[i] << " ";
}

void print_sogac(void) {
	for (int i = 1; i <= M; i++)
		cout << sogac[i] << " ";
}

void insert(void) {
	//p번 종류의 쓰레기 q개를 현재 대기열 뒤에 넣는다.
	cin >> p;
	cin >> q;
	for (int i = 0; i < q; i++) {
		wait.push(p);
	}
}
void recycle(void) {
	//재활용을 위해 현재 대기열 맨 앞의 쓰레기 t개를 제거한다.
	int qsize = wait.size();
	for (int t = 0; t < min(t, qsize); t++)
		wait.pop();

}

int main(void) {
	cin >> N, M, K, Q;
	int cnum; // 명령어 번호.

	sogac.assign(M+1, 0); // index 1부터 사용! 
	//소각로는 M개의 칸이 일렬로 나열되어있는 구조



	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		wait.push(ai);
	}

	//맨 처음에는 대기열의 앞에서부터 순서대로 min(N, M)개의 쓰레기를 가져와 소각로의 1번 칸부터 min(N, M)번 칸까지 순서대로 놓아둔다.
	for (int i = 1; i <= min(N, M); i++) {

		sogac[i] = wait.front();
		wait.pop();
	}
		
		

	for (int i = 0; i < Q; i++) {
		cin >> cnum;
		switch (cnum) {
		case 1:
			sogac_jacup();
			break;
		case 2:
			print_waste();
			break;
		case 3:
			insert();
			break;
		case 4:
			recycle();
			break;
		}
		cout << "\n";
		print_sogac();
	}
	return 0;
}