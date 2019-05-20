#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
using namespace std;
vector<int> order;
vector<int> cache;
int N; // number of children 2~200
int ci; // cache index;
int ordering(int, int);
int returnMax(); // return max value of cache;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	order.assign(N, 0);
	cache.assign(N + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> order[i];
	ordering(0, 1);
	cout << N - returnMax()<< '\n';
	return 0;
}
// �˰��� ���̵�� : N - 1 - �������� �ִ�ġ

int ordering(int base) // start, next �� order�� index�̴�. now�� ��������� �ִ�ġ
{
	int& ret = cache[base];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = base + 1; i < N; i++)
	{
		if (order[i] > order[base]) ret = max(ret, ordering(base) + 1);
	}
	return ret;
}
int returnMax()
{
	int max = 0;
	for (int i = 0; i < sizeof(cache); i++)
	{
		if (max < cache[i])
			max = cache[i];
	}
	return max;
}