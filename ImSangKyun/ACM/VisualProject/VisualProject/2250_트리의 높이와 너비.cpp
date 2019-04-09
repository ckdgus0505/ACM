#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, nodeIdx;
int node[10001], low[10001], high[10001];
pair<int, int> Tree[10001];

int main(void) {


}

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// global
typedef struct NODE {
	int val;
	int left;
	int right;
	int height;
	int col;
}NODE;
vector<NODE> node_vec;
vector<int> node_parent_vec;
int col_idx = 1;

// ������ȸ�� ���Ͽ� col ���� ����
void inorder(int _this_node_idx) {
	NODE* this_node = &node_vec.at(_this_node_idx);
	if (this_node->left != -1) inorder(this_node->left);
	this_node->col = col_idx++;
	if (this_node->right != -1) inorder(this_node->right);
}

// bfs �� ���Ͽ� ���̸� ����
void bfs(int _start_node) {
	queue<int> bfs_queue;
	bfs_queue.push(_start_node);
	int bfs_size = bfs_queue.size();
	int height = 1;
	while (bfs_size) {
		int this_node_idx = bfs_queue.front();
		bfs_queue.pop();
		bfs_size--;

		NODE* this_node = &node_vec.at(this_node_idx);
		this_node->height = height;
		if (this_node->left != -1) bfs_queue.push(this_node->left);
		if (this_node->right != -1) bfs_queue.push(this_node->right);

		if (bfs_size == 0) {
			height++;
			bfs_size = bfs_queue.size();
		}
	}
}

// node�� ���̿� ���缭 �����ϰ�, ���̰� ������ col ���� ���� �����Ѵ�.
int sort_node(const NODE& _node_1, const NODE& _node_2) {
	if (_node_1.height != _node_2.height)
		return _node_1.height < _node_2.height;
	else
		return _node_1.col < _node_2.col;
}

int find_root() {
	int root = 1;
	// �θ� ���� �� ���� ����
	while (node_parent_vec.at(root) != -1)
		root = node_parent_vec.at(root);

	return root;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	node_vec.resize(N+1);
	node_parent_vec.resize(N+1, -1);
	for (int n_idx = 1; n_idx <= N; n_idx++){
		int this_node, left, right;
		cin >> this_node >> left >> right;
		node_vec.at(this_node).left = left;
		node_vec.at(this_node).right = right;
		node_vec.at(this_node).height = node_vec.at(this_node).col = -1;

		// �θ� ��� ��� ǥ��
		if (left != -1)  node_parent_vec.at(left) = this_node;
		if (right != -1)  node_parent_vec.at(right) = this_node;
	}

	// ��Ʈ ã��
	int root = find_root();

	// ������ȸ�� ������ col ��ġ�� �����Ѵ�.
	inorder(root);

	// bfs �� ������ ���̸� �����Ѵ�.
	bfs(root);

	// ������ ���̿� �ش��ϴ� ���ҵ��� col ��ġ�� ���Ͽ� �ִ� ���̸� ���Ѵ�.
	sort(node_vec.begin()+1, node_vec.end(), sort_node);

	// �÷� ������ �ִ� ���� ���Ѵ�
	int answer_width = 1;
	int answer_height = 1;
	int height = 1;
	int row_first = -1;
	for (int n_idx = 2; n_idx <= N; n_idx++) {
		if (height < node_vec.at(n_idx).height) {
			height++;
			row_first = n_idx;
		}
		else if (height == node_vec.at(n_idx).height) {
			if (answer_width < node_vec.at(n_idx).col - node_vec.at(row_first).col + 1){
				answer_width = node_vec.at(n_idx).col - node_vec.at(row_first).col + 1;
				answer_height = height;
			}
		}
	}
	cout << answer_height << " " << answer_width;

	return 0;
}

*/