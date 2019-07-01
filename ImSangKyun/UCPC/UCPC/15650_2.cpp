#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void func(int num, int toPick) {
	if (toPick == 0) {	//1. �������(Ż�� ����)
		for (auto& iter : arr)
			cout << iter << " ";
		cout << '\n';
		return;
	}
	for (int i = num + 1; i <= N; ++i) {	//2. ����
		arr.push_back(i);
		func(i, toPick - 1);
		arr.pop_back();
	}
	//3. �ڽĿ��� �Ѱ��� �ڷ� ����
	//4. �ڽ����κ��� ��ȯ�� �ڷ� ����
	//5. �θ𿡰� ��ȯ �� ���
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	func(0, M);

	return 0;
}