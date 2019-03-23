#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> cache;

int bishopVishionScore(int a, int b) // (a,b)는 비숍의 현재 위치, 현재 위치에서의 비숍의 점수를 반환하는 함수
{
		




}









int main(void)
{
	int N, K;

	cin >> N >> K;

	arr.assign(N,vector<int>(N,0));
	for (int i = 0; i < 2*N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			cin >> arr[i][j];
		}
	}
}