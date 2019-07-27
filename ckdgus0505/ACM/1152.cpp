#include <iostream>
#include <string>
using namespace std;
int delimeter(string& str);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);
	int cnt = 1;
	int i = delimeter(str);
	if (str[i] == '\0') {
		cout << 0 << '\n';
		return 0;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == '\0') break;
		else if (str[i] == ' ') cnt++;
	}
	cout << cnt << '\n';
}
int delimeter(string& str)
{
	int i;

	for (i = str.size()-1; i >= 0; i--)
	{
		if (str[i] == ' ') str[i] = '\0';
		else break;
	}
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ') break;
	}
	return i;
}