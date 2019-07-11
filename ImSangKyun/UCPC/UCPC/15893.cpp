#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int pallindrom(string s) {
	string r = s;
	std::reverse(r.begin(), r.end());
	if (s == r)	return s.size();
	else   return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int res = 0;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		res = max(res, pallindrom(s));
	}
	cout << res << '\n';
}