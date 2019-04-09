/*
문제 해결 과정:
	- 전위 순회한 결과로 이진트리 생성. tree라는 구조체를 만들어 오른쪽 왼쪽 노드의 키를 저장하는 배열을 만든다.
	- 루트를 먼저 넣고 숫자가 작으면 왼쪽 크면 오른쪽에 넣는다
	- 그 이후에 후위 순회로 출력한다.
	- 이진트리를 안만들고 바로 하는 방법은 없을까?
*/
#include<iostream>
#include<cstdio>
using namespace std;

struct Tree {
	int left = 0;
	int right = 0;
};

Tree tree[100001];

void postOrder(int node) {
	if (tree[node].left != 0) {
		postOrder(tree[node].left);
	}
	if (tree[node].right != 0) {
		postOrder(tree[node].right);
	}
	printf("%d\n", node);


}

int main() {
	int root;
	int value;
	scanf_s("%d", &root);
	while (scanf_s("%d", &value) != EOF) {
		int node = root;
		while (true) {
			if (node < value) {
				if (tree[node].right != 0) {
					node = tree[node].right;
				}
				else {
					tree[node].right = value;
					break;
				}
			}
			else {
				if (tree[node].left != 0) {
					node = tree[node].left;
				}
				else {
					tree[node].left = value;
					break;
				}
			}
		}
	}
	postOrder(root);
	return 0;
}
