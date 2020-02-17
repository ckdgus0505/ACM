#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str.at(i) < 'D')
			str.at(i) += 23;
		else
			str.at(i) -= 3;
	}
	cout << str << '\n';
}