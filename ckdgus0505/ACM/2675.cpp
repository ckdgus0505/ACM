#include <iostream>
using namespace std;

int T;

void repeat(int r, char*& str);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int r;
		char* tmp;
		tmp = (char*)malloc(sizeof(char) * 21);
		cin >> r;
		cin >> tmp;
		repeat(r, tmp);
	}
}
void repeat(int r, char*& str)
{
	int idx = 0;
	while (true)
	{
		if (str[idx] == '\0') break;

		for (int i = 0; i < r; i++)
		{
			cout << str[idx];
		}
	idx++;
	}
	cout << "\n";
}