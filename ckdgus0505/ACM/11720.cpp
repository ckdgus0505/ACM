#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int   N, sum;
	char* nums;
	cin >> N;
	nums = (char*)malloc(sizeof(char) * N + 1);

	cin >> nums;
	sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (nums[i]-'0');
	}
	cout << sum;
	return 0;
}