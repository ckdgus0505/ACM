#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; //N개의 쓰레기.
int M; //M개의 소각로 칸
int K; // 종류 K개.
int Q; // 명령어의 개수.

vector<int> sogac;

int command(int cnum) {
	
}

void sogac_jacup(void) {

}
void print_waste(void) {

}
void insert(void) {

}
void recycle(void) {

}

int main(void) {
	cin >> N, M, K, Q;
	int cnum; // 명령어 번호.

	sogac.assign(M, 0);



	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		wait.push_back(ai);
	}

	wait.pop
		

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
	}
	return 0;
}