#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void func(int num, int toPick) {
	if (toPick == 0) {	//1. �������(Ż�� ����)
		for (auto& iter : arr)
			cout << iter << " ";
		cout << num << '\n';
		return;
	}
	arr.push_back(num);
	for (int i = num + 1; i <= N; ++i) {	//2. ����
		func(i, toPick - 1);
	}
	arr.pop_back();
	//3. �ڽĿ��� �Ѱ��� �ڷ� ����
	//4. �ڽ����κ��� ��ȯ�� �ڷ� ����
	//5. �θ𿡰� ��ȯ �� ���
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		func(i, M-1);
	}

	return 0;
}