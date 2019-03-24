#include<iostream>
#include<vector>
using namespace std;
int T, N, K;
int toWin;
vector<int> cost;
vector<vector<int>> build;
vector<int> index;
vector<int> cache;
int minTime(int building)
{
	for (int i = 0; i < K; i++)
	{
		index[build[i][1]] = 0;
	}
	for (int i = 1; i <= K; i++)
	{
		index[i] == 1;
		cache[i] = cost[i];
	}
	for (int i = 0; i < K; i++)
	{
		if(cache[build[i][1]]<cache[build[i][0]] + cost[build[i][1]])
		cache[build[i][1]] = cache[build[i][0]] + cost[build[i][1]];
	}
	return cache[building];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		cost.assign(N + 1, 0);
		index.assign(N + 1, 1);
		build.assign(K, vector<int>(2, 0));
		cache.assign(N + 1,-1);
		for (int n = 1; n <= N; n++)
		{
			cin >> cost[n];
		}
		
		for (int k = 0; k < K; k++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			build[k][0] = tmp1;
			build[k][1] = tmp2;
		}
		cin >> toWin;


		//cout << minTime(toWin) << "\n";
	}


}