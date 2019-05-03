#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> order;
int cache[40000];
int N; // number of children 2~200
int ci; // cache index;
void ordering(int, int, int, int);
int returnMax(); // return max value of cache;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	order.assign(N, 0); 
	memset(cache, 0, sizeof(cache));

	for (int i = 0; i < N; i++)
		cin >> order[i];
	ordering(0, 1, order[0], 0);
	cout << N - 1 - returnMax()<< '\n';
	return 0;
}
// 알고리즘 아이디어 : N - 1 - 오름차순 최대치

void ordering(int start, int next, int now, int max) // start, next 는 order의 index이다. now는 현재까지의 최대치
{
	if (start >= N - 1) return;

	if (next >= N)
	{
		cache[ci++] = max;
		ordering(start + 1, start + 2, order[start + 1], 0);
	}
	else
	{
		if (now < order[next])
		{
			ordering(start, next + 1, order[next], max + 1);
			ordering(start, next + 1, now, max);
		}
		else if (now > order[next])
			ordering(start, next + 1, now, max);
	}
}

int returnMax()
{
	int max = 0;
	for (int i = 0; i < ci; i++)
	{
		if (max < cache[i])
			max = cache[i];
	}
	return max;
}