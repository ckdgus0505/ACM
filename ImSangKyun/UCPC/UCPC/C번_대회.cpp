#include <iostream>
#include <vector>
using namespace std;

struct COMP {
	int start, end;
	int div;
	COMP(int s, int e) : start(s), end(e), div(e - s) {}
};

int N, K;
vector<COMP> arr;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	arr = vector<COMP>(N);

	for (int i = 0; i < N; ++i) {

	}
}