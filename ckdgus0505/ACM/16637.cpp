#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dynamic(string str);
int bfs(string str);
string substring(string str, int n);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	string str;
	cin >> N;
	cin >> str;
	cout << bfs("+"+str) << endl;
}

int bfs(string str) {
	int max = -987654321;
	queue<pair<int, string>> q; // int 에는 지금까지의 계산 결과가 저장되어 있음, string에는 앞으로 계산 할 식이 적혀있음;;
	q.push(make_pair(0,str));
	while (!q.empty()) {
		pair<int, string> tmp = q.front();
		q.pop();

		if (tmp.second.length() == 0) {
			if (tmp.first > max) max = tmp.first;
		}

		else if (tmp.second.length() == 2) {
			int a;
			switch (tmp.second[0]) {
			case '+':
				a = tmp.first + tmp.second[1] - '0';
				if (max < a) max = a;
				break;
			case '-':
				a = tmp.first - (tmp.second[1] - '0');
				if (max < a) max = a;
				break;
			case '*':
				a = tmp.first * (tmp.second[1] - '0');
				if (max < a) max = a;
				break;
			}
		}

		else {
			switch (tmp.second[0]) {
			case '+':
				q.push(make_pair(tmp.first + tmp.second[1] - '0', substring(tmp.second, 2))); // str.substr(1)));
				switch (tmp.second[2]) {
				case '+':
					q.push(make_pair(tmp.first + (tmp.second[1] - '0' + tmp.second[3] - '0'), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '-':
					q.push(make_pair(tmp.first + ((tmp.second[1] - '0') - (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '*':
					q.push(make_pair(tmp.first + ((tmp.second[1] - '0') * (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				}
				break;
			case '-':
				q.push(make_pair(tmp.first - (tmp.second[1] - '0'), substring(tmp.second, 2))); //str.substr(1)));
				switch (tmp.second[2]) {
				case '+':
					q.push(make_pair(tmp.first - (tmp.second[1] - '0' + tmp.second[3] - '0'), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '-':
					q.push(make_pair(tmp.first - ((tmp.second[1] - '0') - (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '*':
					q.push(make_pair(tmp.first - ((tmp.second[1] - '0') * (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				}
				break;
			case '*':
				q.push(make_pair(tmp.first * (tmp.second[1] - '0'), substring(tmp.second, 2))); //str.substr(1)));
				switch (tmp.second[2]) {
				case '+':
					q.push(make_pair(tmp.first * ((tmp.second[1] - '0') + (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '-':
					q.push(make_pair(tmp.first * ((tmp.second[1] - '0') - (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				case '*':
					q.push(make_pair(tmp.first * ((tmp.second[1] - '0') * (tmp.second[3] - '0')), substring(tmp.second, 4))); //str.substr(3)));
					break;
				}
				break;
			}
		}
	}

	return max;
}

string substring(string str, int n) {
	try {
		return str.substr(n);
	}
	catch (const std::out_of_range& e) {
		return "";
	}
}
/*
int dynamic(string str) {
	if (str.length() == 2) return str[1] - '0';

	int max = -1;
	int num1, num2;
	char op1, op2;
	int tmp = 0;

	if (str.length() == 4) {
		num1 = str[1] - '0';
		num2 = str[3] - '0';
		op1 = str[2];
		switch (op1) {
		case '+':
			return num1 + num2;
			break;
		case '-':
			return num1 - num2;
			break;
		case '*':
			return num1 * num2;
			break;
		}
	}
	num1 = str[0] - '0';
	num2 = str[2] - '0';
	op1 = str[1];
	op2 = str[3];

	max = -1;

	switch (op1) {
	case '+':
		max = num1 + dynamic(str.substr(2));
		switch (op2) {
		case '+':
			tmp = num1 + num2 + dynamic(str.substr(4));
			break;
		case '-':
			tmp = num1 + num2 - dynamic(str.substr(4));
			break;
		case '*':
			tmp = (num1 + num2) * dynamic(str.substr(4));
			break;
		}
		if (max < tmp) max = tmp;
		return max;
		break;
	case '-':
		max = num1 - dynamic(str.substr(2));
		switch (op2) {
		case '+':
			tmp = num1 - num2 + dynamic(str.substr(4));
			break;
		case '-':
			tmp = num1 - num2 - dynamic(str.substr(4));
			break;
		case '*':
			tmp = (num1 - num2) * dynamic(str.substr(4));
			break;
		}
		if (max < tmp) max = tmp;
		return max;
		break;
	case '*':
		max = num1 * dynamic(str.substr(2));
		switch (op2) {
		case '+':
			tmp = (num1 * num2) + dynamic(str.substr(4));
			break;
		case '-':
			tmp = (num1 * num2) - dynamic(str.substr(4));
			break;
		case '*':
			tmp = (num1 * num2) * dynamic(str.substr(4));
			break;
		}
		if (max < tmp) max = tmp;
		return max;
		break;
	}
	
} */