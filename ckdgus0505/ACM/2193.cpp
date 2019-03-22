#include<iostream>
#include<cstring>
using namespace std;
long long int cache[91];

long long int bn(int n)
{
	if (n == 0) return 0; //bn 을 저장하는 배열, bn은 an중 마지막이 0 인 것
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 2;

	long long int & ret = cache[n];
	if (ret != -1) return ret;

	ret = bn(n - 1) + bn(n - 2);

	return ret;
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	int n;
	cin >> n;
	cout << bn(n) << "\n";

	return 0;
}