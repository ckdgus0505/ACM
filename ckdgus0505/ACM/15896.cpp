#include <iostream>
#include <vector>
using namespace std;

vector<int> arrA;
vector<int> arrB;
int N;
void init();
int bit_first();
int sum_first();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

}
void init()
{
	cin >> N;
	arrA.assign(N, 0);
	arrB.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arrB[i];
	}
}
int bit_first()
{
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += arrA[i] & arrB[i];
	}
}
int sum_first()
{

}