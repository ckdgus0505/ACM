#include <cstdio>
using namespace std;

int cache[1001];

int func(int n) {
	int& ret = cache[n];
	if (ret)	return ret;
	if (n == 1 || n == 0)	return 1;
	ret += (func(n - 2) + func(n - 1)) % 10007;
	return ret;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", func(n));
	return 0;
}