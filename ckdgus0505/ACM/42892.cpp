#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<pair<int, int>, int> node; // first.first == x�� ��ǥ // first.second == y�� ��ǥ // second == index
typedef struct treenode {
	pair<int, int> value; // first = x�� ��ǥ, second = index
	treenode* lptr = nullptr;
	treenode* rptr = nullptr;
}treenode; // Ʈ���� ���� ���

struct comp {
	bool operator()(const node& x, const node& y) {
		if (x.first.second > y.first.second) return true;
		else if (x.first.second < y.first.second) return false;
		else { // x.first.first == y.first.first
			if (x.first.first < y.first.first) return true;
			else return false;
		}
	}
};

priority_queue<node, vector<node>, comp> pq; // y��ǥ ū ��, x��ǥ ���������� ����

void make_btree(treenode* root, node* add) {
	if (root->value.first > add->first.first) {
		if (root->lptr == nullptr) {
			root->lptr = new treenode;
			root->lptr->value.first = add->first.first;
			root->lptr->value.second = add->second;
		}
		else {
			make_btree(root->lptr, add);
		}
	}
	else {
		if (root->rptr == nullptr) {
			root->rptr = new treenode;
			root->rptr->value.first = add->first.first;
			root->rptr->value.second = add->second;
		}
		else {
			make_btree(root->lptr, add);
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	for (int i = 0; i < nodeinfo.size(); i++) {
		pq.push(make_pair(make_pair(nodeinfo[i][0], nodeinfo[i][1]), i));
	}

	treenode* root = new treenode;
	node tmp = pq.top();
	pq.pop();
	root->value.first = tmp.first.first;
	root->value.second = tmp.second;

	while (!pq.empty()) {
		tmp = pq.top();
		make_btree(root, &tmp);
		pq.pop();
	}

	vector<vector<int>> answer;
	return answer;
}

int main(void) {
	solution(vector<vector<int>>{ {5, 3}, { 11,5 }, { 13,3 }, { 3,5 }, { 6,1 }, { 1,3 }, { 8,6 }, { 7,2 }, { 2,2 }});
}