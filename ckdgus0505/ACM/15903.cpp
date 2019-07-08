#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<unsigned long long> cards;
int n, m;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	cards.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	for (int i = 0; i < m; i++)
	{
		sort(cards.begin(), cards.end(), less<unsigned long long>());

		unsigned long long tmp;

		tmp = cards[0] + cards[1];
		cards[0] = tmp;
		cards[1] = tmp;
	}

	unsigned long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += cards[i];
	}
	cout << sum << '\n';

}