#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void func(int num, int toPick) {
	if (toPick == 0) {	//1. 기저사례(탈출 조건)
		for (auto& iter : arr)
			cout << iter << " ";
		cout << '\n';
		return;
	}
	for (int i = num + 1; i <= N; ++i) {	//2. 전개
		arr.push_back(i);
		func(i, toPick - 1);
		arr.pop_back();
	}
	//3. 자식에게 넘겨줄 자료 선정
	//4. 자식으로부터 반환된 자료 관리
	//5. 부모에게 반환 할 방법
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	func(0, M);

	return 0;
}