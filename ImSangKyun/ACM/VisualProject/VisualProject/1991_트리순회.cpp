#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	//vector<TreeNode*> child;
public:
	//TreeNode(T data = 0, vector<TreeNode*> child = NULL) : data(data), child(child){}
	TreeNode(T data = 0, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL) : data(data), left(left), right(right) {}
};

template <typename T>
class Tree {
private:
	TreeNode<T>* root;
	vector<T> parent;
public:
	Tree(T data = 0) {
		root = new TreeNode<T>(data);
	}

	void buildTree() {	//미완
		root->left = new TreeNode<T>();
		root->right = new TreeNode<T>();
	}

	void insert(char a, char b, char c) {	//1991용 임시 함수
		TreeNode<T>* node = bsearch(a, getRoot());
		if (b)	node->left = new TreeNode<T>(b);
		if (c)	node->right = new TreeNode<T>(c);
	}

	TreeNode<T>* getRoot() {
		return root;
	}

	TreeNode<T>* bsearch(T data, TreeNode<T>* node) {
		TreeNode<T>* tmp = NULL;
		if (node->data == data)	return node;
		if (node->left) {
			tmp = bsearch(data, node->left);
			if (tmp)	return tmp;
		}
		if (node->right) {
			tmp = bsearch(data, node->right);
			if (tmp)		return tmp;
		}
		return NULL;
	}

	void visit(TreeNode<T>* current) {
		cout << current->data;
	}

	// 전위 순회 Current - Left - Right
	void preorder(TreeNode<T>* current) {
		if (current != NULL) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}

	// 중위 순회 Left - Current - Right
	void inorder(TreeNode<T>* current) {
		if (current != NULL) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}

	// 후위 순회 Left - Right - Current
	void postorder(TreeNode<T>* current) {
		if (current != NULL) {
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	char a, b, c;
	Tree<char> t('A');

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b >> c;
		if (b == '.') 
			b = NULL;
		if (c == '.')
			c = NULL;
		t.insert(a, b, c);
	}

	t.preorder(t.getRoot());	cout << '\n';
	t.inorder(t.getRoot());		cout << '\n';
	t.postorder(t.getRoot());	cout << '\n';

	return 0;
}