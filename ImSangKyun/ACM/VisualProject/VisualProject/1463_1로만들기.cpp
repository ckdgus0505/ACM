#include <cstdio>
#include <memory.h>
using namespace std;

int cache[1000001];

int func(int N) {
	int& ret = cache[N];
	if (ret)	return ret;
	if (N == 1)	return 0;
	if (N < 1)	return 99999999;
	
	int tmp;
	ret = 99999999;
	if (!(N % 3)) {
		tmp = func(N / 3) + 1;
		ret = (ret > tmp) ? tmp : ret;
	}
	if (!(N % 2)) {
		tmp = func(N / 2) + 1;
		ret = (ret > tmp) ? tmp : ret;
	}
	tmp = func(N - 1) + 1;
	ret = (ret > tmp) ? tmp : ret;
	return ret;
}

int main(void) {
	int X;
	memset(cache, 0, sizeof(cache));

	scanf("%d", &X);
	printf("%d\n", func(X));
}
/*
	# 1위 코드
	#import<map>
	int f(int a){return a<2?0:std::min(f(a/2)+a%2,f(a/3)+a%3)+1;}main(int n){scanf("%d",&n),printf("%d",f(n));}


	#2 C타입 코드
	#include <stdio.h>
	int solve(int x) {
		if (x <= 1) return 0;
		int d1 = solve(x / 3) + (x % 3) + 1;
		int d2 = solve(x / 2) + (x % 2) + 1;
		return d1 < d2 ? d1 : d2;
	}

	int main() {
		int N; scanf("%d", &N);
		printf("%d", solve(N));
	}
*/