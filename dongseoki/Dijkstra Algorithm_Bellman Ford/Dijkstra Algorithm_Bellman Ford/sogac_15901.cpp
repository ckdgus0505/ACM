#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; //N���� ������.
int M; //M���� �Ұ��� ĭ
int K; // ���� K��.
int Q; // ��ɾ��� ����.

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
	int cnum; // ��ɾ� ��ȣ.

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