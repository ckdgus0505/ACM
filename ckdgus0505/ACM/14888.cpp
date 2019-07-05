#include <iostream>
#include<vector>
using namespace std;

int N; // 입력되는 수의 갯수
int Min = 987654321;
int Max = -987654321; // 최댓값과 최솟값을 저장하는 변수
vector<int> As; // 일련의 수를 나타냄
vector<int> Os; // 연산자
void calculate(int nums, int iter, int a, int b, int c, int d); // nums는 중간 결과, iter은 어디부터 계산 해야 하는지, a~d는 남은 연산자 수
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	As.assign(N, 0);
	Os.assign(4, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> As[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> Os[i];
	}
	calculate(As[0], 0, Os[0], Os[1], Os[2], Os[3]);
	cout << Max << '\n' << Min << '\n';
}
void calculate(int nums, int iter, int a, int b, int c, int d)
{
	if (a > 0)
		calculate(nums + As[iter+1], iter + 1, a - 1, b, c, d);
	if (b > 0)
		calculate(nums - As[iter+1], iter + 1, a, b - 1, c, d);
	if (c > 0)
		calculate(nums * As[iter+1], iter + 1, a, b, c - 1, d);
	if (d > 0)
		calculate(nums / As[iter+1], iter + 1, a, b, c, d - 1);
	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		if (nums > Max)
			Max = nums;
		if (nums < Min)
			Min = nums;
	}
}