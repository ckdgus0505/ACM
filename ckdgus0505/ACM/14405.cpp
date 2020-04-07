#include <iostream>
#include <string>
using namespace std;

string inputstr;
int pi(int i);
int ka(int i);
int chu(int i);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> inputstr;

	int i = 0;
	while (i < inputstr.length()) {
		switch(inputstr[i]) {
		case 'p':
			i = pi(i);
			break;
		case 'k':
			i = ka(i);
			break;
		case 'c':
			i = chu(i);
			break;
		default:
			i = -1;
			break;
		}
		if (i == -1) {
			break;
		}
	}
	if (i == -1) {
		cout << "NO" << '\n';
	}
	else cout << "YES" << '\n';
}


int pi(int i) {
	if (inputstr[i + 1] == 'i')
		return i + 2;
	else return -1;
}
int ka(int i) {
	if (inputstr[i + 1] == 'a')
		return i + 2;
	else return -1;
}
int chu(int i) {
	if (inputstr[i + 1] == 'h') {
		if (inputstr[i + 2] == 'u')
			return i + 3;
	}
	return -1;
}