#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char a;
	while (true) {
		scanf("%c", &a);
		if (a == '\n') break;
		if (a >= 'A'+3 && a <= 'Z')
			printf("%c", a - 3);
		else if (a >='A' && a < 'A'+3)
			printf("%c", a - 'A' + 'Z' - 2);
	}
	return 0;
}