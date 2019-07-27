#include <iostream>
#include <cstdio>
using namespace std;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int q, r;
	q = (N-1) / 14;
	r = (N-1) % 14;

	switch (r)
	{
		case 0:
		case 12:
			cout << "baby" << '\n';
			break;
		case 1:
		case 13:
			cout << "sukhwan" << '\n';
			break;
		case 4:
			cout << "very" << '\n';
			break;
		case 5:
			cout << "cute" << '\n';
			break;
		case 8:
			cout << "in" << '\n';
			break;
		case 9:
			cout << "bed" << '\n';
			break;
		case 2:
		case 6:
		case 10:
			if (q >= 3)
				cout << "tu+ru*" << q + 2 << "\n";
			else
			{
				cout << "tu";
				for (int i = 0 ; i < q+2; i++)
					cout << "ru";
				cout << '\n';
			}	
				break;

	default:
		if (q >= 4)
			cout << "tu+ru*" << q + 1 << "\n";
		else
		{
			cout << "tu";
			for (int i = 0; i < q+1; i++)
				cout << "ru";
			cout << '\n';
		}
			break;
	}
	return 0;
}