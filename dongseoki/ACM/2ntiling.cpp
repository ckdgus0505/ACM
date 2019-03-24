#include <iostream>
#include <cstring>
#include <vector>
#include <utility> // for pair.
#include <algorithm>
using namespace std;
int n;
int n2_tiling(int n);
int cache[1001];


int main(void) {
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	cin >> n;
	memset(cache, -1, sizeof(cache));

	cout << n2_tiling(n);
	
	p.second.first = 3;
	return 0;
}

int n2_tiling(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int & ref = cache[n];
	if (ref != -1)
		return ref;

	ref = 2 * n2_tiling(n - 2) + n2_tiling(n-1) -1;

	return ref;
}