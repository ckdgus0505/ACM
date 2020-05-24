#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;
stack<int> val;
string str;
int flag;
int idx2;
int idx3;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;

	for (int idx = 0; idx < str.length(); idx++) {
		if (str[idx] == '(') {
			st.push('(');
			idx2++;
		}
		else if (str[idx] == '[') {
			st.push('[');
			idx3++;
		}
		else if (str[idx] == ')') {
			idx2--;
			if (idx2 > 0) {
				int tmp;
				if (st.top() == 'V') tmp = 0;
				else tmp = 1;

				while (st.top() == 'V') {
					tmp += val.top();
					st.pop();
					val.pop();
				}
				if (st.top() != '(') flag = -1;
				tmp *= 2;
				st.pop();
				val.push(tmp);
				st.push('V');
			}
			if (idx2 == 0) {
				val.push(2);
				st.push('V');
			}
			else flag = -1;
		}
		else if (str[idx] == ']') {
			idx3--;
			if (idx3 > 0) {
				int tmp;
				if (st.top() == 'V') tmp = 0;
				else tmp = 1;
				while (st.top() == 'V') {
					tmp += val.top();
					st.pop();
					val.pop();
				}
				if (st.top() != '[') flag = -1;
				tmp *= 3;
				st.pop();
				val.push(tmp);
				st.push('V');
			}
		}
		if (idx3 == 0) {
			val.push(3);
			st.push('V');
		}
		else flag = -1;

	}

	int ans = 0;

	if (val.size() == st.size()) {
		while (!val.empty()) {
			if (st.top() != 'V') flag = -1;
			ans += val.top();
			val.pop();
		}
	}

	if (flag == -1) {
		ans = 0;
	}

	cout << ans << "\n";

}