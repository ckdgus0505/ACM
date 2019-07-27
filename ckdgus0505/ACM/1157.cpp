#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef map<char, int> alphcnt;

bool compare_pair_second (pair<char, int> &left, pair<char, int> &right)
{
	return (left.second > right.second);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	alphcnt amap;
	for (int i = 0; i < 26; i++)
	{
		amap.insert(pair<char, int>('A'+i, 0));
	}

	char* str;
	str = (char*)malloc(sizeof(char) * 1000001);
	cin >> str;

	int i = 0;
	while (true)
	{
		if (str[i] == '\0') break;

		char idx;
		if (str[i] >= 'A' && str[i] <= 'Z')
			idx = str[i];
		else if (str[i] >= 'a' && str[i] <= 'z')
			idx = str[i] + 'A' - 'a';

		amap[idx] += 1;
		i++;
	}
	vector<pair<char, int>> vec(amap.begin(), amap.end());

	sort(vec.begin(), vec.end(), compare_pair_second);

	if (vec[0].second == vec[1].second)
		cout << '?' << '\n';
	else cout << vec[0].first << '\n';
}