#include<iostream>
#include<cstring>
using namespace std;
int cache[1001];

int an(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;

	int & ret = cache[n];
	if (ret != -1) return ret;

	ret = (an(n - 1)%10007 + an(n - 2)%10007) % 10007;

	return ret;
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	int n;
	cin >> n;
	cout << an(n) << "\n";

	return 0;
}