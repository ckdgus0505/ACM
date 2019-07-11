#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int num;
	int height;
	struct node * parent;
	vector<struct node> child;
};
typedef struct node Tree;

int N;
Tree T;
queue<pair<int, int>> remain;

bool insert(Tree& t, int a, int b) {
	if (t.num == a || t.num == b) {
		Tree tmp;
		if(t.num == a)	tmp.num = b;
		else  tmp.num = a;
		tmp.height = t.height + 1;
		t.child.push_back(tmp);
		return true;
	}
	bool isInsert = false;
	for (int i = 0; i < t.child.size(); ++i) {
		isInsert = insert(t.child[i], a, b);
		if (isInsert)
			break;
	}
	return isInsert;
}

int sumleaf(Tree& t) {
	if (t.child.size() == 0)
		return t.height;
	int val = 0;
	for (int i = 0; i < t.child.size(); ++i) {
		val += sumleaf(t.child[i]);
	}
	return val;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	T.num = 1;
	T.height = 0;
	
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		bool isInsert = false;
		isInsert = insert(T, a, b);
		if (!isInsert) {
			remain.push(make_pair(a, b));
		}
	}
	for (int i = 0; !remain.empty(); ++i) {
		if (i >= remain.size())	i = 0;
		bool isInsert = false;
		int a = remain.front().first;
		int b = remain.front().second;
		isInsert = insert(T, a, b);
		remain.pop();
		if (!isInsert) {
			remain.push(make_pair(a, b));
		}
	}

	int sum = 0;
	sum = sumleaf(T);
	while (sum > 1)
		sum %= 2;
	if (sum == 1)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}