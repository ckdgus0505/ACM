#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> st;
string str;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;

	int index = 0;


	// (은 -10 ( 은 -11 로 정의함
	// [은 -20 ] 은 -21 로 정의함
	for (index = 0; index < str.length(); index++) {

		if (str[index] == '(') st.push(-10);
		else if (str[index] == '[') st.push(-20);
		else {



			if (str[index] == ')') {
				if (st.top() > 1) {
					int tmp = 2;
					tmp *= st.top();
					st.pop();
					st.pop();

					if (st.top() > 1) {
						tmp += st.top();
						st.pop();
					}
					st.push(tmp);
				}

				if (st.top() == -10) {
					int tmp = 2;
					st.pop();
					if (st.top() > 1) {
						tmp += st.top();
						st.pop();
					}
					st.push(tmp);
				}
			}

			else if (str[index] == ']') {
				if (st.top() > 1) {
					int tmp = 3;
					tmp *= st.top();
					st.pop();
					st.pop();

					if (st.top() > 1) {
						tmp += st.top();
						st.pop();
					}
					st.push(tmp);
				}

				if (st.top() == -20) {
					int tmp = 3;
					st.pop();
					if (st.top() > 1) {
						tmp += st.top();
						st.pop();
					}
					st.push(tmp);
				}
			}

		}
	}

	cout << st.top() << endl;
}