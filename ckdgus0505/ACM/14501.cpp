#include <iostream>
#include<vector>
using namespace std;

int N; // ��� ���� ��¥ N
int Max; // �ִ� ������ �����ϴ� ����
vector<vector<int>> TP; // T�� P�� ����Ǵ� ����
void counsel(int income, int iter); //(ȣ���) income�� ���ݱ��� ���� ����, iter�� ���� ��� ������ ��¥
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