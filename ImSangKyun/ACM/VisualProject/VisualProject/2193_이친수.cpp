/*
	��Ģ�� ã��
	1. ó�� ������ ������ 1�̴�
	2. �� Top�� ���� 1���� �����ؼ� 0 �� 1�� ������ ����

	//���� �� �Ǻ���ġ�� ����
	
*/
/*
	#first code
#include <cstdio>
using namespace std;

int N;
int cache[91][2];

int func(int floor, int val) {
	int& ret = cache[floor][val];
	if (ret)	return ret;
	if (floor == N)	return 1;
	ret = 0;
	if (!val) {
		ret += func(floor + 1, 1);
	}
	ret += func(floor + 1, 0);
	return ret;
}

int main(void) {
	scanf("%d", &N);
	printf("%d\n", func(1, 1));
}

*/

#include <cstdio>

int N;
long long cache[91];

long long func(int x) {
	long long& ret = cache[x];
	if (ret)	return ret;
	if (x == 1 || x == 2)	return 1;
	return ret = func(x - 1) + func(x - 2);
}

int main(void) {
	cache[1] = cache[2] = 1;
	scanf("%d", &N);
	printf("%lld\n", (N > 2) ? func(N) : 1);
}