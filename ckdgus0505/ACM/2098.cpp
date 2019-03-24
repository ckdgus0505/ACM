#include<iostream>
#include<cstdio>
#define max = 987654321;
#define CITY = 16;

using namespace std;
int N;
int W[16][16];
int trial[];
int cache[65535][16]; // [2^17-1][16] 0000000000000000 ~ 1111111111111111
int TSP(int visited, int now)
{
	//if (cache[visited][now] != -1) return cache[visited][now];
	int& ret = cache[visited][now];
	if (ret != -1) return ret;
	
	





	return ret;
}

int main(void)
{
	fill_n(&cache[0][0], 65535*16 , -1);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	printf("%d", TSP(0, 0));
	return 0;
}