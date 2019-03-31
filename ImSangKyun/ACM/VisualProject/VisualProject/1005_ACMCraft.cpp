#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, W;
vector<vector<int>> arr;	//��� ������, x->y �϶� arr[y].push_back(x) �� ��������
vector<int> time;	//�� �ǹ��� ���µ� �ʿ��� �ð�
vector<int> cache;	//�޸������̼�

int func(int node) {
	int& ret = cache[node];
	if (ret != -1)	return ret;	
	if (arr[node].empty())	return time[node];	//���������� �ݵ�� 1�� �ƴϹǷ� �������� ���ֵ� ���� ���� �ٷ� ����
	for (auto iter : arr[node]) {
		ret = max(ret, func(iter) + time[node]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int lo = 0; lo < T; ++lo) {
		cin >> N >> K;
		arr = vector<vector<int>>(N+1);
		time = vector<int>(N + 1, 0);
		cache = vector<int>(N + 1, -1);
		for (int i = 1; i <= N; ++i) 
			cin >> time[i];
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			arr[y].push_back(x);
		}
		cin >> W;

		cout << func(W) << '\n';
	}

}