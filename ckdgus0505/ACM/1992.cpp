#include<iostream>
#include<cstdio>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int N;
vector<vector<int>> arr;

int quadTree(int x, int y, int size) // x,y 는 시작 위치
{
	vector<vector<int>> arr0(size, vector<int>(size, 0));
	vector<vector<int>> arr1(size, vector<int>(size, 1));
	vector<vector<int>> subarr(size, vector<int>(size, 0));
	/*for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			subarr[i - x][j - y] = arr[i][j];
		}
	}*/
	subarr = arr;
	if (subarr == arr0)
	{
		cout << '0';
		return 0;
	}
	else if (subarr == arr1)
	{
		cout << '1';
		return 0;
	}
	arr0.clear(); // 메모리 해제
	arr1.clear();
	subarr.clear();
	cout << '(';
	quadTree(x, y, size / 2);
	quadTree(x, y + size / 2, size / 2);
	quadTree(x + size / 2, y, size / 2);
	quadTree(x + size / 2, y + size / 2, size / 2);
	cout << ')';
}


int main(void)
{
	cin >> N;

	arr.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	quadTree(0, 0, N);
	return 0;
}