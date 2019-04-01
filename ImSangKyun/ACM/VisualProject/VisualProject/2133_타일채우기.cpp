#include <cstdio>

int cache1[31];
int cache2[31];

int func1(int num);
int func2(int num);

int func1(int num) {	//f
	int& ret = cache1[num];
	if (ret)	return ret;
	if (num == 2)	return 3;
	ret += 2 * func2(num - 1) + func1(num - 2);
	return ret;
}

int func2(int num) {	//g	
	int& ret = cache2[num];
	if (ret)	return ret;
	if (num == 3)	return 4;
	ret += func1(num - 1) + func2(num - 2);
	return ret;
}

int main(void) {
	int N;
	scanf("%d", &N);
	if (N % 2 != 0) {
		printf("0");
		return 0;	//주의... -1로 했다가 런타임에러 떳음
	}
	printf("%d\n", func1(N));
	return 0;
}