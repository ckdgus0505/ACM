#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> scores;
vector<int> cache;

int stairFunction(int stair, int isOne)
{
	if (stair < 1) return 0;
	if (stair == 1) return scores[1];

	int& ret = cache[stair];
	if (ret != -1) return ret;

	if (isOne == 1)
	{
		return stairFunction(stair - 2, 0) + scores[stair];
	}
	else
	{
		int tmp1 = stairFunction(stair - 1, 1) + scores[stair];
		int tmp2 = stairFunction(stair - 2, 0) + scores[stair];
		if (tmp1 > tmp2)
		{
			return tmp1;
		}
		else ret = tmp2;
	}

	return ret;
}





int main(void)
{
	int stairs;
	cin >> stairs;
	scores.assign(stairs + 1, 0);
	cache.assign(stairs + 1, -1);
	for (int i = 1; i <= stairs; i++)
	{
		cin >> scores[i];
	}
	//cache[0] = 0;
	//cache[1] = scores[1];

	printf("%d", stairFunction(stairs, 0));

	for (int i = 0; i < stairs + 1; i++)
	{
		cout << cache[i] << endl;
	}
}