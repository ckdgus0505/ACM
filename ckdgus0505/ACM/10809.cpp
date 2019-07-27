#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char* str;
	int alphabet[26];
	str = (char*)malloc(sizeof(char) * 101);
	memset(alphabet, -1, sizeof(alphabet));

	cin >> str;

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '\0') break;
		else if (alphabet[str[i] - 'a'] == -1)
		{
			alphabet[str[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alphabet[i]);
	}
	return 0;
}
