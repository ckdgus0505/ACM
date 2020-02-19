#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int w, n;
bool func(int idx, int cnt, int val) {
	if (cnt == 4) {
		if (val == w)	return true;
		else	return false;
	}
	bool ret = false;
	for (int i = idx + 1; i <= n; ++i) {
		ret = func(i, cnt + 1, val + arr[i]);
		if (ret)	break;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w >> n;
	arr = vector<int>(n+1, 0);
	for (int i = 1; i <= n; ++i)	//0번은 root로 의미없는 값 사용
		cin >> arr[i];
	if (func(0, 0, 0)) 
		cout << "YES" << '\n';
	else 
		cout << "NO" << '\n';
}