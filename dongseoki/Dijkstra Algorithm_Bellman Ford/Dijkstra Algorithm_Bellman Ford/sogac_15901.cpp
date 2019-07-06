
//https://twpower.github.io/76-how-to-use-queue-in-cpp


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; //N���� ������.
int M; //M���� �Ұ��� ĭ
int K; // ���� K��.
int Q; // ��ɾ��� ����.
int L, R; // �Ұ� ��ġ.
int p, q; // p�� ������ ������ q���� ���� ��⿭ �ڿ� �ִ´�.
int t; // ��Ȱ���� ���� ���� ��⿭ �� ���� ������ t���� �����Ѵ�.
vector<int> sogac;
queue<int> wait;

int command(int cnum) {
	
}

void sogac_jacup(void) {
	//�̷��� �� �� �¿�� ���� L�� ĭ���� R�� ĭ������ ��� �Ǵµ�, 
	//�׶� ��⿭�� �տ������� ������� �����⸦ ������ L�� ĭ���� R�� ĭ���� ä���. 
	//�����⸦ ������ ä��ٰ� �� �̻� ��⿭ �� �����Ⱑ ���� �ʾ����� �� �ڷδ� �ƹ��͵� ���� �ʴ´�.
	cin >> L, R;
	// �¿��
	for (int i = L; i <= R; i++)
		sogac[i] = 0;
	int qsize = wait.size();

	// ������ ������ ä���. 
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
	//p�� ������ ������ q���� ���� ��⿭ �ڿ� �ִ´�.
	cin >> p;
	cin >> q;
	for (int i = 0; i < q; i++) {
		wait.push(p);
	}
}
void recycle(void) {
	//��Ȱ���� ���� ���� ��⿭ �� ���� ������ t���� �����Ѵ�.
	int qsize = wait.size();
	for (int t = 0; t < min(t, qsize); t++)
		wait.pop();

}

int main(void) {
	cin >> N, M, K, Q;
	int cnum; // ��ɾ� ��ȣ.

	sogac.assign(M+1, 0); // index 1���� ���! 
	//�Ұ��δ� M���� ĭ�� �Ϸķ� �����Ǿ��ִ� ����



	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		wait.push(ai);
	}

	//�� ó������ ��⿭�� �տ������� ������� min(N, M)���� �����⸦ ������ �Ұ����� 1�� ĭ���� min(N, M)�� ĭ���� ������� ���Ƶд�.
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