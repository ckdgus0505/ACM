#include <iostream>
#include <vector>
using namespace std;
int G, P;
vector<int> port;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> G >> P;
	port.assign(G+1, 0);
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		int a = 0;
		cin >> a;
		for (int j = a; j > 0; j--) {
			if (port[j] == 0) {
				port[j] = 1;
				cnt++;
				break;
			}
			if (j == 1 && port[j] == 1) {
				cout << cnt << '\n';
				return 0;
			}
		}
	}
}