#include <iostream>
using namespace std;

int intarr[9];
int main(void) {
	int N;
	int M;
	ios_base::sync_with_stdio(0); // https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio 싱크를 안하면 속도가 빨라진다 단일로 사용가능하다를 알수 있음.
	cin.tie(0); // https://codecollector.tistory.com/381 , https://su-m.tistory.com/7 , tie 안하면 입력을 먼저 받게 된다.  속도 향상은 가능
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