#include <iostream>
#include<vector>
using namespace std;

int N; // 상담 남을 날짜 N
int Max; // 최대 수익을 저장하는 변수
vector<vector<int>> TP; // T와 P가 저장되는 벡터
void counsel(int income, int iter); //(호출시) income은 지금까지 얻은 수익, iter은 다음 상담 가능한 날짜
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie (NULL);
	cin >> N;
	TP.assign(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> TP[i][0] >> TP[i][1];
	}
	counsel(0, 0);
	cout << Max;
}

void counsel(int income, int iter)
{
	for (int i = iter ; i < N; i++)
	{
		if(i + TP[i][0] <= N)
			counsel(income + TP[i][1], i + TP[i][0]);
	}
	if (iter >= N || iter + TP[iter][0] > N)
	{
		if (income > Max)
			Max = income;
		return;
	}
}