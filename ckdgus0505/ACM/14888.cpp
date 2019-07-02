#include <iostream>
#include<vector>
using namespace std;

int N; // �ԷµǴ� ���� ����
int Min = 987654321;
int Max = -987654321; // �ִ񰪰� �ּڰ��� �����ϴ� ����
vector<int> As; // �Ϸ��� ���� ��Ÿ��
vector<int> Os; // ������
void calculate(int nums, int iter, int a, int b, int c, int d); // nums�� �߰� ���, iter�� ������ ��� �ؾ� �ϴ���, a~d�� ���� ������ ��
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