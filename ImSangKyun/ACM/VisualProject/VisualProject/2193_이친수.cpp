/*
	규칙성 찾기
	1. 처음 시작은 무조건 1이다
	2. 맨 Top의 노드는 1에서 시작해서 0 과 1로 나눠져 간다

	//뭐지 왜 피보나치가 되지
	
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