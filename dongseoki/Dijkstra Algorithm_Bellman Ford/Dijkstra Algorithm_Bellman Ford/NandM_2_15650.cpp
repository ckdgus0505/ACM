#include <iostream>
using namespace std;

int intarr[9];
int main(void) {
	int N;
	int M;
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio ��ũ�� ���ϸ� �ӵ��� �������� ���Ϸ� ��밡���ϴٸ� �˼� ����.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie ���ϸ� �Է��� ���� �ް� �ȴ�.  �ӵ� ����� ����
	cin >> N;
	cin >> M;

	selected(0);
	
	return 0;
}

void selected(int count){
	if (count == M) {
		print_numbers();
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (intarr[i] != 0) {
			intarr[i] = 1;
			selected(count + 1);
			intarr[i] = 0;
		}

	}
}


void print_numbers() {
	for (int i = 1; i < N; i++) {
		if (intarr[i] == 1)
			cout << i << " ";
	}
}