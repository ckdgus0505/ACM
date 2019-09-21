#include <iostream>
using namespace std;
int N;
char* str;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		str = (char*)malloc(sizeof(char) * 40);
		cin >> str;

		int j = 30;
		while (str[j] != '\0') {
			j--;
		}
		switch (str[j - 1]) {
		case ('a'):
		case ('o'):
		case ('u'):
			str[j] = 's';
			str[j + 1] = '\0';
			break;
		case ('i'):
		case ('y'):
			str[j - 1] = 'i';
			str[j] = 'o';
			str[j + 1] = 's';
			str[j + 2] = '\0';
			break;
		case ('l'):
		case ('r'):
		case ('v'):
			str[j] = 'e';
			str[j + 1] = 's';
			str[j + 2] = '\0';
			break;
		case ('n'):
			str[j - 1] = 'a';
			str[j] = 'n';
			str[j + 1] = 'e';
			str[j + 2] = 's';
			str[j + 3] = '\0';
			break;
		case ('t'):
		case ('w'):
			str[j] = 'a';
			str[j + 1] = 's';
			str[j + 2] = '\0';
			break;
		default:
			if (str[j - 2] == 'n' && str[j - 1] == 'e') {
				str[j - 2] = 'a';
				str[j - 1] = 'n';
				str[j] = 'e';
				str[j + 1] = 's';
				str[j + 2] = '\0';
				break;
			}
			else {
				str[j] = 'u';
				str[j + 1] = 's';
				str[j + 2] = '\0';
				break;
			}

		}
			cout << str << '\n';
			free(str);
	}
}