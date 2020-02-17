#include <iostream>
#include <string>
using namespace std;

bool UCPC[4];

void inline func(char c) {
	if (!UCPC[0]) {
		if (c == 'U')	UCPC[0] = true;
	}
	else if (!UCPC[1]) {
		if (c == 'C')	UCPC[1] = true;
	}
	else if (!UCPC[2]) {
		if (c == 'P')	UCPC[2] = true;
	}
	else if (!UCPC[3]) {
		if (c == 'C')	UCPC[3] = true;
	}
}

int main(void) {
	string str;
	std::getline(cin, str);
	for (int i = 0; i < str.size(); ++i) {
		func(str.at(i));
	}
	if (UCPC[3]) {
		cout << "I love UCPC" << '\n';
	}
	else {
		cout << "I hate UCPC" << '\n';
	}
}