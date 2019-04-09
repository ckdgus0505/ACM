#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TreeNode {	//Tree �� �� Node �� ���� ��ü
public : 
	T data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T data = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : data(data), left(left), right(right) {}
};

template<typename T>
class Tree {	//��ü���� Tree ����
public :
	static TreeNode<T>* root;
	int cnt;

	Tree(T data) {	//�⺻�� �����ʰ� �׳� ������ �޴°ɷ�
		root = new TreeNode<T>(data);
		cnt = 0;
	}

	void insert(int num, TreeNode<T>* node = root) {
		++cnt;
		if (num < node->data) {
			if (node->left != nullptr) {	//������ ���� ������ �ְ� ������ ��ͷ� Ÿ�� ������
				insert(num, node->left);
			}
			else {
				node->left = new TreeNode<T>(num);
				cout << cnt << '\n';
			}
		}
		else {
			if (node->right != nullptr) {
				insert(num, node->right);
			}
			else {
				node->right = new TreeNode<T>(num);
				cout << cnt << '\n';
			}
		}
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, first, num;

	cin >> N;
	cin >> first;
	Tree<int> t(first);
	for (int i = 0; i < N - 1; ++i) {
		cin >> num;
		t.insert(num);
	}
	
	

	return 0;
}
