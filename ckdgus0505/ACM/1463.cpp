#include<iostream>
#include<cstring>
using namespace std;
int cache[1000001];

int func(int n)
{
	cache[1] = 0;
	for (int i = 2; i < 1000001; i++)
	{
		cache[i] = cache[i - 1] + 1;

		if (i % 2 == 0 && cache[i] > cache[i / 2] + 1)
		{
			cache[i] = cache[i / 2] + 1;
		}

		if (i % 3 == 0 && cache[i] > cache[i / 3] + 1)
		{
			cache[i] = cache[i / 3] + 1;
		}

	}
	return cache[n];
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	cout << func(n) << "\n";

	return 0;
}